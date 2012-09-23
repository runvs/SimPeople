#include "PersonWithNeeds.h"
#include "../SimPeople/NeedManager.h"
namespace SimPeople
{
PersonWithNeeds::PersonWithNeeds(void) :
	BasicNeedPersonCommand((new IPersonCommand()))
{
	m_strName = "Paul";

	PersonWithNeeds::m_pNeedManager = new NeedManager(this);
}


PersonWithNeeds::~PersonWithNeeds(void)
{
}

void PersonWithNeeds::DoActionGetFood(void)
{
	std::cout << m_strName << " is getting food" << std::endl;
};

void PersonWithNeeds::DoActionStarve(void)
{
	std::cout << m_strName << " starves" << std::endl;
};

void PersonWithNeeds::DoActionSleep(void)
{
	std::cout << m_strName << " is getting some sleep" << std::endl;
};

void PersonWithNeeds::DoActionCollapse(void)
{
	std::cout << m_strName <<  " collapses" << std::endl;
};

void PersonWithNeeds::DoActionShit(void)
{
	std::cout << m_strName <<  " is going For a shit" << std::endl;
};
}