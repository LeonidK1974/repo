// Permutations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

void PrintSequence(const vector<int>& v)
{	
	for (const auto& item : v)
	{
		cout << item << " ";
	}
}

int main()
{
	int range;
	cin >> range;
	//int iter = 0;
	vector<int> v_seq(range);
	iota(v_seq.begin(), v_seq.end(), 1);
	
	reverse(begin(v_seq), end(v_seq));
	//cout << ++iter << endl;

	do
	{
		//cout << ++iter << endl;
		PrintSequence(v_seq);
		cout << endl;
	} while (prev_permutation(begin(v_seq), end(v_seq)));
	
}


