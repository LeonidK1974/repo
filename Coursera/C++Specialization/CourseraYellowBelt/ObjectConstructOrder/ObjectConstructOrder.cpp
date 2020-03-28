// ObjectConstructOrder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

struct Log { // структура данных логер
	Log(string name) : n(name) {
		cout << "+ " << n << endl; // пишет + и свой id, когда создаётся
	};
	~Log() { // деструктор
		cout << "- " << n << endl; // пишет - и свой id, когда удаляется
	}
	string n;
};

	struct Fruit {
		Fruit(const string& t) : l(t + " (Fruit)")	{}
		const Log l ; // заведём логер для фруктов
	};

	struct Apple : public Fruit {
		Apple(const string& t) : Fruit(t), l(t) { // добавили индентификатор и логер
		}
		const Log l; // теперь логер для яблока
	};

class AppleTree
{
public:
	AppleTree() : a1("a1"), a2("a2") { }
	Log l = Log("AppleTree");
	Apple a1;
	Apple a2;
};

int main()
{
	/*Apple a1 = Apple("a1");
	Apple a2 = Apple("a2");*/
	AppleTree at;
	return 0;
}

