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
	//Синхронизация
	//Если бы индекс не изменялся в течение жизни объекта SearchServer, то выполнять сихронизацию доступа к нему из метода AddQueriesStream было бы не нужно.
	//Но параллельно с этим методом может вызываться ещё UpdateDocumentBase, который изменяет индекс.Поэтому поле index в классе SearchServer всё - таки надо защитить мьютексом.
	//Для этого удобно воспользоваться шаблоном Synchronized, который мы реализовали в одной из задач модуля «Многопоточность».
	Synchronized<InvertedIndex> inverted_index;
	vector<future<void>> futures;
};