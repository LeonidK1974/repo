// Test_iterator_usage.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

bool f(const int& num)
{
	if (num < 0) {
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{

	//set<int> s = { -1, 2, -3, -4, 5, 0 };
	//vector<int> v;

	////1 true
	//{
	//	v.clear();
	//	auto it = remove_copy_if(begin(s), end(s),
	//		back_inserter(v), f);
	//}
	//
	////2 true
	//{
	//	v.clear();
	//	vector<int> garbage;
	//	partition_copy(
	//	begin(s), end(s),
	//	back_inserter(garbage), back_inserter(v), f);
	//}
	//
	////3 true
	//{
	//	v.clear();
	//	copy_if(begin(s), end(s), back_inserter(v),
	//		[](int x) { return !f(x); });
	//}
	//

	////4 true
	//{
	//	v.clear();
	//	v.assign(begin(s), end(s));
	//	auto it = remove_if(begin(v), end(v), f);
	//	v.erase(it, end(v));
	//}

	////5 true
	//{
	//	v.clear();
	//	v.assign(begin(s), end(s));
	//	sort(begin(v), end(v),
	//		[](int lhs, int rhs) { return f(lhs) > f(rhs); });
	//	auto it = partition_point(begin(v), end(v), f);
	//	v.erase(begin(v), it);
	//}
	//

	////6 true
	//{
	//	v.clear();
	//	v.assign(begin(s), end(s));
	//	auto it = partition(begin(v), end(v), f);
	//	v.erase(begin(v), it);
	//}

	////7 false
	//{
	//	v.clear();
	//	copy_if(begin(s), end(s), back_inserter(v), f);
	//}

	////8 false
	//{
	//	v.clear();
	//	v.assign(begin(s), end(s));
	//	auto it = remove_if(begin(v), end(v),
	//		[](int x) { return !f(x); });
	//	v.erase(it, end(v));
	//}

	////9 false
	//{
	//	v.clear();
	//	v.assign(begin(s), end(s));
	//	auto it = partition(begin(v), end(v), f);
	//	v.erase(it, end(v));
	//}

	////10 false
	//{
	//	v.clear();
	//	v.assign(begin(s), end(s));
	//	sort(begin(v), end(v),
	//		[](int lhs, int rhs) { return f(lhs) > f(rhs); });
	//	auto it = partition_point(begin(v), end(v), f);
	//	v.erase(it, end(v));
	//}

	////11 false
	//{
	//	v.clear();
	//	remove_copy_if(begin(s), end(s), back_inserter(v),
	//		[](int x) { return !f(x); });
	//}

	////12 false
	//{
	//	v.clear();
	//	remove_copy_if(begin(s), end(s), back_inserter(v),
	//		[](int x) { return !f(x); });
	//}

	////13 false
	//{
	//	v.clear();
	//	auto it = partition(begin(s), end(s), f);
	//	//copy(it, end(s), back_inserter(v));
	//}

	////14 false
	//{
	//	v.clear();
	//	vector<int> garbage;
	//	partition_copy(
	//		begin(s), end(s),
	//		back_inserter(v), back_inserter(garbage), f);
	//}
	

	//test 2
	vector<int> vec;
	auto vector_begin = begin(vec);
	auto vector_end = end(vec);

	string str;
	auto string_begin = begin(str);
	auto string_end = end(str);

	set<int> s;
	auto set_begin = begin(s);
	auto set_end = end(s);

	// false
	/*{
		partial_sum(vector_begin, vector_end, set_begin);
	}*/
	
	{
		auto res = accumulate(set_begin, set_end, 0);
	}
	
	{
		auto res = is_permutation(set_begin, set_end, vector_begin);
	}

	{
		auto res = is_heap(string_begin, string_end);
	}

	// false
	/*{
		auto res = is_heap(set_begin, set_end);
	}*/

	{
		auto res =
			is_permutation(vector_begin, vector_end, vector_begin);
	}

	{
		auto res = accumulate(vector_begin, vector_end, 0);
	}

	// false
	/*{
		auto res = next_permutation(set_begin, set_end);
	}*/
	
	{
		auto res = next_permutation(string_begin, string_end);
	}

	{
		partial_sum(set_begin, set_end, back_inserter(vec));
	}

	{
		partial_sum(set_begin, set_end, vector_begin);
	}

	//false
	/*{
		auto res =
			is_permutation(set_begin, set_end, back_inserter(vec));
	}*/

	{
		auto res = next_permutation(string_begin, string_end);
	}

	
	//test 3
	vector<int> nums{ 1, 2, 3, 5, 7, 6 };
	auto it= is_sorted_until(begin(nums), end(nums));
	auto it2 = is_sorted_until(rbegin(nums), rend(nums));

	return 0;
}
