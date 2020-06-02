#pragma once
#include "inverted_index.h"
#include "synchronized.h"
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

vector<string> SplitIntoWords(const string &line);

class SearchServer {
public:
	SearchServer() = default;

	explicit SearchServer(istream& document_input)
		: inverted_index(InvertedIndex(document_input))
	{
	}

	void UpdateDocumentBase(istream &document_input);
	void AddQueriesStream(istream &query_input, ostream &search_results_output);


private:
	//�������������
	//���� �� ������ �� ��������� � ������� ����� ������� SearchServer, �� ��������� ������������ ������� � ���� �� ������ AddQueriesStream ���� �� �� �����.
	//�� ����������� � ���� ������� ����� ���������� ��� UpdateDocumentBase, ������� �������� ������.������� ���� index � ������ SearchServer �� - ���� ���� �������� ���������.
	//��� ����� ������ ��������������� �������� Synchronized, ������� �� ����������� � ����� �� ����� ������ �����������������.
	Synchronized<InvertedIndex> inverted_index;
	vector<future<void>> futures;
};