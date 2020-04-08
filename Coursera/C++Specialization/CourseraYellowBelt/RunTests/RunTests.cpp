// RunTests.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "test_runner.h"

int main()
{
	int n = 1;
	AssertEqual(n, 2, "n =! 2");
	string s{ "test" };
	AssertEqual(s, "test", "string not \"test\"");
}


