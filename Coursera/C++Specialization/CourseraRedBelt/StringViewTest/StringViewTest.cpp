// StringViewTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <string_view>
#include <sstream>
#include <algorithm>

using namespace std;

void print(string_view v)
{
	// note: do not expect a null terminated string
	const auto words_begin(v.find_first_not_of(" \t\n"));
	v.remove_prefix(min(words_begin, v.size()));

	const auto words_end(v.find_last_not_of(" \t\n"));

	if (words_end != string_view::npos) {
		v.remove_suffix(v.size() - words_end - 1);
	}

	cout << "length: " << v.length()
		<< " [" << v << "]\n";
}

string ConcatenateStringViews(
	string_view lhs, string_view rhs) {
	string s;
	s.reserve(lhs.size() + rhs.size());
	return (s += lhs) += rhs;
}

int main(int argc, char *argv[])
{
    std::cout << "Hello string_view class!\n";

	string a{ "a" };
	auto   b("b"s);

	string_view c{ "c" };
	string_view d("d"sv);

	cout << a << ", " << b << '\n';
	cout << c << ", " << d << '\n';

	cout << ConcatenateStringViews(c, d);

	cout << a + b << '\n';
	cout << a + string{ c } << '\n';

	ostringstream o;

	o << a << " " << b << " " << c << " " << d;
	auto concatenated(o.str());

	cout << concatenated << '\n';

	transform(begin(concatenated), end(concatenated), begin(concatenated), ::toupper);
	cout << concatenated << '\n';

	print(argv[0]);
	print({});
	print("a const char * array");
	print("an std::string_view literal"sv);
	print("an std::string instance"s);

	print("   \t\n foobar  \n  \t ");

	char cstr[]{ 'a', 'b', 'c' }; // no null termination
	print(string_view(cstr, sizeof(cstr)));
}


