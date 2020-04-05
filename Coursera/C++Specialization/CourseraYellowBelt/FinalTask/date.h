#pragma once
#include <string>
#include <sstream>

class Date {
public:
	Date(int new_year, int new_month, int new_day) : day_(new_day), month_(new_month), year_(new_year){
	}

	int GetYear() const;

	int GetMonth() const;

	int GetDay() const;
	
	std::string date2str() const;
	
private:
	int day_;
	int month_;
	int year_;
};

bool operator<(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);

std::ostream& operator<<(std::ostream& stream, const Date& date);

Date ParseDate(std::istream& s);