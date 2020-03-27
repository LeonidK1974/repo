// SetOfFigures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//
#include <iomanip>
#include <iostream>
#include <math.h>
#include <memory>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

const double Pi = 3.14;

struct Figure
{
	virtual string Name() const = 0;
	virtual double Perimeter() const = 0;
	virtual double Area() const = 0;
};

class Rect : public Figure
{
public:
	Rect(const string& name,  double width, double height) : name_(name), width_(width), height_(height) {}

	string Name() const override
	{
		return name_;
	}

	double Perimeter() const override
	{
		return (width_ + height_) * 2 ;
	}

	double Area() const override
	{
		return width_ * height_;
	}
	
private:
	string name_;
	double width_;
	double height_;
	
};

class Triangle : public Figure
{
public:
	Triangle(const string& name, double a, double b, double c) : name_(name), a_(a), b_(b), c_(c) {}
	
	string Name() const override
	{
		return name_;
	}
	
	double Perimeter() const override
	{
		return (a_ + b_ + c_);
	}

	double Area() const override
	{
		auto p = Perimeter() / 2;
		return sqrt(p*(p-a_)*(p-b_)*(p-c_));
	}
	
private:
	string name_;
	double a_;
	double b_;
	double c_;
	
};

class Circle : public Figure
{
public:
	Circle(const string& name, double r) : name_(name), r_(r) {}

	string Name() const override
	{
		return name_;
	}

	double Perimeter() const override
	{
		return (2 * Pi * r_);
	}

	double Area() const override
	{
		return Pi * r_ * r_;
	}
	
private:
	string name_;
	double r_;
};

shared_ptr<Figure> CreateFigure(istringstream& is)
{
	string name;
	is >> name;
	if (name == "RECT")
	{
		double width, height;
		is >> width >> height;

		return make_shared<Rect>(name,width,height);
	}
	else if (name == "TRIANGLE")
	{
		double a, b, c;
		is >> a >> b >> c;
		return make_shared<Triangle>(name, a, b, c);
	}
	else if (name == "CIRCLE")
	{
		double r;
		is >> r;
		return make_shared<Circle>(name, r);
	}
	return nullptr;
}


int main() {
	vector<shared_ptr<Figure>> figures;
	for (string line; getline(cin, line); ) {
		istringstream is(line);

		string command;
		is >> command;
		if (command == "ADD") {
			figures.push_back(CreateFigure(is));
		}
		else if (command == "PRINT") {
			for (const auto& current_figure : figures) {
				cout << fixed << setprecision(3)
					<< current_figure->Name() << " "
					<< current_figure->Perimeter() << " "
					<< current_figure->Area() << endl;
			}
		}
	}
	return 0;
}

 