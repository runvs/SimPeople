// DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
// Version 2, December 2004 

// Copyright (C) 2012 Sam Hocevar <sam@hocevar.net> 

// Everyone is permitted to copy and distribute verbatim or modified 
// copies of this license document, and changing it is allowed as long 
// as the name is changed. 

// DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
// TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION 

// 0. You just DO WHAT THE FUCK YOU WANT TO.

// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://sam.zoy.org/wtfpl/COPYING for more details. 

// This File is part of the SimPeople Project done by Julian Dinges and Simon Weis

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