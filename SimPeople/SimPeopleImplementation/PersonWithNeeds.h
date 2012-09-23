#pragma once

#include "../SimPeople/Person.h"
#include "BasicNeedPersonCommand.h"

namespace SimPeople
{

class PersonWithNeeds :
	public Person,
	public BasicNeedPersonCommand
{
public:
	PersonWithNeeds(void);
	~PersonWithNeeds(void);

	void DoActionGetFood(void);
	void DoActionStarve(void);
	void DoActionSleep(void);
	void DoActionCollapse(void);
	void DoActionShit(void);
};

}
