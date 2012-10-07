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


#include "INeed.h"
#include "ITimeDependence.h"
#include "SimPeopleExceptions.h"

namespace SimPeople
{
INeed::INeed(const std::string&  strNeedName)
{
	m_strName = strNeedName;
	m_fCompletion = 1.0;
	m_fOldCompletion = 1.0;
	INeed::m_TimeDependece = NULL;

}


INeed::~INeed(void)
{
	m_vecListOfActions.clear();
	m_mapCompletionActionList.clear();
	if ( INeed::m_TimeDependece != NULL)
	{
		delete INeed::m_TimeDependece;
	}
}




void INeed::Update ( float fTimeIncrement )
{
	if ( m_TimeDependece == NULL )
	{
		throw Exceptions::NullPointerError();
	}
	INeed::m_fOldCompletion = INeed::m_fCompletion;
	INeed::m_TimeDependece->UpdateValue(INeed::m_fCompletion, fTimeIncrement);
	INeed::CheckCompletion();
}


void INeed::SetTimeDependence ( ITimeDependence* pTimeDependence )
{
	if (pTimeDependence == NULL )
	{
		throw Exceptions::NullPointerError();
	}

	INeed::m_TimeDependece = pTimeDependence;
}


void INeed::AddAction (float fCompletionValue, std::string strAction)
{
	if ( fCompletionValue < 0.0 || fCompletionValue > 1.0 )
	{
		throw SimPeople::Exceptions::CompletionError();
	}
	if ( strAction == "")
	{
		throw SimPeople::Exceptions::UnkownStringError("");
	}
	std::pair<float, std::string> t_pairNewPair(fCompletionValue, strAction);
	m_mapCompletionActionList.insert(t_pairNewPair);
}


void INeed::CheckCompletion()
{
	std::map<float, std::string>::const_iterator t_cit;

	for (	t_cit = INeed::m_mapCompletionActionList.begin();
			t_cit != INeed::m_mapCompletionActionList.end();
			++t_cit)
	{
		if (INeed::m_fCompletion <= t_cit->first)
		{		// actual value is below the threshold
			if (INeed::m_fOldCompletion > t_cit->first)
			{		// But old value is greater (so we just passed the threshold)
				INeed::m_vecListOfActions.push_back(t_cit->second);
			}
		}
	}

	if ( INeed::m_fCompletion < 0.0f )
	{
		INeed::m_fCompletion = 0.0f;
	}
	else if ( INeed::m_fCompletion > 1.0f )
	{
		INeed::m_fCompletion = 1.0f;
	}
}

}