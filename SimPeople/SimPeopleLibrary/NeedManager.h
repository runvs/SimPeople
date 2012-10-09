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

#ifndef SIMPEOPLELIBRARY_NEEDMANAGER_H
#define SIMPEOPLELIBRARY_NEEDMANAGER_H

#include <boost/ptr_container/ptr_map.hpp>


namespace SimPeople
{
	// fwd decls
class INeed;
class IPersonCommand;

/// This Class manages multiple Needs and is used as an encapsulation
class NeedManager
{
public:

	/// ctor
	NeedManager(void);

	/// ctor with specific CommandInterface
	NeedManager(IPersonCommand* pPersonCommand);

	/// dtor
	~NeedManager(void);

	/// Setter for the PersonCommandInterface
	void SetPersonCommandInterface ( IPersonCommand* PersonCommand);

	/// This Method pics a Need by a String and changes its Completion
	void ChangeNeedCompletion(std::string strNeedName, float fChange);

	/// This Method Adds a Need to the NeedManager
	void AddNeed(INeed* pNeed, int iPriority);

	/// This Method Updated all Needs
	void Update ( float fTimeIncrement );

private:
	boost::ptr_map<int, INeed> m_mapPriorityNeedsMap;

	/// This Method Checks All needs
	/// It gets the Actions from the Needs list and handles them to the CommandInterface
	void CheckNeeds(void);
	
	/// This Method updates the Timing of the Needs and thus sets the local Actionlists in the strings
	void UpdateNeeds(float fTimeIncrement );

	IPersonCommand* m_PersonCommand;

	/// Check if a Need is present in the NeedManager
	bool ContainsNeed ( INeed* pNeed) const;

	/// Check if a Need is present in the NeedManager
	bool ContainsNeed ( std::string strNeedName ) const;

	/// Check if a special Priority is already used by this NeedManager
	bool ContainsPriotity ( int iPriority) const;

	/// Get a Need by its String (as a Pointer). Should be used Rarely
	INeed* GetNeedByName (std::string strNeedName);
};

}

#endif