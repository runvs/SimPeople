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

#include "INameGenerator.h"
#include "SimPeopleExceptions.h"

namespace SimPeople
{
INameGenerator::INameGenerator(void)
{
}


INameGenerator::~INameGenerator(void)
{
}

std::string INameGenerator::GetName ()
{
	// call the method
	std::string t_strName = DoGetName();

	// some basic postchecks
	if (t_strName.size() == 0)
	{
		throw SimPeople::Exceptions::UnkownStringError("t_strName");
	}

	// return the Name
	return t_strName;
}
}
