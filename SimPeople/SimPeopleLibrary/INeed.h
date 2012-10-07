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

#ifndef SIMPEOPLELIBRARY_INEED_H
#define SIMPEOPLELIBRARY_INEED_H

#include <string>
#include <map>
#include <vector>

namespace SimPeople
{
	// fwd decls
class ITimeDependence;

/// This is the basic Class for Needs. Though it is titled an interface it can be instantiated
class INeed
{
public:
	/// ctor, create a Need with the passed Name
	INeed(const std::string& strNeedName);
	
	/// dtor (virtual for inheritance)
	virtual ~INeed(void);

	/// The Update Method
	/// Uses the TimeDependance of the Need, sets the completion Values and checks for changes
	void Update ( float fTimeIncrement );

	/// Getter for the Need's name
	inline std::string GetName  ( void ) const {return m_strName;};

	/// Setter for the TimeDependance
	void SetTimeDependence ( ITimeDependence* pTimeDependence );

	/// This Method returns the Completion of the Need (must be in [0, 1] intervall)
	inline float GetCompletion (void) const {return m_fCompletion; };

	/// This Method changes the Completion by the passed Value. A check for a valid Completion Range is done [0, 1].
	inline void ChangeCompletion (float fCompletionChange) {m_fCompletion += fCompletionChange; CheckCompletion();};

	/// This Method returns the List of Actions that arose from the change of Completion
	inline std::vector<std::string>& const GetActionList (void) { return m_vecListOfActions;};

	/// This Method clears the ActionList so for the next frame there won't be any more actions to be done
	inline void ClearActionList(void) {m_vecListOfActions.clear();};

	/// This Method adds an Action String to a specific completion Value
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

#endif