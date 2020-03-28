// InheritanceExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

struct Fruit
{
	int health = 0; // ���� ��������, ����� �� ��������� ����� 0 hp
	string type = "fruit"; // ��������� ��� ����, ��� �� ����
};

struct Animal
{
	Animal(const string& t = "animal") : type(t) { // ����� ������������������� type ��������� t
	}
		
	void Eat(const Fruit& f) { // �������� ���� type ��� ������
	cout << type << " eats " << f.type << ". "<< f.health << "hp. ";
	}
	const string type = "animal"; // ����� ������������ � ������ Ea
};


struct Apple : public Fruit
{
	Apple() { // ��� ���������� �������� ����������� ��� ������
		health = 10; // ������ ����� ���� health � ������, ������� ����������� 10
		type = "apple"; // ���� ���������, ��� ������ ����� ��� ������
	}
};

struct Orange : public Fruit
{
	Orange() { // ��� ��� �� ����������
		health = 5;
		type = "orange";
	}
};

struct PineApple : public Fruit
{
	PineApple() {
		health = 15;
		type = "papple";
	}
};

struct Cat : public Animal
{
	Cat() : Animal("cat") { // ������� � Animal ������ ��� �������� } // ������� ��������� � ����������� type
	}

	void Meow() const {
		cout << "meow! ";
	} // ������� ����� Eat() � �����. ��� ��������, � �������� ����� ����

};

struct Dog : public Animal
{
	Dog() : Animal("dog") {
	}
};

void DoMeal(Animal& a, Fruit& f)
{
	a.Eat(f);
}
	
int main()
{
	Dog d;
	Cat c;
	Orange o;
	Apple a;
	DoMeal(d, a); // ��� ������� ������ �� ����� �� � �������, �� � ������
	DoMeal(c, o); // ��� ����� ������ � ������� �������� ����
	return 0;
}

