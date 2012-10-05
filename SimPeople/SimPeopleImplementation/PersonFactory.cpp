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

#include <boost/lexical_cast.hpp>

#include "PersonFactory.h"
#include "PersonWithNeeds.h"
#include "../SimPeopleLibrary/INeed.h"
#include "../SimPeopleLibrary/TimeDependenceLinear.h"


namespace SimPeople
{

unsigned int PersonFactory::m_uiNameCounter = 0;
PersonFactory::PersonFactory(void)
{
}


PersonFactory::~PersonFactory(void)
{
}

Person* PersonFactory::CreatePersonWithBasicNeeds ( void )
{
	Person* pPerson = new PersonWithNeeds();
	pPerson->SetName(CreateRandomName());
	AddNeeds(pPerson);

	return pPerson;

}


std::string PersonFactory::CreateRandomName(void)
{
	std::string t_strReturn = "";
	if (m_uiNameCounter%5 == 0 )
	{
		t_strReturn = "Paul";
	}
	else if (m_uiNameCounter%5 == 1 )
	{
		t_strReturn = "Gilbert";
	}
	else if (m_uiNameCounter%5 == 2 )
	{
		t_strReturn = "Jean";
	}
	else if (m_uiNameCounter%5 == 3 )
	{
		t_strReturn = "Linda";
	}
	else if (m_uiNameCounter%5 == 4 )
	{
		t_strReturn = "Julia";
	}

	if ( m_uiNameCounter > 5 )
	{
		t_strReturn += boost::lexical_cast<std::string>((m_uiNameCounter/5));
	}

	m_uiNameCounter++;
	return t_strReturn;
}


void PersonFactory::AddNeeds( Person* pPerson)
{
	INeed* t_pNeed = new INeed("SleepNeed");
	t_pNeed->AddAction(0.33f, "sleep");
	t_pNeed->AddAction(0.01f, "collapse");
	TimeDependenceLinear* t_pTimeDependance = new TimeDependenceLinear();
	t_pTimeDependance->SetSlope(-0.623f);
	t_pNeed->SetTimeDependence(t_pTimeDependance);
	pPerson->AddNeed(t_pNeed, 12);

	t_pNeed = new INeed("FoodNeed");
	t_pNeed->AddAction(0.6f, "getfood");
	t_pNeed->AddAction(0.2f, "starve");
	t_pNeed->SetTimeDependence(new TimeDependenceLinear());
	pPerson->AddNeed(t_pNeed, 15);

	t_pNeed = new INeed("ShitNeed");
	t_pNeed->AddAction(0.24f, "shit");
	t_pTimeDependance = new TimeDependenceLinear();
	t_pTimeDependance->SetSlope(-0.435f);
	t_pNeed->SetTimeDependence(t_pTimeDependance);
	t_pNeed->SetTimeDependence(new TimeDependenceLinear());
	pPerson->AddNeed(t_pNeed, 25);
}

}