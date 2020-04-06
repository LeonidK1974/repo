// LambdaPredicates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

int main() {

	/*std::string s = "xAAAyyByABCxGxZyIxGyyZI";

	std::cout << "Before: '" << s << "'" << std::endl;

	bool (*pred1)(char) = [](char c) { return c == 'x' || c == 'y'; };
	std::replace_if(s.begin(), s.end(), pred1, '*');
	std::cout << "1st tr: '" << s << "'" << std::endl;

	auto pred2 = [](char c) { return c == '*'; };
	std::replace_if(s.begin(), s.end(), pred2, '#');
	std::cout << "2nd tr: '" << s << "'" << std::endl*/;

	/*typedef std::tuple<std::string, int, std::string> TUPLE;
	std::map<int, TUPLE> m = {{1, {"string", 1 , "string"}} , { 2, {"string2", 2,  "string2"}},  { 3, {"some string", 2,  "string2"}} };

	auto predicate = [](const std::pair<int, TUPLE>& v) {
		return std::get<0>(v.second) == "some string";
	};*/

	//typedef std::pair<std::string, int> PAIR;
std::map<int, string> m = { {1, "string" } , { 2, "string2"}, { 3, "some string" }};

	auto predicate = [](const std::pair<int, string>& m) {
		return (m.first) > 1;
	};
	
	auto it = std::find_if(m.begin(), m.end(), predicate);
	
	return 0;
}
