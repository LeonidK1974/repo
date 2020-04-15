// DequeTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <deque>
#include <iostream>

using namespace std;

int main()
{
    std::cout << "Hello Deque!\n";
	deque<int> deq;
	deq.push_front(1);
	deq.push_back(3);
	deq.push_front(2);
	deq.push_back(4);
	deq.push_front(3);
	deq.push_back(5);
	deq.push_front(5);
	deq.push_front(6);

	for (auto& item : deq)
	{
		cout << item << " ";
	}

	cout << deq[8];
}

