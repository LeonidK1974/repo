#include "search_server.h"
#include "iterator_range.h"
#include <algorithm>
#include <iterator>
#include <sstream>
#include <iostream>

vector<string> SplitIntoWords(const string &line) {
	istringstream words_input(line);
	return { istream_iterator<string>(words_input), istream_iterator<string>() };
}

SearchServer::SearchServer(istream &document_input) {
	UpdateDocumentBase(document_input);
}

void SearchServer::UpdateDocumentBase(istream &document_input) {
	InvertedIndex new_index;

	for (string current_document; getline(document_input, current_document); ) {
		new_index.Add(move(current_document));
	}

	inverted_index = move(new_index);
}


void SearchServer::AddQueriesStream(istream &query_input,
	ostream &search_results_output) {

	vector<pair<size_t, size_t>> docid_count(inverted_index.Size());

	for (string current_query; getline(query_input, current_query);) {
		const auto words = SplitIntoWords(current_query);
		fill(docid_count.begin(), docid_count.end(), make_pair(0, 0));

		for (const auto &word : words) {
			for (const auto&[docid, hitcount] : inverted_index.Lookup(word)) {
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

void InvertedIndex::Add(const string &document) {
	docs.push_back(move(document));

	const size_t docid = docs.size() - 1;
	map<string, size_t> m;

	for (const auto &word : SplitIntoWords(docs.back())) {
		++m[word];
	}
	for (const auto&[word, count] : m) {
		index[word].push_back({ docid, count });
	}
	size = docs.size();
}

vector<pair<size_t, size_t>> InvertedIndex::Lookup(const string &word) const {
	auto it = index.find(word);
	if (it != index.end()) {
		return it->second;
	}
	return vector<pair<size_t, size_t>>{ {0, 0}};
}