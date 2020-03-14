// TemplateFunctions.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <utility>

using namespace std;

template <typename F, typename S>
pair<F, S> operator* (const pair<F, S>& p1, const pair<F, S>& p2) {
	F f = p1.first * p2.first;
	S s = p1.second * p2.second;
	return make_pair(f, s);
}

template <typename T>
T Sqr(T x) {
	return x * x;
}

int main()
{
    std::cout << "Hello Templates!\n";
	int x = 2;
	cout << Sqr(x) << endl;

	float  y = 2.5;
	cout << Sqr(y) << endl;

	auto p = Sqr(make_pair(x, y));
	cout << p.first << endl;
	cout << p.second << endl;
}

