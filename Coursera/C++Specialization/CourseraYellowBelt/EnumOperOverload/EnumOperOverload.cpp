// EnumOperOverload.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <algorithm>
#include <iostream>
using namespace std;

enum class Color { 
	Begin, 
	Red = Begin, 
	Green, Blue, 
	End };

struct Colors
{
	Color begin() const { return Color::Begin; }
	Color end() const { return Color::End; }
};

// перегрузка инкремента
Color& operator++(Color& col) { return (Color&)(++(int&)col); }

Color operator*(Color col) { return col; }

void Foo(Color col) {
	cout << static_cast<int>(col) << endl;
}



int main()
{
	// ...
	cout << "for loop on enum:" << endl;
	for (Color col = Color::Begin; col < Color::End; ++col)
	{
		Foo(col);
	}

	cout << "for_each loop on enum:" << endl;
	for_each(Color::Begin, Color::End, Foo);

	cout << "range-based loop on enum:" << endl;
	for (const auto& col : Colors())
	{
		Foo(col);
	}

}

