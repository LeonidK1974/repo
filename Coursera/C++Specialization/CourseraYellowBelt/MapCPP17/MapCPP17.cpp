// MapCPP17.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	// use pairs old style
	std::cout << "Hello Map wit pairs!\n";
	map<int, string> digits{ {1, "one"}, {2, "two"} };
	for (const pair<int, string>& item : digits)
	{
		cout << item.first << "=" << item.second << endl;
	}

	// use auto CPP17 style
    std::cout << "Hello New Map!\n";
	for (const auto& [key, value] : digits)
	{
		cout << key << " " << value << endl;
	}

}


