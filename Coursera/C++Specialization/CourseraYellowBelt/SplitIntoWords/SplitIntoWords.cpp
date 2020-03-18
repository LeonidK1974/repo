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
	// ������� ������, � ������� ����� ��������� �����
	vector<string> result;

	// ��� ��� ��������� ����� ������������ ������� �� �������� ����� ������
	// str_begin ����� ��������� ������
	auto str_begin = begin(str);
	// str_end ������ ����� ��������� �� ����� ������ (������� �� �����������)
	const auto str_end = end(str);

	// � ����� ��� ������� ����������, ��� ��� ������������ ������ ��������� ��� �
	// ������� break
	while (true) {

		// ������� ������ ������ � ������� ������� ������
		auto it = find(str_begin, str_end, ' ');

		// ������������ [str_begin, it) � ��������� �����
		result.push_back(string(str_begin, it));

		if (it == str_end) {
			// ���� �������� ������ ���, ���� ���� ���������.
			// ��������� ����� ��� ���������
			break;
		}
		else {
			// ����� ������ ������ ����� ������� � ������ ���������� �����.
			// ���� � �������� str_begin
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


