// ClassTemplate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T, typename U> 
struct Pair { 
	T first; 
	U second; 
};


// variant 1
//template <typename Iterator> 
//struct IteratorRange { 
//	Iterator first, last; 
//	Iterator begin() const { 
//		return first; 
//	} 
//	Iterator end() const {
//		return last; 
//	}
//};

template <typename Iterator> 
class IteratorRange {
private: 
	Iterator first, last;

public: 
	IteratorRange(Iterator f, Iterator l) : first(f), last(l) { } 
		Iterator begin() const { 
			return first; 
		} 
		Iterator end() const { 
			return last; 
		}
};

template <typename T>
IteratorRange<typename vector<T>::iterator> Head(vector<T>& v, size_t top) { 
	return { 
		v.begin(), 
		next(v.begin(), min(top, v.size())) 
	}; 
}


int main()
{
	std::cout << "Hello Class Templates!\n";
	Pair<int, int> p_of_ints;
	p_of_ints.first = 1;
	p_of_ints.second = 2;

	vector<int> v = { 1, 2, 3, 4, 5}; 
	for (int x : Head(v, 3)) 
	{ 
		cout << x << " "; 
	}
    
	IteratorRange second_half(v.begin() + v.size() / 2, v.end());
	for (int x : second_half)
	{
		cout << x << " ";
	}

}

