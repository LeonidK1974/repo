// InheritanceManual.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
	// ваш код
	Animal(const string& n)
		: Name(n) {
	}
	
	const string Name;
};


class Dog : public Animal{
public:
	// ваш код
	Dog(string n) : Animal(n){
	}

	void Bark() {
		cout << Name << " barks: woof!" << endl;
	}
};

//int main()
//{
//    std::cout << "Hello Animals!\n";
//	Dog d("Tosha");
//	d.Bark();
//}

