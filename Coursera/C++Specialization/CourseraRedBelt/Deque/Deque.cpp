// Deque.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

template <typename T>
class Deque
{
public:
	Deque() {}
	
	bool Empty() const
	{
		return head_.empty() && tail_.empty();
	}
	
	size_t Size() const
	{
		return head_.size() + tail_.size();
	}

	T& operator[](size_t index)
	{
		if (index < head_.size() && (!head_.empty()))
		{
			return head_.at(head_.size() - index - 1);
		}
		else
		{
			return tail_.at(index - head_.size());
		}
			
	}
	
	const T& operator[](size_t index) const
	{
		if (index < head_.size() && (!head_.empty()))
		{
			return head_.at(head_.size() - index - 1);
		}
		else
		{
			return tail_.at(index - head_.size());
		}

	}

	T& At(size_t index)
	{
		if (index < head_.size() && (!head_.empty())) {
			return head_.at(head_.size() - index - 1);
		}
		else
		{
			return tail_.at(index - head_.size());
		}
	}

	const T& At(size_t index) const
	{
		if (index < head_.size() && (!head_.empty())) {
			return head_.at(head_.size() - index - 1);
		}
		else
		{
			return tail_.at(index - head_.size());
		}
	}

	T& Front()
	{
		if (!head_.empty()) 
		{
			return head_.back();
		}
		else 
		{
			return *(tail_.begin());
		}
	}

	const T& Front() const
	{
		if (!head_.empty())
		{
			return head_.back();
		}
		else
		{
			return *(tail_.begin());
		}
	}

	T& Back()
	{
		if (!tail_.empty()) {
			return tail_.back();
		}
		else 
		{
			return *(head_.begin());
		}
	}

	const T& Back() const
	{
		if (!tail_.empty()) {
			return tail_.back();
		}
		else
		{
			return *(head_.begin());
		}
	}

	void PushFront(const T& element)
	{
		head_.push_back(element);
	}

	void PushBack(const T& element)
	{
		tail_.push_back(element);
	}
	
private:
	vector<T> head_, tail_;
};

int main()
{	
 //   std::cout << "Hello Deque!\n";
	//Deque<int> deq;
	//cout << deq.Size() << endl;
	////deq[2] = 0;
	//if (deq.Empty())
	//{
	//	deq.PushFront(1);
	//	deq.PushBack(3);
	//	deq.PushFront(2);
	//	deq.PushBack(4);
	//	deq.PushFront(3);
	//	deq.PushBack(5);
	//	deq.PushFront(5);
	//	deq.PushFront(6);
	//	cout << deq.Back() << endl;
	//	cout << deq.Front() << endl;
	//	cout << deq.Size() << endl;
	//}
	////deq[8] = 33;
	//cout << deq.At(8);
	
}

