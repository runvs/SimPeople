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

#ifndef INAMEGENERATOR_H_12345
#define INAMEGENERATOR_H_12345

#include <string>

namespace SimPeople
{
	/// this is the name generator interface. Use this to derive classes which create names
	/// HowTo: The derived class implements the (here) pure virtual method DoGetName which is not acessible to the outside of the class.
	/// The caller (who uses the interface) just calls the GetName Method from the interface which does some postchecks on the names.
class INameGenerator
{
public:
	/// default ctor
	INameGenerator(void);

	/// cctor
	INameGenerator( volatile const INameGenerator& other ) {};

	/// default dtor (virtual for inheritance reasons)
	virtual ~INameGenerator(void);

	/// This Method returns a valid (post checks) Name for a person
	std::string GetName ();

protected:
	/// Implement this Method in the underlying implementation (aka the derived class)
	virtual std::string DoGetName() = 0;
};

}

#endif
