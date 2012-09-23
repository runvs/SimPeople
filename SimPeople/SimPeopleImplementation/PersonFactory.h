#pragma once

#include <string>

namespace SimPeople
{

class Person;
class PersonFactory
{
public:
	PersonFactory(void);
	~PersonFactory(void);
	static Person* CreatePersonWithBasicNeeds (void);

private:
	static std::string CreateRandomName(void);
	static void AddNeeds( Person* pPerson);

	static unsigned int m_uiNameCounter;
};

}

