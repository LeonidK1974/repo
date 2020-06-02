#pragma once

#include <istream>
#include <ostream>
#include <set>
#include <list>
#include <vector>
#include <map>
#include <string>
#include <future>
#include <mutex>

using namespace std;

class InvertedIndex {
public:
	void Add(const string &document);

	vector<pair<size_t, size_t>> Lookup(const string &word) const;

	const string &GetDocument(size_t id) const {
		return docs[id];
	}
	size_t Size() const {
		return size;
	}

private:
	map<string, vector<pair<size_t, size_t>>> index;
	vector<string> docs;
	size_t size;
};


class SearchServer {
public:
	SearchServer() = default;

	explicit SearchServer(istream &document_input);

	void UpdateDocumentBase(istream &document_input);

	void AddQueriesStream(istream &query_input, ostream &search_results_output);

private:
	InvertedIndex inverted_index;
};