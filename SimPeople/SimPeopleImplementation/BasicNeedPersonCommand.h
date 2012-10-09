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

#ifndef SIMPEOPLEIMPLEMENTATION_BASICNEEDPERSONCOMMAND_H
#define SIMPEOPLEIMPLEMENTATION_BASICNEEDPERSONCOMMAND_H

#include "../SimPeopleLibrary/IPersonCommand.h"

namespace SimPeople
{
	/// This class is the representation of the BasicNeed Command interface
	/// It is derived from the CommandInterfaceDecorator so it is compatible with any other decorator Command interface
class BasicNeedPersonCommand :
	public CommandInterfaceDecorator
{
public:
	/// ctor
	BasicNeedPersonCommand(IPersonCommand* pCommandInterface);
	/// dtor
	~BasicNeedPersonCommand(void);
private:
	/// This Method searches for the String and performs the action if it has been found.
	void SearchAndPerformAction (std::string strAction);

protected:
	// Basic Implementations for console Output. Pleas Override in your derived classes
	virtual void DoActionGetFood(void){std::cout << "Getting Food" << std::endl;};
	virtual void DoActionStarve(void){std::cout << "Starve" << std::endl;};
	virtual void DoActionSleep(void){std::cout << "Sleep" << std::endl;};
	virtual void DoActionCollapse(void){std::cout << "Collapse" << std::endl;};
	virtual void DoActionShit(void){std::cout << "Going For a shit" << std::endl;};
};
}

#endif