// IteratorsAndReverseIterator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

template <typename It> // написали шаблонную функцию
void PrintRange(It range_begin,	It range_end)
{	 
	for (auto it = range_begin; it != range_end; ++it)
	{
		cout << *it << " ";
	} 
}

int main() 
{	
	vector<string> langs = { "Python", "C++", "C", "Java", "C#" };
	sort(begin(langs), end(langs)); // сортируем по убыванию
	PrintRange(begin(langs), end(langs));
	cout << endl;
	
	sort(rbegin(langs), rend(langs)); // сортируем по убыванию
	PrintRange(begin(langs), end(langs));
	cout << endl;

	vector<int> nums = { 1, 3, 5, 2, 6 };
	sort(begin(nums), end(nums));
	PrintRange(begin(nums), end(nums));
	cout << endl;
	sort(rbegin(nums), rend(nums));
	PrintRange(begin(nums), end(nums));
	cout << endl;

	vector<float> floats = { 1.1, 1.3, 5.0, 2.3566, 3.1415 };
	sort(begin(floats), end(floats));
	PrintRange(begin(floats), end(floats));
	cout << endl;
	sort(rbegin(floats), rend(floats));
	PrintRange(begin(floats), end(floats));
	cout << endl;
	
	
	return 0;
}


