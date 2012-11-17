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
#include <boost/ptr_container/ptr_vector.hpp>
#include <exception>
#include "../SimPeopleImplementation/PersonFactory.h"
#include "../SimPeopleLibrary/Person.h"
#include <iostream>


using namespace SimPeople;

void DoUpdate ( boost::ptr_vector<Person>& vecPersons, float fTimeIncrement )
{
	boost::ptr_vector<Person>::iterator it;
	for (it = vecPersons.begin(); it != vecPersons.end(); ++it)
	{
		it->Update(fTimeIncrement);
	}
}



int  main(int argc, char** argv)
{
	// create the person Factory
	PersonFactory* t_PersonFactory = NULL;
	
	// try creating a PersonFactory
	try
	{
		t_PersonFactory = new SimPeople::PersonFactory();
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
		// if this fails, exit straight away
		exit(1);
	}

	// a Persons Pointer to store new Persons in it
	Person* t_pPerson = NULL;

	// a Boost Container for storing Persons.
	boost::ptr_vector<Person> g_vecPersons;

	for (int i = 0; i < 5; ++i)	// create some Persons
	{
		try
		{
			t_pPerson = t_PersonFactory->CreatePersonWithBasicNeeds();
			g_vecPersons.push_back(t_pPerson);
		}
		catch (std::exception ex)
		{
			std::cout << ex.what() << std::endl;
		}
	}



	float g_fTimeMax = 10.0f;
	float g_fTimeIncrement = 0.01f;
	float g_fTimeNow = 0.0f;

	// Update Time and let it run for some Time
	try 
	{
		for (g_fTimeNow = 0.0f; g_fTimeNow < g_fTimeMax; g_fTimeNow += g_fTimeIncrement)
		{
			DoUpdate(g_vecPersons, g_fTimeIncrement);
		}
	}
	catch ( std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}

	// just wait for the user to press a key
	char a;
	std::cin >> a;

	return 0;
}
