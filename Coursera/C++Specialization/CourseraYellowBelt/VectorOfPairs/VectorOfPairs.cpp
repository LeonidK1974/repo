// VectorOfPairs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> a;
	vector<pair<int, int>> b;
	for (int i = 0; i < 100; ++i) a.push_back(rand() % 20);
	sort(a.begin(), a.end());
	pair<int, int> p{ a[0],1 };
	for (int i = 1; i < a.size(); ++i)
	{
		if (p.first == a[i]) { p.second++; continue; }
		b.push_back(p);
		p = { a[i], 1 };
	}
	b.push_back(p);
	for (auto i : b)
		cout << setw(3) << i.first << setw(10) << i.second << "\n";
}


