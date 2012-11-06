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

#include "PersonWithNeeds.h"
#include "../SimPeopleLibrary/NeedManager.h"
namespace SimPeople
{
PersonWithNeeds::PersonWithNeeds(void) :
	BasicNeedPersonCommand((new IPersonCommand()))
{
	m_strName = "Paul";
	PersonWithNeeds::m_pNeedManager = new NeedManager(this);
}


PersonWithNeeds::~PersonWithNeeds(void)
{
}

void PersonWithNeeds::DoActionGetFood(void)
{
	std::cout << m_strName << " is getting food" << std::endl;
	PersonWithNeeds::GetNeedManager()->ChangeNeedCompletion("FoodNeed", 1);	// just assume foodneed is completely satisfied
};

void PersonWithNeeds::DoActionStarve(void)
{
	std::cout << m_strName << " starves" << std::endl;
};

void PersonWithNeeds::DoActionSleep(void)
{
	std::cout << m_strName << " is getting some sleep" << std::endl;
	PersonWithNeeds::GetNeedManager()->ChangeNeedCompletion("SleepNeed", 1);	// just assume sleepneed is completely satisfied

};

void PersonWithNeeds::DoActionCollapse(void)
{
	std::cout << m_strName <<  " collapses" << std::endl;
};

void PersonWithNeeds::DoActionShit(void)
{
	std::cout << m_strName <<  " is going For a shit" << std::endl;
	PersonWithNeeds::GetNeedManager()->ChangeNeedCompletion("ShitNeed", 1);	// just assume shitneed is completely satisfied
};



}