// FindNearestElement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

set<int>::const_iterator FindNearestElement(
	const set<int>& numbers,
	const int border)
{
	if (numbers.empty())
	{
		return end(numbers);
	}
	auto it = numbers.lower_bound(border);
	if (it == begin(numbers))
	{
		return it;
	}
	else if (it == end(numbers) || *it - border >= border - *prev(it))
	{
		--it;
	}

	return it;
}
// set<int>::const_iterator —
// тип итераторов для константного множества целых чисел

int main() {
	const set<int> numbers = { 1, 4, 6 };
	cout <<
		*FindNearestElement(numbers, 0) << " " <<
		*FindNearestElement(numbers, 3) << " " <<
		*FindNearestElement(numbers, 5) << " " <<
		*FindNearestElement(numbers, 6) << " " <<
		*FindNearestElement(numbers, 100) << endl;

	set<int> empty_set;

	cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
	return 0;
}


