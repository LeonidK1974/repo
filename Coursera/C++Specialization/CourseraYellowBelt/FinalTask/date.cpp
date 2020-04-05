#include "date.h"
#include <iomanip>
#include <tuple>

using namespace std;

int Date::GetYear() const
{
	return year_;
};

int Date::GetMonth() const
{
	return month_;
};

int Date::GetDay() const
{
	return day_;
};

string Date::date2str() const
{
	ostringstream ost;
	ost << setw(4) << setfill('0') << year_ << '-'
		<< setw(2) << month_ << '-' << setw(2) << day_;
	return ost.str();
}

bool operator<(const Date& lhs, const Date& rhs)
{
	return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) < make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}
bool operator<=(const Date& lhs, const Date& rhs)
{
	return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) <= make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}
bool operator==(const Date& lhs, const Date& rhs)
{
	return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) == make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}
bool operator!=(const Date& lhs, const Date& rhs)
{
	return !(lhs == rhs);
}
bool operator>(const Date& lhs, const Date& rhs)
{
	return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) > make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}
bool operator>=(const Date& lhs, const Date& rhs)
{
	return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) >= make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

ostream& operator<<(ostream& stream, const Date& date) {
	stream << setfill('0');
	stream << setw(4) << date.GetYear() << '-'
		<< setw(2) << date.GetMonth() << '-'
		<< setw(2) << date.GetDay();
	return stream;
}

Date ParseDate(istream& date_stream) {
	bool ok = true;

	int year;
	ok = ok && (date_stream >> year);
	ok = ok && (date_stream.peek() == '-');
	date_stream.ignore(1);

	int month;
	ok = ok && (date_stream >> month);
	ok = ok && (date_stream.peek() == '-');
	date_stream.ignore(1);

	int day;
	ok = ok && (date_stream >> day);
	//ok = ok && date_stream.eof();

	if (!ok) {
		throw logic_error("Wrong date format");
	}
	return Date(year, month, day);
}