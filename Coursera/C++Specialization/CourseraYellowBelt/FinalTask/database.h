#pragma once
#include <algorithm>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "date.h"


class Database {
public:
	void Add(const Date& date, const std::string& event);

	void Print(std::ostream& cout) const;

	template <class Func>
	std::vector<std::string> FindIf(Func func) const {
		std::vector<std::string> result;
		for (auto i = database_vector_.begin(); i != database_vector_.end(); i++) {
			auto k = i->second.begin();
			while (true) 
			{
				k = find_if(k, i->second.end(), [func, i](const std::string& ev) {
					return func(i->first, ev);
					});
				
				if (k == i->second.end()) {
					break;
				}
				
				result.push_back((i->first).date2str() + " " + *k++);

			}
		}
		return result;
	}

	template<class Func>
	int RemoveIf(Func func)
	{
		int prevSize = 0, result = 0;
		for (auto dateIt = database_vector_.begin(); dateIt != database_vector_.end();) {
			//if (dateIt->second.empty()) continue;
			auto it = stable_partition(dateIt->second.begin(), dateIt->second.end(),
				[&](const std::string& i_event) {return !func(dateIt->first, i_event); });
			prevSize = dateIt->second.size();

			// remove removed elements from set too
			auto& date = dateIt->first;
			auto eventsDateIt = database_set_.find(date);
			for (auto evIt = it; evIt != dateIt->second.end();) {
				eventsDateIt->second.erase(*evIt);
				evIt++;
			}
			if (eventsDateIt->second.empty()) database_set_.erase(eventsDateIt);

			dateIt->second.resize(std::distance(dateIt->second.begin(), it));
			result += prevSize - dateIt->second.size();
			
			if (dateIt->second.size() == 0)
				dateIt = database_vector_.erase(dateIt);
			else 
				dateIt++;

			//dateIt++;
		}
		return result;
	}

	std::string Last(const Date& date) const;
		
private:
	std::map<Date, std::vector<std::string>> database_vector_;
	std::map<Date, std::set<std::string>> database_set_;
};

