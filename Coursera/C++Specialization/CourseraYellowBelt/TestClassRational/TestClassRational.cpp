#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
	os << "{";
	bool first = true;
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
	os << "{";
	bool first = true;
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
	os << "{";
	bool first = true;
	for (const auto& kv : m) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << kv.first << ": " << kv.second;
	}
	return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
	if (t != u) {
		ostringstream os;
		os << "Assertion failed: " << t << " != " << u;
		if (!hint.empty()) {
			os << " hint: " << hint;
		}
		throw runtime_error(os.str());
	}
}

void Assert(bool b, const string& hint) {
	AssertEqual(b, true, hint);
}

class TestRunner {
public:
	template <class TestFunc>
	void RunTest(TestFunc func, const string& test_name) {
		try {
			func();
			cerr << test_name << " OK" << endl;
		}
		catch (exception& e) {
			++fail_count;
			cerr << test_name << " fail: " << e.what() << endl;
		}
		catch (...) {
			++fail_count;
			cerr << "Unknown exception caught" << endl;
		}
	}

	~TestRunner() {
		if (fail_count > 0) {
			cerr << fail_count << " unit tests failed. Terminate" << endl;
			exit(1);
		}
	}

private:
	int fail_count = 0;
};

int GetNOD(int a, int b)
{
	a = abs(a);
	b = abs(b);
	while (a > 0 && b > 0)
	{
		if (a > b)
		{
			a = a % b;
		}
		else
		{
			b = b % a;
		}
	}

	return a + b;
}

//class Rational {
//public:
//	Rational() {
//		// Реализуйте конструктор по умолчанию
//		m_numerator = 0;
//		m_denominator = 1;
//	}
//
//	Rational(int numerator, int denominator) {
//		// Реализуйте конструктор
//		if (numerator < 0 && denominator < 0)
//		{
//			numerator = abs(numerator);
//			denominator = abs(denominator);
//		}
//		nod = GetNOD(numerator, denominator);
//		numerator /= nod;
//		denominator /= nod;
//		if (denominator < 0)
//		{
//			m_numerator = -numerator;
//		}
//		else {
//			m_numerator = numerator;
//		}
//
//		m_denominator = abs(denominator);
//	}
//
//	int Numerator() const {
//		// Реализуйте этот метод
//
//		return m_numerator;
//	}
//
//	int Denominator() const {
//		// Реализуйте этот метод		
//		return m_denominator;
//	}
//
//private:
//	// Добавьте поля
//	int m_numerator;
//	int m_denominator;
//	int nod;
//};

void TestRationalInit() {
	Rational r;
	AssertEqual(r.Numerator(), 0);
	AssertEqual(r.Denominator(), 1);
}

void TestRationalSimplify() {
	Rational r(3,9);
	AssertEqual(r.Numerator(), 1);
	AssertEqual(r.Denominator(), 3);
}

void TestRationalNegative() {
	Rational r(1, -3);
	AssertEqual(r.Numerator(), -1);
	AssertEqual(r.Denominator(), 3);
}

void TestRationalPositive() {
	Rational r(-2, -3);
	AssertEqual(r.Numerator(), 2);
	AssertEqual(r.Denominator(), 3);
}

void TestRationalZeroNominator() {
	Rational r(0, 3);
	AssertEqual(r.Numerator(), 0);
	AssertEqual(r.Denominator(), 1);
}

int main() {
	TestRunner runner;
	// добавьте сюда свои тесты
	runner.RunTest(TestRationalInit, "TestRationalInit");
	runner.RunTest(TestRationalSimplify, "TestRationalSimplify");
	runner.RunTest(TestRationalNegative, "TestRationalNegative");
	runner.RunTest(TestRationalPositive, "TestRationalPositive");
	runner.RunTest(TestRationalZeroNominator, "TestRationalZeroNominator");
	return 0;
}


