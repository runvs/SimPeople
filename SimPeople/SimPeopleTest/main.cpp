
#include <iostream>
#include "INeedTests.h"
#include "NeedManagerTests.h"
#include "PersonTest.h"
#include <fstream>

using namespace SimPeopleTest;

int main ()
{
	std::ofstream ostr;
	ostr.open("TestResults.log");

	ostr << "Testing INeed" << std::endl;
	INeedTest MyNeedTest;
	MyNeedTest.RunTests();

	ostr << "Testing NeedManager" << std::endl;
	NeedManagerTest MyNeedManagerTest;
	MyNeedManagerTest.RunTests();

	ostr << "Testing Person" << std::endl;
	PersonTest MyPersonTest;
	MyPersonTest.RunTests();

	ostr << "-- Tests are fine" << std::endl;
	ostr.close ();
	std::cout << "Tests are fine" << std::endl;



	return 0;
}