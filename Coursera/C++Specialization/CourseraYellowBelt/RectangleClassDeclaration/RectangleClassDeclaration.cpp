// RectangleClassDeclaration.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Rectangle.h"

using namespace std;

int main()
{
    std::cout << "Hello Rect!\n";
	Rectangle r(3, 4);
	cout << r.GetHeight() << endl;
	cout << r.GetWidth() << endl;
	cout << r.GetArea() << endl;
	cout << r.GetPerimeter() << endl;
}

