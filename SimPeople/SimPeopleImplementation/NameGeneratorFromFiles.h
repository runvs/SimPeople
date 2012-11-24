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

#ifndef NAMEGENERATORFROMFILES_H_12345
#define NAMEGENERATORFROMFILES_H_12345

#include <string>
#include <vector>
#include <boost/random/mersenne_twister.hpp>
#include "../SimPeopleLibrary/INameGenerator.h"
namespace SimPeople
{
/// This implementation of the NameGenerator Interface loads some Names from a file on the disc.
/// The File can be specified with the path
/// All Names are loaded from the File and then stored in a container so IO is minimized
class NameGeneratorFromFiles :
	public SimPeople::INameGenerator
{
public:
	/// ctor
	NameGeneratorFromFiles(void);

	/// cctor
	NameGeneratorFromFiles( volatile const NameGeneratorFromFiles& other ) {};
	/// dtor
	~NameGeneratorFromFiles(void);

	/// This Method loads the Names from the File specified in strNameFilePath and pushes them to m_vecFirstNames
	/// \sa m_vecFirstNames
	void LoadNamesFromFiles ( std::string strNameFilePath = "names.txt");

protected:
	/// Implementation of the parents class method
	virtual std::string DoGetName();

private:
	/// This vector stores the Names from the files
	std::vector<std::string> m_vecFirstNames;

	boost::random::mt19937 gen;		// rn generation must be encapsulated in a special object
	int GetRandomInt(int min, int max);

};

}
#endif
