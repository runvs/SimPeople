
#include <iostream>
#include "INeedTests.h"


using namespace SimPeopleTest;

int main ()
{
	INeedTest MyNeedTest;

	MyNeedTest.RunTests();
	std::cout << "Tests are fine" << std::endl;
	return 0;
}