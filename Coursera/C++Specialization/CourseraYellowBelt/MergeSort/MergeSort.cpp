// MergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


//template <typename RandomIt>
//void MergeSort(RandomIt range_begin, RandomIt range_end)
//{
//	if (range_begin + 1 == range_end) { return; }
//	
//	vector<typename RandomIt::value_type> aux_vector(range_begin, range_end);
//
//
//	//int third = (elements.size() / 3);
//	//auto it_lhs = elements.begin() + third;
//	
//	MergeSort(begin(aux_vector), end(aux_vector) - aux_vector.size() / 2);	
//	MergeSort(end(aux_vector) - aux_vector.size() / 2, end(aux_vector));
//	
//	std::merge(begin(aux_vector), end(aux_vector) - aux_vector.size() / 2,
//			   end(aux_vector) - aux_vector.size() / 2, end(aux_vector), 
//			   range_begin);
//			
//}

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
	if (range_begin + 1 == range_end) { return; }

	vector<typename RandomIt::value_type> aux_vector(range_begin, range_end);


	int onethird = (aux_vector.size() / 3);
	//auto it_lhs = elements.begin() + third;

	MergeSort(begin(aux_vector), begin(aux_vector) + onethird);
	MergeSort(begin(aux_vector) + onethird, end(aux_vector) - onethird);
	MergeSort(end(aux_vector) - onethird, end(aux_vector));

	vector<typename RandomIt::value_type> tmp;
	
	std::merge(begin(aux_vector), begin(aux_vector) + onethird,
		begin(aux_vector) + onethird, end(aux_vector) - onethird,
		back_inserter(tmp));

	std::merge(begin(tmp), end(tmp),
		end(aux_vector) - onethird, end(aux_vector),
		range_begin);
}

int main()
{
	/*vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1 };
	MergeSort(begin(v), end(v));
	for (auto x : v) {
		cout << x << " ";
	}*/
	vector<int> v3 = { 6, 4, 7, 6, 4, 4, 0, 1, 5 };
	MergeSort(begin(v3), end(v3));
	for (auto x : v3) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}

