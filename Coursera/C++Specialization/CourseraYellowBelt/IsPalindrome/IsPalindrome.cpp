// IsPalindrome.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom(const string& str) {
	// Вы можете вставлять сюда различные реализации функции,
	// чтобы проверить, что ваши тесты пропускают корректный код
	// и ловят некорректный
	if (str.empty())
		return true;

	string input = str;
	transform(input.begin(), input.end(), input.begin(), ::tolower);
	if (input[0] == input[input.length() - 1])
		return true;
	else
		return false;

}

int main()
{
    cout << "Hello Palindromes!\n";

	cout << IsPalindrom("madam") << endl;
	cout << IsPalindrom("olala") << endl;
	cout << IsPalindrom("lol") << endl;
	cout << IsPalindrom("") << endl;
	cout << IsPalindrom("1") << endl;
	cout << IsPalindrom(" ") << endl;
}


