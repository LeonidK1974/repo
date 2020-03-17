// VectorInterval.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void PrintVectorPart(const vector<int>& numbers)
{
	auto border = find_if(begin(numbers), end(numbers), [](const int& num)
	{
			return num < 0;
	});

	while (border != begin(numbers)) {
		--border;
		cout << *border << " ";
	}

	// direct order 
	//for (auto it = begin(numbers); it != border; ++it) {
	//	cout << *it << " ";
	//}

}

int main()
{
    std::cout << "Hello Iterators!\n";
	PrintVectorPart({ 6, 1, 8, -5, 4 });
	cout << endl;
	PrintVectorPart({ -6, 1, 8, -5, 4 });  // ничего не выведется
	cout << endl;
	PrintVectorPart({ 6, 1, 8, 5, 4 });
	cout << endl;
	return 0;
}

