#include <algorithm>
#include <set>
#include <string>
#include <vector>
#include "database.h"
#include "date.h"

using namespace std;

void Database::Add(const Date& date, const string& event) {

	if(database_set_[date].insert(event).second)
	{
		database_vector_[date].push_back(event);
	}
	
};

void Database::Print(ostream& cout) const
{
	for (const auto& db_record : database_vector_)
	{
		vector<string> events = database_vector_.at(db_record.first);
		for (const auto& event : events)
		{
			cout << db_record.first << " " << event << endl;;
		}
	}
};


string Database::Last(const Date& date) const { 
	auto found = database_vector_.lower_bound(date);
	if (found->first != date) {
		if (found == database_vector_.begin())
			throw invalid_argument(date.date2str());
		--found;
	}
	if (found == database_vector_.end())
		--found;
	return found->first.date2str() + ' ' + found->second.back();
}





