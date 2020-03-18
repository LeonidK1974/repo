// SplitIntoWords.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//my variant
//vector<string> SplitIntoWords(const string& str)
//{
//	vector<string> result_vec;
//	auto space = find(begin(str), end(str),' ');
//	auto start = begin(str);
//
//	while (space != end(str))
//	{		
//		string s(start, space);
//		result_vec.push_back(s);
//		start =++space;
//		space = find(start,end(str), ' ');		
//	}
//	const string s(start, end(str));
//	result_vec.push_back(s);
//	
//	return result_vec;
//}

vector<string> SplitIntoWords(const string& str) {
	// Готовим вектор, в который будем сохранять слова
	vector<string> result;

	// Эти два итератора будут ограничивать текущую не разбитую часть строки
	// str_begin будет двигаться вправо
	auto str_begin = begin(str);
	// str_end всегда будет указывать на конец строки (поэтому он константный)
	const auto str_end = end(str);

	// У цикла нет условия завершения, так что единственный способ закончить его —
	// сделать break
	while (true) {

		// Находим первый пробел в текущем «хвосте» строки
		auto it = find(str_begin, str_end, ' ');

		// Полуинтервал [str_begin, it) — очередное слово
		result.push_back(string(str_begin, it));

		if (it == str_end) {
			// Если пробелов больше нет, цикл пора завершить.
			// Последнее слово уже добавлено
			break;
		}
		else {
			// Иначе первый символ после пробела — начало очередного слова.
			// Туда и подвинем str_begin
			str_begin = it + 1;
		}

	}

	return result;
}


int main()
{
	{
		const string s = "C Cpp Java Python";

		auto words = SplitIntoWords(s);
		cout << words.size() << " ";
		for (auto it = begin(words); it != end(words); ++it) {
			if (it != begin(words)) {
				cout << "/";
			}
			cout << *it;
		}
		cout << endl;

		return 0;
	}
}


