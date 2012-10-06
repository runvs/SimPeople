#include "INameGenerator.h"
#include "SimPeopleExceptions.h"

namespace SimPeople
{
INameGenerator::INameGenerator(void)
{
}


INameGenerator::~INameGenerator(void)
{
}

std::string INameGenerator::GetName ()
{
	// call the method
	std::string t_strName = DoGetName();

	// some basic postchecks
	if (t_strName.size() == 0)
	{
		throw SimPeople::Exceptions::UnkownStringError("t_strName");
	}

	return t_strName;
}
}