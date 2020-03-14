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

int GetDistinctRealRootCount(double a, double b, double c) {
	// Вы можете вставлять сюда различные реализации функции,
	// чтобы проверить, что ваши тесты пропускают корректный код
	// и ловят некорректный
	if (a == 0 && c == 0) {
		return 1;
	}

	double desciminant;
	desciminant = b * b - 4 * a*c;
	if (desciminant < 0) {
		return 0;
	}		
	else if (desciminant == 0) {
		return 1;
	}
	else
	{
		return 2;
	}

}

void TestDescriminantLessZero() {
	AssertEqual(GetDistinctRealRootCount(5, 3, 7), 0);
}

void TestDescriminantZero() {
	AssertEqual(GetDistinctRealRootCount(1, -6, 9), 1);
}

void TestDescriminantAboveZero() {
	AssertEqual(GetDistinctRealRootCount(1, -8, 12), 2);
}

void TestA_Zero() {
	AssertEqual(GetDistinctRealRootCount(0, 3, -9), 1);
}

void TestB_Zero() {
	AssertEqual(GetDistinctRealRootCount(4, 0, -9), 2);
	AssertEqual(GetDistinctRealRootCount(5, 0, 30), 0);
}

void TestC_Zero() {
	AssertEqual(GetDistinctRealRootCount(1, 7, 0), 2);
}

void TestB_C_Zero() {
	AssertEqual(GetDistinctRealRootCount(5, 0, 0), 1);
}

void TestA_C_Zero() {
	AssertEqual(GetDistinctRealRootCount(0, 5, 0), 1);
}

void TestConstant() {
	AssertEqual(GetDistinctRealRootCount(0, 0, 1), 0,
		"c = 0, where c = 1 has 0 real roots.");
	AssertEqual(GetDistinctRealRootCount(0, 0, -10), 0,
		"c = 0, where c = -10 has 0 real roots.");
	AssertEqual(GetDistinctRealRootCount(0, 0, 189238910), 0,
		"c = 0, where c = 189238910 has 0 real roots.");
}



int main() {
	TestRunner runner;
	// добавьте сюда свои тесты
	runner.RunTest(TestDescriminantLessZero, "TestDescriminantLessZero");
	runner.RunTest(TestDescriminantZero, "TestDescriminantZero");
	runner.RunTest(TestDescriminantAboveZero, "TestDescriminantAboveZero");
	runner.RunTest(TestA_Zero, "TestA_Zero");
	runner.RunTest(TestB_Zero, "TestB_Zero");
	runner.RunTest(TestC_Zero, "TestC_Zero");
	runner.RunTest(TestB_C_Zero, "TestB_C_Zero");
	runner.RunTest(TestA_C_Zero, "TestA_C_Zero");
	runner.RunTest(TestConstant, "TestConstant");

	return 0;
}

