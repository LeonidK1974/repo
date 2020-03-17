// FindGreaterElementAuthor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
#include <vector>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
	// ����� ������������� �� ���������
	auto it = begin(elements);
	// ���� � ����� ������ �������, ������� border
	// ���� �������� �� ������ ����� � ��������� �� ����, �������
	while (it != end(elements) && *it <= border) {
		++it;
	}
	// ���������� ������, ��������� �� ��������� ���������, ������� � it
	return { it, end(elements) };
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

