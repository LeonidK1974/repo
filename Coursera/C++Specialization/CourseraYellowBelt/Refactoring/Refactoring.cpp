// Refactoring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
public:
	Person(const string& name, const string occupation) : name_(name), occupation_(occupation){}
	
	virtual void Walk(const string& destination) const
	{
		cout << GetOccupation() << ": " << GetName() << " walks to: " << destination << endl;
	};

	string GetName() const
	{
		return name_;
	}

	string GetOccupation() const
	{
		return occupation_;
	}

	string Log() const
	{
		return GetOccupation() + ": " + GetName();
	}

protected:
	const string name_;
	const string occupation_;
};

class Student : public Person {
public:	
	Student(const string& name, const string& favoriteSong) : Person(name,"Student"), favoriteSong_(favoriteSong) {
	}

	void Learn() const {
		cout << Log() << " learns" << endl;
	}

	void Walk(const string& destination) const override{
		Person::Walk(destination);
		SingSong();
	}

	void SingSong() const {
		cout << Log() << " sings a song: " << favoriteSong_ << endl;
	}

private:
	const string favoriteSong_;
};


class Teacher : public Person {
public:
	
	Teacher(const string& name,const string& subject) : Person(name, "Teacher"), subject_(subject) {
	}

	void Teach() const {
		cout << Log()<< " teaches: " << subject_ << endl;
	}

private:
	const string subject_;
};


class Policeman : Person {
public:	
	Policeman(const string& name) : Person(name, "Policeman") {
	}

	void Check(const Person& p) const {
		cout << Log() << " checks " << p.GetOccupation() << ". " << p.GetOccupation() << "'s name is: " << p.GetName() << endl;
	}
};

void VisitPlaces(const Person& human, const vector<string>& places)
{
	for (const auto& h : places) {
		human.Walk(h);
	}
}

int main() {
	const Teacher t("Jim", "Math");
	const Student s("Ann", "We will rock you");
	const Policeman p("Bob");

	VisitPlaces(t, { "Moscow", "London" });
	p.Check(s);
	VisitPlaces(s, { "Moscow", "London" });
	return 0;
}


