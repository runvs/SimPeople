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

#ifndef SIMPEOPLEIMPLEMENTATION_PERSONFACTORY_H
#define SIMPEOPLEIMPLEMENTATION_PERSONFACTORY_H

#include <string>
#include <boost/random/mersenne_twister.hpp>


namespace SimPeople
{

	// fwd declarations
class Person;
class INameGenerator;

/// This class is there to create all kinds of different Persons
class PersonFactory
{
public:
	/// ctor
	PersonFactory(void);
	/// dtor
	~PersonFactory(void);

	/// \brief Use this Method to create a Person wit Basic Needs
	/// Since this is a factory, this Method calls new and the scope calling this method is responsible for freeing the data
	Person* CreatePersonWithBasicNeeds (void);


private:
	/// Pointer to a NameGenerator for the Persons to be created
	INameGenerator* m_pNameGenerator;

	/// This Method adds all basic Needs to a Person
	void AddBasicNeeds( Person* pPerson);

	boost::random::mt19937 gen;		// rn generation must be encapsulated in a special object
	float GetRandomFloat(float min, float max);
};

}

#endif
