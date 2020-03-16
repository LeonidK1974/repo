// phone_numbers.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "phone_number.h"

int main()
{
	const PhoneNumber num{"+7-495-7220102"};
	cout << num.GetCountryCode() << endl;
	cout << num.GetCityCode() << endl;
	cout << num.GetLocalNumber() << endl;
	cout << num.GetInternationalNumber() << endl;
	const PhoneNumber num2{ "+7-495-111-22-33" };
	cout << num.GetCountryCode() << endl;
	cout << num.GetCityCode() << endl;
	cout << num.GetLocalNumber() << endl;
	cout << num.GetInternationalNumber() << endl;
	const PhoneNumber num3{ "+1-2-coursera-cpp" };
	cout << num.GetCountryCode() << endl;
	cout << num.GetCityCode() << endl;
	cout << num.GetLocalNumber() << endl;
	cout << num.GetInternationalNumber() << endl;
	const PhoneNumber num4{ "1 - 2 - 333" };
	cout << num.GetCountryCode() << endl;
	cout << num.GetCityCode() << endl;
	cout << num.GetLocalNumber() << endl;
	cout << num.GetInternationalNumber() << endl;
	const PhoneNumber num5{ "+7 - 1233" };
	cout << num.GetCountryCode() << endl;
	cout << num.GetCityCode() << endl;
	cout << num.GetLocalNumber() << endl;
	cout << num.GetInternationalNumber() << endl;

}
