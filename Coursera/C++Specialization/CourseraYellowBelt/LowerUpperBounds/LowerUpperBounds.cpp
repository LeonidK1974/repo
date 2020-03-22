// LowerUpperBounds.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	map<int, string> m_first{ {1965, "Polina"}, {1968, "Apolina"} };
	map<int, string> m_second{ {1965, "Sergeeva"}, {1970, "Volkova"} };

	const int year = 1990;
	auto iter_after = m_first.upper_bound(year);
	if(iter_after != m_first.begin())
	{
		cout << prev(iter_after)->second;
	}
		
}


