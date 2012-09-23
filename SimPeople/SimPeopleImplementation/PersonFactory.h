#pragma once

namespace SimPeople
{

class Person;
class PersonFactory
{
public:
	PersonFactory(void);
	~PersonFactory(void);
	static Person* CreatePersonWithBasicNeeds (  void);
};

}

