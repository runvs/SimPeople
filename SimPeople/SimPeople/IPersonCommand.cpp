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

#include "IPersonCommand.h"
#include "SimPeopleExceptions.h"

namespace SimPeople
{
IPersonCommand::IPersonCommand(void)
{
	m_bStringHasBeenFound = false;
}


IPersonCommand::~IPersonCommand(void)
{
}


void IPersonCommand::DoAction(std::string strActionName)
{
	m_bStringHasBeenFound = false;
	SearchAndPerformAction(strActionName);
	CheckForActionFound(strActionName);
}

 void IPersonCommand::SearchAndPerformAction(std::string strAction)
{
	// do nothing in here
}


 void IPersonCommand::CheckForActionFound(std::string strAction)
{
	std::cout << "Finishing Search for ActionString" << std::endl;
	if (!m_bStringHasBeenFound)
	{
		if ( strAction != "TestAction")
		{
			std::cout << "Search has not been sucessfull!" << std::endl;
			throw SimPeople::Exceptions::UnkownStringError(strAction);
		}
	}
}


 void CommandInterfaceDecorator::SearchAndPerformAction (std::string strAction) 
	{

		m_pMyCommandInterface->SearchAndPerformAction(strAction);  
		IPersonCommand::SearchAndPerformAction(strAction);
	};
}
