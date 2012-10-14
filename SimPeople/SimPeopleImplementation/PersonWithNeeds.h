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

#ifndef SIMPEOPLEIMPLEMENTATION_PERSONWITHNEEDS_H
#define SIMPEOPLEIMPLEMENTATION_PERSONWITHNEEDS_H

#include "../SimPeopleLibrary/Person.h"
#include "BasicNeedPersonCommand.h"

namespace SimPeople
{
	/// this is the first exampe implementation of a Person with Basic Needs. It is as simple as this
class PersonWithNeeds :
	public Person,
	public BasicNeedPersonCommand
{
public:
	/// ctor
	PersonWithNeeds(void);
	/// dtor
	~PersonWithNeeds(void);

	// just some Action Strings

	void DoActionGetFood(void);
	void DoActionStarve(void);
	void DoActionSleep(void);
	void DoActionCollapse(void);
	void DoActionShit(void);


};

}

#endif