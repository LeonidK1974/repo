// ListSplice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

std::ostream& operator<<(std::ostream& ostr, const std::list<int>& list)
{
	for (auto &i : list) {
		ostr << " " << i;
	}
	return ostr;
}

int main()
{
	list<int> list1 = { 1, 2, 3, 4, 5 };
	//std::list<int> list2 = { 10, 20, 30, 40, 50 };
	//list<int> list2;


	auto it1 = list1.begin();
	auto it2 = it1;
	std::advance(it2, 2);

	//iter_swap(it1, it3);
	auto it2_next { next(it2) };
	list1.splice(it1, list1, it2);
	list1.splice(it2_next, list1, it1);

	std::cout << "list1: " << list1 << "\n";
	//std::cout << "list2: " << list2 << "\n";

	/*auto it = list1.begin();
	std::advance(it, 2);

	list1.splice(it, list2);

	std::cout << "list1: " << list1 << "\n";
	std::cout << "list2: " << list2 << "\n";

	list2.splice(list2.begin(), list1, it, list1.end());

	std::cout << "list1: " << list1 << "\n";
	std::cout << "list2: " << list2 << "\n";*/
}
