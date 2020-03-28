// InheritanceExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

struct Fruit
{
	int health = 0; // поле здоровья, пусть по умолчанию будет 0 hp
	string type = "fruit"; // добавляем тип того, что мы едим
};

struct Animal
{
	Animal(const string& t = "animal") : type(t) { // хотим проинициализировать type значением t
	}
		
	void Eat(const Fruit& f) { // животное типа type ест фрукты
	cout << type << " eats " << f.type << ". "<< f.health << "hp. ";
	}
	const string type = "animal"; // уберём дублирование в методе Ea
};


struct Apple : public Fruit
{
	Apple() { // нам достаточно написать конструктор для яблока
		health = 10; // яблоко видит поле health у фрукта, поэтому присваиваем 10
		type = "apple"; // явно указываем, что яблоко имеет тип яблока
	}
};

struct Orange : public Fruit
{
	Orange() { // наш код не заработает
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
	Cat() : Animal("cat") { // передаём в Animal нужное нам значение } // которое запишется в константный type
	}

	void Meow() const {
		cout << "meow! ";
	} // удалили метод Eat() у кошки. Она животное, а животные умеют есть

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
	DoMeal(d, a); // эта функция ничего не знает ни о собаках, ни о кошках
	DoMeal(c, o); // она знает только о классах базового типа
	return 0;
}

