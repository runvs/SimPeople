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
class IPersonCommand
{
public:
	IPersonCommand(void);
	virtual ~IPersonCommand(void);
	void DoAction(std::string strActionName);

	virtual void SearchAndPerformAction(std::string strAction);
protected:
	inline void TriggerStringHasBeenFound(void) {m_bStringHasBeenFound = true;};

private:
	bool m_bStringHasBeenFound;
	void CheckForActionFound(std::string strAction);
};


class CommandInterfaceDecorator : public IPersonCommand
{
public:
	CommandInterfaceDecorator(IPersonCommand* pCommandInterface)
	{
		if (pCommandInterface == NULL)
		{
			throw SimPeople::Exceptions::NullPointerError();
		}
		m_pMyCommandInterface = pCommandInterface;
	};

	virtual ~CommandInterfaceDecorator()
	{
		if (m_pMyCommandInterface != NULL)
		{
			delete m_pMyCommandInterface;
		}
	}

	virtual void SearchAndPerformAction (std::string strAction);

private:	
	IPersonCommand* m_pMyCommandInterface;
};

}

#endif