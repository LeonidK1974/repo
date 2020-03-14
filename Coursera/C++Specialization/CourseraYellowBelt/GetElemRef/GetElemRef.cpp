// GetElemRef.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

template <typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& m, const Key& k)   {
	if (m.count(k) == 0) {
		throw runtime_error("element not exist");
	}
	
	return m[k];
}


int main()
{
	try {
		map<int, string> m = { {0, "value"} };
		string& item = GetRefStrict(m, 1);
		item = "newvalue";
		cout << m[0] << endl; // выведет newvalue
	}
	catch (exception& ex) {
		cout << ex.what();
	}
	
}
