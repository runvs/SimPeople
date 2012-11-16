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

#ifndef SIMPEOPLELIBRARY_PERSON_H
#define SIMPEOPLELIBRARY_PERSON_H

#include <string>


namespace SimPeople
{

class NeedManager;
class INeed;

/// Class for a basic Person. Overwrite for special purposes
/// This class is not intended to be used since it does not derive from a PersonCommandInterface and thus can not do any cool stuff
class Person
{
public:

	/// ctor
	Person();

	/// dtor
	virtual ~Person(void);

	/// This Method Updates all the necessary Parts of the Person
	void Update ( float fTimeIncrement );

	/// This Methos Adds a Need to the Person
	void AddNeed (INeed* pNeed, int priority);

	/// Setter for the Name of the Person
	inline void SetName (std::string strNewName) { m_strName = strNewName; };

protected:

	/// global satisfaction Value
	int m_iSatisfaction;

	/// the person's name
	std::string m_strName;

	/// Getter fpr the NeedManager
	inline NeedManager* GetNeedManager() {return m_pNeedManager;};

	/// the NeedManager
	NeedManager* m_pNeedManager;

	/// Slow down Need Timing (eg. if person is going to sleep all other needs will be decreasing slower)
	void SlowDownNeedTiming(const float fFactor);

	/// Reset the Need Timing (eg. the Person wakes up again)
	void ResetNeedTiming(void);


};

}

#endif
