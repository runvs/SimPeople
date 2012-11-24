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

#ifndef NAMEGENERATORHARDCODED_H_12345
#define NAMEGENERATORHARDCODED_H_12345
#include "../SimPeopleLibrary/INameGenerator.h"

namespace SimPeople
{
/// This implementation of the NameGenerator Interface has some hard coded names that will be chosen linar.
/// If the names are depleted the list is started from the beginning with appending Numbers to the names
class NameGeneratorHardCoded :
	public INameGenerator
{
public:
	/// ctor
	NameGeneratorHardCoded(void);

	/// cctor
	NameGeneratorHardCoded( volatile const NameGeneratorHardCoded& other ) {};

	/// dtor
	~NameGeneratorHardCoded(void);
protected:
	/// this Method does the work for creating the names
	std::string DoGetName();

private:
	/// This variable is used for counting through the list
	unsigned int m_uiNameCounter;
};
}
#endif
