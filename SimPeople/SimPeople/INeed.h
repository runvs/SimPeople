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

#pragma once

#include <string>
#include <map>
#include <vector>

namespace SimPeople
{
class ITimeDependence;

class INeed
{
public:
	INeed(std::string strNeedName);
	virtual ~INeed(void);
	void Update ( float fTimeIncrement );

	inline std::string GetName  ( void ) const {return m_strName;};
	void SetTimeDependence ( ITimeDependence* pTimeDependence );

	inline float GetCompletion (void) const {return m_fCompletion; };

	inline void ChangeCompletion (float fCompletionChange) {m_fCompletion += fCompletionChange; CheckCompletion();};

	inline std::vector<std::string>& const GetActionList (void) { return m_vecListOfActions;};

	inline void ClearActionList(void) {m_vecListOfActions.clear();};

	void AddAction (float fCompletionValue, std::string strAction);

private:

	void CheckCompletion();

	float m_fCompletion;
	float m_fOldCompletion;
	std::string m_strName;
	std::map<float, std::string> m_mapCompletionActionList;
	std::vector<std::string> m_vecListOfActions;

	ITimeDependence* m_TimeDependece;
};

}