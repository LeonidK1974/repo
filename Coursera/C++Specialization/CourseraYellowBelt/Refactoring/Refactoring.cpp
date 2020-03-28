// Refactoring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Person
{
	Person(const string& j =" Person") : Job(j){}
	virtual void Walk(const string& destination) const {};
	const string Job = "Person";
};

class Student : public Person {
public:	
	Student(const string& name, const string& favoriteSong) : Name(name), FavoriteSong(favoriteSong) {
	}

	void Learn() const {
		cout << "Student: " << Name << " learns" << endl;
	}

	void Walk(const string& destination) const override{
		cout << "Student: " << Name << " walks to: " << destination << endl;
		cout << "Student: " << Name << " sings a song: " << FavoriteSong << endl;
	}

	void SingSong() const {
		cout << "Student: " << Name << " sings a song: " << FavoriteSong << endl;
	}

	string Job = "Student";
	string Name;
	string FavoriteSong;
};


class Teacher : public Person {
public:
	
	Teacher(const string& name,const string& subject) : Name(name), Subject(subject) {
	}

	void Teach() const {
		cout << "Teacher: " << Name << " teaches: " << Subject << endl;
	}

	void Walk(const string& destination) const override{
		cout << "Teacher: " << Name << " walks to: " << destination << endl;
	}

	string Job = "Teacher";
	string Name;
	string Subject;
};


class Policeman : Person {
public:
	Policeman() : Person("Policeman"){}
	
	Policeman(const string& name) : Name(name) {
	}

	template <class T> 
	void Check(const T& t) const {
		cout << "Policeman: " << Name << " checks " << t.Job << ". " << t.Job << "'s name is: " << t.Name << endl;
	}


	void Walk(const string& destination) const override{
		cout << "Policeman: " << Name << " walks to: " << destination << endl;
	}

	string Job = "Policeman";
	string Name;
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


