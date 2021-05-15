// expp.cpp : Defines the entry point for the application.
//

#include "expp.h"

#include <fstream>

int main()
{
	std::cout << "Hello CMake." << std::endl;

	std::ofstream testResults("expp.testresult");
	if (testResults.is_open())
	{
		testResults << "Dummy;Passed\n";
		testResults.close();
	}

	return 0;
}
