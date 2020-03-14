// SquareAll.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// Предварительное объявление шаблонных функций
template <typename F, typename S> pair<F, S> operator* (const pair<F, S>& p1, const pair<F, S>& p2);
template <typename T> vector<T> Sqr(const vector<T>& v);
template <typename Key, typename Value> map<Key, Value> Sqr(const map<Key, Value>& m);
template<typename T> T Sqr(T x);

template <typename T>
T Sqr(T x) {
	return x * x;
}

template <typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& p) {

	return make_pair(Sqr(p.first), Sqr(p.second));
}

template <typename T>
vector<T> Sqr(const vector<T>& vi) {
	vector<T> new_v;
	for (const auto& item : vi)
	{
		new_v.push_back(Sqr(item));
	}
	return new_v;
}

template <typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& m) {
	map<Key, Value> res;
	for (const auto& i : m) {
		res[i.first] = Sqr(i.second);
	}
	return res;
}

int main()
{
	int x = 2;
	cout << Sqr(x) << endl;

	float  y = 2.5;
	cout << Sqr(y) << endl;

	auto p = Sqr(make_pair(x, y));
	cout << p.first << endl;
	cout << p.second << endl;

	vector<int> vi{1,2,3,4,5};
	cout << "vector:";
	for (int x : Sqr(vi)) {
		cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {  {4, {2, 2}},  {7, {4, 3}} };
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
		cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}

}

