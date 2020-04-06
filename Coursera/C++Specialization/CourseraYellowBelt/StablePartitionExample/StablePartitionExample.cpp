// StablePartitionExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Demonstrates usage of "Stable_partition" algorithm in conjunction with erase
// Stable_partition works with blocks containers and does not work with assotiative containers

#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>	// need for std::tuple use (кортеж)
#include <utility> // need for std::pair use (пара)
#include <vector>

using namespace std;

bool IsPositiveInt(int n)
{
	return n > 0;
}

bool IsPositivePair(std::pair<int, string>& p)
{
	return p.first > 0;
}

bool IsPositiveTuple(std::tuple<string, int, string> t)
{
	return std::get<1>(t) > 0;
}

template <class T, class Func>
int RemoveIf (vector<T>& v, Func func)
{
	const auto orig_size = v.size();
	
	auto it = std::stable_partition(begin(v), end(v), func);
	auto it_erased = v.erase(it, v.end());
	const auto removed_number = orig_size - v.size();

	return removed_number;
}

int main()
{	
	std::vector<int> v{ 0, 0, 3, 0, 2, 4, 5, 0, 7 };

	int n_removed = RemoveIf(v, IsPositiveInt);
	
	for (const auto& i : v) {
		std::cout << i << endl;
	}
	cout << "Removed: " << n_removed << endl;
	std::cout << '\n';
	
	vector<pair<int, string>> p = { {0,"string0"},{1,"string1"},{2,"string2"},{3,"string3"}};
	
	n_removed = RemoveIf(p, IsPositivePair);
	
	for (const auto& i : p) {
		std::cout << i.first << ' ' << i.second << endl;
	}
	cout << "Removed: " << n_removed << endl;
	std::cout << '\n';

	typedef std::tuple<std::string, int, std::string> TUPLE;
	vector<TUPLE> t = { {"string0",0,"string0"},{"string1",1,"string1"},{"string2", 2,"string2"},{"string3",3,"string3"} };
	n_removed = RemoveIf(t, IsPositiveTuple);
	for (const auto& i : t) {
		std::cout <<  std::get<0>(i) << ' ' << std::get<1>(i) << ' ' << std::get<2>(i) << endl;
	}
	cout << "Removed: " << n_removed << endl;
	std::cout << '\n';
	
	return 0;
}

