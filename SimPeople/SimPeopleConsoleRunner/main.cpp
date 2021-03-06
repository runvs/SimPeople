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

#include "../SimPeople/Person.h"
#include "../SimPeople/INeed.h"
#include "../SimPeopleImplementation/BasicNeedPersonCommand.h"
#include "../SimPeople/TimeDependenceLinear.h"

#include <boost\ptr_container\ptr_vector.hpp>

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
	Person* t_pPerson = new Person(new BasicNeedPersonCommand(new IPersonCommand()));
	INeed* t_pNeed = new INeed("SleepNeed");
	t_pNeed->AddAction(0.5f, "sleep");
	t_pNeed->SetTimeDependence(new TimeDependenceLinear());
	t_pPerson->AddNeed(t_pNeed);
	
	boost::ptr_vector<Person> g_vecPersons;

	g_vecPersons.push_back(t_pPerson);


	float g_fTimeMax = 10.0f;
	float g_fTimeIncrement = 0.001f;
	float g_fTimeNow = 0.0f;
	for (g_fTimeNow = 0.0f; g_fTimeNow < g_fTimeMax; g_fTimeNow += g_fTimeIncrement)
	{
		DoUpdate(g_vecPersons, g_fTimeIncrement);
		//std::cout << "== TimeStep with Time " << g_fTimeNow << std::endl;
	}

	return 0;
}