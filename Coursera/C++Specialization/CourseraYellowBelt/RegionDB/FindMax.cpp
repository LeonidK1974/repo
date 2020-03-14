#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Region.h"

using namespace std;

bool operator<(const Region& lhs, const Region& rhs)
{
	return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
		tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
	int result = 0;
	map<Region, int> regionsDB;
	for (const auto& item : regions) {
		result = max(result, ++regionsDB[item]);
	}

	return result;
}