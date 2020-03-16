#include "phone_number.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

PhoneNumber::PhoneNumber(const string &international_number) {
	istringstream is{ international_number };

	const char sign = is.get();
	getline(is, country_code_, '-');
	getline(is, city_code_, '-');
	getline(is, local_number_);
	if (sign != '+' || country_code_.empty() || city_code_.empty() || local_number_.empty())
	{
		throw invalid_argument("Phone number must begin with '+' symbol and contain 3 parts separated by '-' symbol: "  + international_number);
	}
}

string  PhoneNumber::GetCountryCode() const {
	return country_code_;
	
}
string  PhoneNumber::GetCityCode() const {
	return city_code_;
}

string  PhoneNumber::GetLocalNumber() const {
	return local_number_;
}

string  PhoneNumber::GetInternationalNumber() const {
	auto inter_number = "+" + GetCountryCode()
							+ "-" + GetCityCode()
							+ "-" + GetLocalNumber();
	
	return inter_number;
}