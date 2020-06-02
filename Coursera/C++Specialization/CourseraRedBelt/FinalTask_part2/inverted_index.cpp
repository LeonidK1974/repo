#include "inverted_index.h"
#include "search_server.h"

InvertedIndex::InvertedIndex(istream& document_input) {
	for (string document; getline(document_input, document); ) {
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
}

//void InvertedIndex::Add(const string &document) {
//	docs.push_back(move(document));
//
//	const size_t docid = docs.size() - 1;
//	map<string, size_t> m;
//
//	for (const auto &word : SplitIntoWords(docs.back())) {
//		++m[word];
//	}
//	for (const auto&[word, count] : m) {
//		index[word].push_back({ docid, count });
//	}
//	size = docs.size();
//}

vector<pair<size_t, size_t>> InvertedIndex::Lookup(const string &word) const {
	if (auto it = index.find(word); it != index.end()) {
		return it->second;
	}
	return vector<pair<size_t, size_t>>{ {0, 0}};
}
