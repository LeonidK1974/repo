// RegionDB.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Region.h"

using namespace std;

bool operator<(const Region& lhs, const Region& rhs);
int FindMaxRepetitionCount(const vector<Region>& regions);

int main() {
		cout << FindMaxRepetitionCount({
			{
				"Moscow",
				"Russia",
				{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
				89
			}, {
				"Russia",
				"Eurasia",
				{{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
				89
			}, {
				"Moscow",
				"Russia",
				{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
				89
			}, {
				"Moscow",
				"Russia",
				{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
				89
			}, {
				"Russia",
				"Eurasia",
				{{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
				89
			},
			}) << endl;

		cout << FindMaxRepetitionCount({
			{
				"Moscow",
				"Russia",
				{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
				89
			}, {
				"Russia",
				"Eurasia",
				{{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
				89
			}, {
				"Moscow",
				"Russia",
				{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
				89
			}, {
				"Moscow",
				"Toulouse",
				{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
				89
			}, {
				"Moscow",
				"Russia",
				{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
				31
			},
			}) << endl;

		return 0;
}

