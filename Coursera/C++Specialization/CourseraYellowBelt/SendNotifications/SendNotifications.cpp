// SendNotifications.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

void SendSms(const string& number, const string& message) {
	cout << "Send '" << message << "' to number " << number << endl;
}

void SendEmail(const string& email, const string& message) {
	cout << "Send '" << message << "' to e-mail " << email << endl;
}

/*
 Реализуйте здесь классы INotifier, SmsNotifier, EmailNotifier
 */

struct INotifier
{
	virtual void Notify(const string& message) const = 0;
};

struct SmsNotifier :  public INotifier
{
	SmsNotifier(const string& phone_number) : phone_number_(phone_number){}

	void Notify(const string& message) const override
	{
		SendSms(phone_number_, message);
	}

private:
	string phone_number_;
};

struct EmailNotifier : public INotifier
{
	EmailNotifier(const string& email_addess) : email_address_(email_addess){}

	void Notify(const string& message) const override
	{
		SendEmail(email_address_, message);
	}
	
private:
	string email_address_;
};

void Notify(INotifier& notifier, const string& message) {
	notifier.Notify(message);
}


int main() {
	SmsNotifier sms{ "+7-495-777-77-77" };
	EmailNotifier email{ "na-derevnyu@dedushke.ru" };

	Notify(sms, "I have White belt in C++");
	Notify(email, "And want a Yellow one");
	return 0;
}
