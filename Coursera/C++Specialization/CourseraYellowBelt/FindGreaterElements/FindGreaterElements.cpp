// FindGreaterElements.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border)
{
	vector<T> result;
	auto it_border = find_if(begin(elements), end(elements), [border](const T& element)
	{
		return element > border;
	});

	while (it_border != end(elements))
	{		
		result.push_back(*it_border);
		++it_border;
	}

	return result;
}

int main()
{
	for (auto x : FindGreaterElements(set<int>{1, 5, 8, 7}, 3)) {
		cout << x << " ";
	}
	cout << endl;

	const string to_find = "C#";
	cout << FindGreaterElements(set<string>{"C", "C++", "C#"}, to_find).size() << endl;
	return 0;
}

