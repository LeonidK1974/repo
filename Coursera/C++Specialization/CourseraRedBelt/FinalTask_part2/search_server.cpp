#include "search_server.h"
#include "inverted_index.h"
#include "iterator_range.h"
#include <algorithm>
#include <iterator>
#include <sstream>
#include <iostream>

vector<string> SplitIntoWords(const string &line) {
	istringstream words_input(line);
	return { istream_iterator<string>(words_input), istream_iterator<string>() };
}

//SearchServer::SearchServer(istream &document_input) {
//	UpdateDocumentBase(document_input);
//}

//	Построение индекса в методе UpdateDocumentBase занимает какое - то значительное время.
//	Если выполнять его под мьютексом, то параллельная обработка поисковых запросов будет заблокирована.
//	Поэтому лучше сначала в отдельном потоке построить новый объект класса InvertedIndex, 
//	а потом под мьютеком лишь переместить его в поле index класса SearchServer .
void UpdateDocumentBaseAsync(istream &document_input, Synchronized<InvertedIndex>& inverted_index)
{
	InvertedIndex new_inverted_index(document_input);
	swap(inverted_index.GetAccess().ref_to_value, new_inverted_index);
}

void AddQueriesStreamAsync(istream &query_input,	ostream &search_results_output, Synchronized<InvertedIndex>& inverted_index)
{

	const InvertedIndex &inv_index = inverted_index.GetAccess().ref_to_value;
	vector<pair<size_t, size_t>> docid_count(inv_index.Size());

	for (string current_query; getline(query_input, current_query);) {
		const auto words = SplitIntoWords(current_query);
		fill(docid_count.begin(), docid_count.end(), make_pair(0, 0));
		for (const auto &word : words) {
			for (const auto&[docid, hitcount] : inv_index.Lookup(word)) {
				docid_count[docid].first = docid;
				docid_count[docid].second += hitcount;
			}
		}

		size_t middle = min<size_t>(docid_count.size(), 5);

		partial_sort(begin(docid_count),
			begin(docid_count) + middle,
			end(docid_count),
			[](pair<size_t, size_t> lhs, pair<size_t, size_t> rhs) {
				int64_t lhs_docid = lhs.first;
				auto lhs_hit_count = lhs.second;
				int64_t rhs_docid = rhs.first;
				auto rhs_hit_count = rhs.second;
				return make_pair(lhs_hit_count, -lhs_docid) >
					make_pair(rhs_hit_count, -rhs_docid);
			}
		);

		search_results_output << current_query << ':';
		for (const auto &[docid, hitcount] : Head(docid_count, middle)) {
			if (hitcount != 0) {
				search_results_output << " {"
					<< "docid: " << docid << ", "
					<< "hitcount: " << hitcount << '}';
			}
		}
		search_results_output << endl; 
	}
}

void SearchServer::UpdateDocumentBase(istream &document_input) {
	futures.push_back(async(UpdateDocumentBaseAsync, ref(document_input), ref(inverted_index)));
}

//	Так как метод AddQueriesStream никак не изменяет содержимое индекса, 
//	то ускорения можно достигнуть за счёт параллельного выполнения нескольких вызовов этого метода.
void SearchServer::AddQueriesStream(istream &query_input,
	ostream& search_results_output) {
	futures.push_back(async(AddQueriesStreamAsync, ref(query_input), ref(search_results_output), ref(inverted_index)));
}

