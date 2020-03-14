// VectorNM.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

void PrintVectorRangeReverse(vector<int>& v, int m , int n) {
	for (size_t k = v.size(); k > n + m; --k) {
		size_t i = k - m - 1;
		cout << v[i] << endl;
	}
}

void PrintVectorRange(vector<int>& v, int n, int m) {
	for (size_t i = n; i + m < v.size(); ++i) {
		cout << v[i] << endl;
	}
}

int main()
{

    std::cout << "Hello World!\n";
	//unsigned n, m;
	//cin >> m >> n;
	vector<int> v{ 1, 2, 3, 4, 5 };
	PrintVectorRange(v, 1, 1);
	PrintVectorRangeReverse(v, 1, 1);
}

