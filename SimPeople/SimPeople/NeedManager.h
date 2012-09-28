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

#include <boost\ptr_container\ptr_map.hpp>


namespace SimPeople
{
class INeed;
class IPersonCommand;

class NeedManager
{
public:
	NeedManager(void);
	NeedManager(IPersonCommand* pPersonCommand);
	~NeedManager(void);

	void SetPersonCommandInterface ( IPersonCommand* PersonCommand);

	void ChangeNeedCompletion(std::string strNeedName, float fChange);
	void AddNeed(INeed* pNeed, int iPriority);
	void Update ( float fTimeIncrement );

private:
	boost::ptr_map<int, INeed> m_mapPriorityNeedsMap;
	void CheckNeeds(void);
	void UpdateNeeds(float fTimeIncrement );

	IPersonCommand* m_PersonCommand;

	bool ContainsNeed ( INeed* pNeed) const;
	bool ContainsNeed ( std::string strNeedName ) const;
	bool ContainsPriotity ( int iPriority) const;
	INeed* GetNeedByName (std::string strNeedName);
};

}

#endif