// phone_numbers.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include "phone_number.h"

int main()
{
	vector<PhoneNumber> my_contacts;
	
	try
	{
		const PhoneNumber num{ "+7-495-7220102" };
		my_contacts.push_back(num);
		const PhoneNumber num2{ "+7-495-111-22-33" };
		my_contacts.push_back(num2);
		const PhoneNumber num3{ "+1-2-coursera-cpp" };
		my_contacts.push_back(num3);
		const PhoneNumber num4{ "1 - 2 - 333" };
		my_contacts.push_back(num4);
		const PhoneNumber num5{ "+7 - 1233" };
		my_contacts.push_back(num5);
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	for (const auto& number : my_contacts)
	{
		cout << number.GetCountryCode() << endl;
		cout << number.GetCityCode() << endl;
		cout << number.GetLocalNumber() << endl;
		cout << number.GetInternationalNumber() << endl;
	}
	
	
}
