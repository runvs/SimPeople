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


#ifndef SIMPEOPLELIBRARY_IPERSONCOMMAND_H
#define SIMPEOPLELIBRARY_IPERSONCOMMAND_H

#include <string>
#include <vector>
#include <iostream>
#include "SimPeopleExceptions.h"

namespace SimPeople
{

	/// Fundamental CommandInterface Use this class as a pointer in any Case you want do push commands to the persons
class IPersonCommand
{
public:
	/// ctor
	IPersonCommand(void);

	/// cctor
	IPersonCommand( volatile const IPersonCommand& other ) {};

	/// dtor
	virtual ~IPersonCommand(void);

	// This Method does an Action if called with the correct string.
	// throws
	void DoAction(std::string strActionName);

	/// This Method searches and Performs an Action by a string. Needs to be overwritten for any new String
	virtual void SearchAndPerformAction(std::string strAction);
protected:
	/// Call this Method when the String has been Found and no more searches have to be done this time
	inline void TriggerStringHasBeenFound(void) {m_bStringHasBeenFound = true;};

private:
	bool m_bStringHasBeenFound;

	/// This Method checks if the ActionString has been found and executed. If not throws
	void CheckForActionFound(std::string strAction);
};


/// Decorator Pattern so the Command Interfaces can be used together. This is no trivial shit
class CommandInterfaceDecorator : public IPersonCommand
{
public:
	/// ctor
	CommandInterfaceDecorator(IPersonCommand* pCommandInterface)
	{
		if (pCommandInterface == NULL)
		{
			throw SimPeople::Exceptions::NullPointerError();
		}
		m_pMyCommandInterface = pCommandInterface;
	};

	/// dtor
	virtual ~CommandInterfaceDecorator()
	{
		if (m_pMyCommandInterface != NULL)
		{
			delete m_pMyCommandInterface;
		}
	}

	/// needs to be overwritten
	virtual void SearchAndPerformAction (std::string strAction);

private:
	// storage for the inner PersonCommandInterface
	IPersonCommand* m_pMyCommandInterface;
};

}

#endif
