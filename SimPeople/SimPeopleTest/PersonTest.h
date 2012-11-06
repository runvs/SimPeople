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

#include "stdafx.h"

#include "../SimPeopleLibrary/Person.h"
#include "../SimPeopleLibrary/INeed.h"
#include "../SimPeopleLibrary/SimPeopleExceptions.h"
#include "../SimPeopleImplementation/BasicNeedPersonCommand.h"
#include "../SimPeopleLibrary/TimeDependenceLinear.h"

using namespace SimPeople;

namespace SimPeopleTest
{		
	class PersonTest
	{
	public:
		void RunTests ()
		{
			std::cout << "TestConstructor" << std::endl;
			PersonConstructorTest();
			std::cout << "TestUpdate" << std::endl;
			PersonUpdateTest();
		}

	private:
		void PersonConstructorTest()
		{
			Person* t_pPerson = NULL;
			t_pPerson = new Person();
			delete t_pPerson;
		}

		void PersonUpdateTest()
		{
			Person* t_pPerson = new Person();
			try
			{
				t_pPerson->Update(1.0f);
			}
			catch (SimPeople::Exceptions::NullPointerError)
			{
				delete t_pPerson;
				abort;
			}
			catch (...)
			{
				delete t_pPerson;
				abort;
			}
			abort;
		}

	};
}