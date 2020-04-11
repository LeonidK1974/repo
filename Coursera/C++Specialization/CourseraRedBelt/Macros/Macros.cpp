// Macros.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

#define WITH_SHARP(x) #x

int main() {
	string variable = "value";
	cout << WITH_SHARP(variable);
}

