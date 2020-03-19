// RemoveDuplicates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

//My answer
//template <typename T>
//void RemoveDuplicates(vector<T>& elements)
//{
//	set<T> s(elements.begin(), elements.end());
//	elements.assign(s.begin(), s.end());
//}

template <typename DataType>
void RemoveDuplicates(vector<DataType>& elements) {
	sort(begin(elements), end(elements));
	elements.erase(
		unique(begin(elements), end(elements)),
		elements.end());
}

int main() {
	vector<int> v1 = { 6, 4, 7, 6, 4, 4, 0, 1 };
	RemoveDuplicates(v1);
	for (int x : v1) {
		cout << x << " ";
	}
	cout << endl;

	vector<string> v2 = { "C", "C++", "C++", "C", "C++" };
	RemoveDuplicates(v2);
	for (const string& s : v2) {
		cout << s << " ";
	}
	cout << endl;
	return 0;
}


