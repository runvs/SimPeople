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

#include "NeedManager.h"
#include "INeed.h"
#include "IPersonCommand.h"
#include "SimPeopleExceptions.h"

namespace SimPeople
{
NeedManager::NeedManager(IPersonCommand* pPersonCommand)
{
	NeedManager::SetPersonCommandInterface(pPersonCommand);
	NeedManager::m_fNeedsTimingFactor = 1;
}

NeedManager::NeedManager(void)
{
	NeedManager::m_fNeedsTimingFactor = 1;
}


NeedManager::~NeedManager(void)
{
	NeedManager::m_mapPriorityNeedsMap.clear();
}


void NeedManager::SetPersonCommandInterface ( IPersonCommand* pPersonCommand)
{
	if ( pPersonCommand == NULL )
	{
		throw Exceptions::NullPointerError();
	}

	m_PersonCommand = pPersonCommand;
}

void NeedManager::CheckNeeds(void)
{
	if ( m_PersonCommand == NULL)
	{
		throw Exceptions::NullPointerError();
	}
	boost::ptr_map<int, INeed>::iterator t_it;

	for (	t_it = NeedManager::m_mapPriorityNeedsMap.begin();
			t_it != NeedManager::m_mapPriorityNeedsMap.end();
			++t_it)	// iterate over all Needs
	{
		while (!(t_it->second->GetActionList().empty()))
		{
			// TODO Priority Checking
			m_PersonCommand->DoAction(t_it->second->GetActionList().back());		// Do the Action
			t_it->second->GetActionList().pop_back();								// Delete the last element in the cue
		}
		
		t_it->second->ClearActionList();	// just make sure there are no action strings left
	}
}

void NeedManager::UpdateNeeds(float fTimeIncrement )
{
	// this is the actual timing increment for updating the Needs since there might be a change in the Timing Factor
	float t_fUpdateTimeIncrement = fTimeIncrement * NeedManager::m_fNeedsTimingFactor;	

	boost::ptr_map<int, INeed>::iterator t_it;
	// loop over all Needs
	for (	t_it = NeedManager::m_mapPriorityNeedsMap.begin();
			t_it != NeedManager::m_mapPriorityNeedsMap.end();
			++t_it)
	{
		t_it->second->Update(t_fUpdateTimeIncrement);
	}
}


void NeedManager::ChangeNeedCompletion(std::string strNeedName, float fChange)
{
	if ( !NeedManager::ContainsNeed(strNeedName))
	{
		throw Exceptions::UnkownStringError(strNeedName);
	}

	NeedManager::GetNeedByName(strNeedName)->ChangeCompletion(fChange);
}


void NeedManager::AddNeed(INeed* pNeed, int iPriority)
{
	if (pNeed == NULL)
	{
		throw Exceptions::NullPointerError();
	}
	if (iPriority < 0)
	{
		throw Exceptions::ArgumentError();
	}

	if (NeedManager::ContainsNeed(pNeed))
	{
		throw Exceptions::DistinctError();
	}
	if (NeedManager::ContainsPriotity(iPriority))
	{
		throw Exceptions::DistinctError();
	}

	NeedManager::m_mapPriorityNeedsMap.insert(iPriority, pNeed);

}

void NeedManager::Update( float fTimeIncrement )
{
	NeedManager::UpdateNeeds(fTimeIncrement);
	NeedManager::CheckNeeds();
}

bool NeedManager::ContainsNeed ( INeed* pNeed) const
{
	return NeedManager::ContainsNeed(pNeed->GetName());
}

bool NeedManager::ContainsNeed ( std::string strNeedName ) const
{
			boost::ptr_map<int, INeed>::const_iterator t_cit;
	for (	t_cit = NeedManager::m_mapPriorityNeedsMap.begin();
			t_cit != NeedManager::m_mapPriorityNeedsMap.end();
			++t_cit)
	{
		if ( t_cit->second->GetName() == strNeedName)
		{
			return true;
		}
	}
	return false;
}

INeed* NeedManager::GetNeedByName (std::string strNeedName)
{
	if ( !NeedManager::ContainsNeed(strNeedName))
	{
		throw Exceptions::UnkownStringError(strNeedName);
	}

	boost::ptr_map<int, INeed>::iterator t_it;
	for (	t_it = NeedManager::m_mapPriorityNeedsMap.begin();
			t_it != NeedManager::m_mapPriorityNeedsMap.end();
			++t_it)
	{
		if ( t_it->second->GetName() == strNeedName)
		{
			return t_it->second;
		}
	}

	throw Exceptions::UnkownStringError(strNeedName);
}


bool NeedManager::ContainsPriotity ( int iPriority) const
{
	if (NeedManager::m_mapPriorityNeedsMap.find(iPriority) == NeedManager::m_mapPriorityNeedsMap.end())
	{
		return false;
	}
	return true;
}

}