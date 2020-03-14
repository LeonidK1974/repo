#include <algorithm>
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
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
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

bool IsPalindrom(const string& str) {
  // Вы можете вставлять сюда различные реализации функции,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
	if (str.empty())
		return true;

	string input = str;
	//transform(input.begin(), input.end(), input.begin(), ::tolower);
	if (input[0] == input[input.length() - 1])
		return true;
	else
		return false;
}

void TestPredefined() {
	AssertEqual(IsPalindrom("medam"), false);
	AssertEqual(IsPalindrom("madam"), true);
	AssertEqual(IsPalindrom("olala"), false);
	AssertEqual(IsPalindrom("lol"), true);
	AssertEqual(IsPalindrom(""), true);
	AssertEqual(IsPalindrom("1"), true);
	AssertEqual(IsPalindrom(" "), true);
	AssertEqual(IsPalindrom(" 121"), false);
	AssertEqual(IsPalindrom("Lol"), false);
	AssertEqual(IsPalindrom("777777"), true);
	AssertEqual(IsPalindrom("777778"), false);
	
}

int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
  runner.RunTest(TestPredefined, "TestPredefined");

  return 0;
}

