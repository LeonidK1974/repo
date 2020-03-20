// EqualRange.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <algorithm>
#include <iostream>
#include <set>
#include <tuple>
#include <vector>
#include <utility>

using namespace std;
template <typename RandomIt>
pair<RandomIt, RandomIt> FindSegment(
	RandomIt range_begin, RandomIt range_end, int left, int right) {
	// ТЕЛО ФУНКЦИИ

	//auto it1 = upper_bound(range_begin, range_end, left);
	//auto it2 = lower_bound(range_begin, range_end, right);
	
	//auto it1 = lower_bound(range_begin, range_end, left);
	//auto it2 = lower_bound(range_begin, range_end, right);

	//auto it1 = next(lower_bound(range_begin, range_end, left - 1));
	//auto it2 = prev(upper_bound(range_begin, range_end, right + 1));
	
	/*auto it1 = upper_bound(range_begin, range_end, left - 1);
	auto it2 = lower_bound(range_begin, range_end, right + 1);*/
	
	/*auto it1 = lower_bound(range_begin, range_end, left);
	auto it2 = upper_bound(range_begin, range_end, right);*/

	/*auto it1 = upper_bound(range_begin, range_end, left);
	auto it2 = upper_bound(range_begin, range_end, right);*/
	
	return { it1, it2};
}

int main()
{
	//проверка существования в векторе
	vector<int> vec_of_its{1, 0, 3, 4, 2, 0, 4};
	sort(begin(vec_of_its), end(vec_of_its));

	auto p = FindSegment(begin(vec_of_its), end(vec_of_its), 1, 4);
	cout << *p.first << "-" << *p.second << endl;
	
	//auto it = find(begin(vec_of_its), end(vec_of_its), 0);
	/*if (it != end(vec_of_its))
	{
		cout << *it << " exists" << endl;
	}
	else
	{
		cout << "not exists" << endl;
	}
	
	it = find(begin(vec_of_its), end(vec_of_its), 45);
	if (it != end(vec_of_its))
	{
		cout << "exists" << endl;
	}
	else
	{
		cout << "not exists" << endl;
	}*/


	//проверка существования в сортированном векторе
	/*sort(begin(vec_of_its), end(vec_of_its));

	pair<vector<int>::iterator, vector<int>::iterator> p = FindSegment(begin(vec_of_its), end(vec_of_its), 1, 4);
	cout << *p.first << "-" << *p.second << endl; */
	
	/*if (binary_search(begin(vec_of_its), end(vec_of_its), 0))
	{
		cout << "exists" << endl;
	}
	else
	{
		cout << "not exists" << endl;
	}
	if (binary_search(begin(vec_of_its), end(vec_of_its), 45))
	{
		cout << "exists" << endl;
	}
	else
	{
		cout << "not exists" << endl;
	}

	it = lower_bound(begin(vec_of_its), end(vec_of_its), 3);
	if (it != end(vec_of_its))
	{
		cout << *it << " exists" << endl;
	}
	else
	{
		cout << "not exists" << endl;
	}
	*/
	/*auto r = equal_range(begin(vec_of_its), end(vec_of_its), 4);
	cout << r.second - r.first<< endl;*/

	/*auto r = equal_range(begin(vec_of_its), end(vec_of_its), 4);
	for (auto it = r.first; it < r.second; ++it) {
		cout << *it << endl;
	}*/

	//set<int> set_of_ints{ 1, 0, 3, 4, 2, 0, 4 };
	//// проверка существования в множестве
	//if (set_of_ints.count(0) > 0)
	//{
	//	cout << "exists" << endl;
	//}
	//else
	//{
	//	cout << "not exists" << endl;
	//}
	//if (set_of_ints.count(45) > 0)
	//{
	//	cout << "exists" << endl;
	//}
	//else
	//{
	//	cout << "not exists" << endl;
	//}

	//auto its = find(begin(set_of_ints), end(set_of_ints), 0);
	//if (its != end(set_of_ints))
	//{
	//	cout << *its << " exists" << endl;
	//}
	//else
	//{
	//	cout << "not exists" << endl;
	//}
	//
	//its = find(begin(set_of_ints), end(set_of_ints), 45);
	//if (its != end(set_of_ints))
	//{
	//	cout << *its << " exists" << endl;
	//}
	//else
	//{
	//	cout << "not exists" << endl;
	//}
	
	//auto rs = equal_range(begin(set_of_its), end(set_of_its), 5);*/
	
}
