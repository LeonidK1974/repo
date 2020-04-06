// ContainersRemoveOp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <algorithm>
#include <iterator>
#include <iostream>
#include <map>
#include <string>

using namespace std;

bool IsPositiveInt(pair<int, string> p)
{
	return p.first <= 0;
}


template <class K, class V, class Func>
int RemoveIf(map<K, V>& m, Func func)
{
	const auto orig_size = m.size();

	map<int, string> good;
	remove_copy_if(m.begin(), m.end(), inserter(good, good.end()), func);
	m.swap(good);
	
	return orig_size - m.size();
}

template <class K, class V, class Func>
int RemoveIf2(map<K, V>& m, Func func)
{
	const auto orig_size = m.size();

	for (auto i = m.begin();
		i != m.end();)
	{
		if  (IsPositiveInt(*i))
		{
			m.erase(i++);
		}
		else
		{
			++i;
		}
	}
	
	return orig_size - m.size();
}

int main()
{
	map<int, string> m = { {0,"string0"},{1,"string1"},{2,"string2"},{3,"string3"} };
	
	//int n_removed = RemoveIf(m, IsPositiveInt);
	int n_removed = RemoveIf2(m, IsPositiveInt);
	
	for (const auto& i : m) {
		std::cout << i.first << ' ' << i.second << endl;
	}
	cout << "Removed: " << n_removed << endl;
	std::cout << '\n';
	
}

