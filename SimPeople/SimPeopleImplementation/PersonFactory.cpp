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
#include<boost/random/uniform_real.hpp>
#include<boost/random/variate_generator.hpp>

#include "../SimPeopleLibrary/INeed.h"
#include "../SimPeopleLibrary/TimeDependenceLinear.h"

#include "PersonFactory.h"
#include "PersonWithNeeds.h"

//#include "NameGeneratorHardCoded.h";
#include "NameGeneratorFromFiles.h"


namespace SimPeople
{


PersonFactory::PersonFactory(void)
{
	// replace this for any specific name Generator
	PersonFactory::m_pNameGenerator = new NameGeneratorFromFiles();
	try
	{
		dynamic_cast<SimPeople::NameGeneratorFromFiles*>(m_pNameGenerator)->LoadNamesFromFiles();
	}
	catch ( SimPeople::Exceptions::IOError)
	{
		// add some more Data
		throw;
	}

}


PersonFactory::~PersonFactory(void)
{
	if (PersonFactory::m_pNameGenerator != NULL)
	{
		delete PersonFactory::m_pNameGenerator;
	}
}

Person* PersonFactory::CreatePersonWithBasicNeeds ( void )
{
	Person* pPerson = new PersonWithNeeds();
	pPerson->SetName(m_pNameGenerator->GetName());
	AddBasicNeeds(pPerson);

	return pPerson;

}

float PersonFactory::GetRandomFloat(float min, float max)
{
    boost::uniform_real<float> distribution(min, max);
    boost::variate_generator<boost::mt19937&, boost::uniform_real<float> > RNG(gen, distribution);
    return RNG();
}


void PersonFactory::AddBasicNeeds( Person* pPerson)
{
	INeed* t_pNeed = new INeed("SleepNeed");
	float t_fSleepThreshold = 0.33f + GetRandomFloat(-0.05f, 0.05f);
	t_pNeed->AddAction(t_fSleepThreshold, "sleep");
	t_pNeed->AddAction(0.01f, "collapse");
	TimeDependenceLinear* t_pTimeDependance = new TimeDependenceLinear();
	float t_fSleepSlope = -0.623f + GetRandomFloat(-0.1f, 0.1f);
	t_pTimeDependance->SetSlope(t_fSleepSlope);
	t_pNeed->SetTimeDependence(t_pTimeDependance);
	pPerson->AddNeed(t_pNeed, 12);

	t_pNeed = new INeed("FoodNeed");
	float t_fFoodThreshold = 0.6f + GetRandomFloat(-0.1f, 0.1f);
	t_pNeed->AddAction(t_fFoodThreshold, "getfood");
	t_pNeed->AddAction(0.1f, "starve");
	t_pNeed->SetTimeDependence(new TimeDependenceLinear());
	t_pTimeDependance = new TimeDependenceLinear();
	float t_fFooldSlope = -0.43f + GetRandomFloat(-0.2f, 0.2f);
	t_pTimeDependance->SetSlope(t_fFooldSlope);
	t_pNeed->SetTimeDependence(t_pTimeDependance);
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
