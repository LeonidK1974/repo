// GroupStringsBySymbol.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
	RandomIt range_begin, RandomIt range_end,
	char prefix)
{
	RandomIt iter_beg, iter_end;
	return make_pair(iter_beg, iter_end);
	//return make_pair(iter_beg, iter_end) = equal_range(range_begin, range_end, 
	//	prefix,
	//	[](const string& city)
	//	{
	//		return city[0] != 'C';
	//	});;
}

int main()
{
	const vector<string> sorted_strings = { "moscow", "murmansk", "vologda" };

	const auto m_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
	for (auto it = m_result.first; it != m_result.second; ++it) {
		cout << *it << " ";
	}
	cout << endl;

	const auto p_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
	cout << (p_result.first - begin(sorted_strings)) << " " <<
		(p_result.second - begin(sorted_strings)) << endl;

	const auto z_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
	cout << (z_result.first - begin(sorted_strings)) << " " <<
		(z_result.second - begin(sorted_strings)) << endl;

	return 0;
}


