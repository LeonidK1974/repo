// GroupStringsBySymbol.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

template<class Iter, class T, class Proj>
std::pair<Iter, Iter> my_equal_range(Iter first, Iter last, const T& value, Proj proj) {
	auto b = std::partition_point(first, last, [&](const auto& s) { return proj(s) < value; });
	auto e = std::partition_point(b, last, [&](const auto& s) { return !(value < proj(s)); });
	return { b, e };
}

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
	RandomIt range_begin, RandomIt range_end,
	char prefix)
{
	return my_equal_range(range_begin, range_end, prefix,
		[](const auto& s) { return s.front(); });
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


