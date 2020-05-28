// MutexAndLockGuard.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <mutex>
#include <future>
using namespace std;

struct Account {
	int balance = 0;
	vector<int> history;
	mutex m;

	Account(int new_balance) : balance(new_balance)
	{
	}

	
	bool Spend(int value) 
	{
		lock_guard<mutex> g(m);
		if (value <= balance) 
		{ 
			balance -= value;
			history.push_back(value);
			return true; 
		} 
		return false; 
	};
};

int SpendMoney(Account& account) 
{ 
	int total_spent = 0; 
	for (int i = 0; i < 100000; ++i) 
	{ 
		if (account.Spend(1)) 
		{
			
			++total_spent; 
		}
	} 
	return total_spent; 
}


int main()
{
    std::cout << "Hello Race!\n";

	//single-threaded
	Account my_account(100000);
	cout << "Total spent: " << SpendMoney(my_account) << endl;
	cout << "Balance: " << my_account.balance << endl;

	cout << endl;

	//multithreaded
	Account family_account(100000);

	auto husband = async(SpendMoney, ref(family_account)); 
	auto wife = async(SpendMoney, ref(family_account)); 
	auto son = async(SpendMoney, ref(family_account)); 
	auto daughter = async(SpendMoney, ref(family_account));

	int spent = husband.get() + wife.get() + son.get() + daughter.get();

	cout << "Total spent: " << spent << endl;
	cout << "Balance: " << family_account.balance << endl;
}


