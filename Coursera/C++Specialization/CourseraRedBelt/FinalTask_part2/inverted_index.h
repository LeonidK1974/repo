#pragma once
#include "parse.h"
#include <map>
#include <string>
#include <vector>

using namespace std;

class InvertedIndex {
public:
	InvertedIndex() = default;
	explicit InvertedIndex(istream& document_input);

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

