// ArithmeticExpression.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//variant 1
//#include <iostream>
//#include <string>
//#include <deque>
//
//using namespace std;
//
//void AddOps(deque<string>& result, const string& op, const string& operand)
//{
//	result.push_front("(");
//	result.emplace_back(")");
//	result.emplace_back(" ");
//	result.emplace_back(op);
//	result.emplace_back(" ");
//	result.emplace_back(operand);
//}
//
//void PrintResult(const deque<string>& deq)
//{
//	for (const auto& item : deq)
//	{
//		cout << item;
//	}
//}
//
//int main()
//{
//	deque<string> result;
//	int first_number;
//	cin >> first_number;
//	result.push_back(to_string(first_number));
//	int op_count;
//	cin >> op_count;
//	if (op_count > 0)
//	{
//		for (auto i = 0; i < op_count; ++i)
//		{
//			string op, operand;
//			cin >> op >> operand;
//
//			AddOps(result, op, operand);
//		}
//	}
//
//	PrintResult(result);
//		
//}

//variant 2
#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool NeedBracket(string prev, string next) {
	return (prev == "+" || prev == "-") && (next == "*" || next == "/");
}

void AddOps(deque<string>& result, const string& op, const string& prev_op, const string& operand)
{
	if (NeedBracket(prev_op, op))
	{
		result.push_front("(");
		result.emplace_back(")");
	}
	
	result.emplace_back(" ");
	result.emplace_back(op);
	result.emplace_back(" ");
	result.emplace_back(operand);
}

void PrintResult(const deque<string>& deq)
{
	for (const auto& item : deq)
	{
		cout << item;
	}
}



int main()
{
	deque<string> result;
	int first_number;
	cin >> first_number;
	result.emplace_back(to_string(first_number));
	int op_count;
	cin >> op_count;
	if (op_count > 0)
	{
		string prev_op{"*"};
		for (auto i = 0; i < op_count; ++i)
		{
			string op, operand;
			cin >> op >> operand;

			AddOps(result, op, prev_op, operand);
			prev_op = op;
		}
	}

	PrintResult(result);
		
}

