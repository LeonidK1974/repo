// print_values.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "test_runner.h"

#include <ostream>

using namespace std;

#define PRINT_VALUES(out, x, y)  out << (x) << endl << (y) << endl			


int main() {
	TestRunner tr;
	ostringstream output;
	if (true)
		PRINT_VALUES(output, 5, "red belt");
	else
		PRINT_VALUES(output, 6, "red belt");
		
	
	tr.RunTest([] {
		ostringstream output;
		PRINT_VALUES(output, 5, "red belt");
		ASSERT_EQUAL(output.str(), "5\nred belt\n");
		}, "PRINT_VALUES usage example");
}

