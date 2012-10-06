#include <boost/lexical_cast.hpp>
#include "NameGeneratorHardCoded.h"

namespace SimPeople
{

NameGeneratorHardCoded::NameGeneratorHardCoded(void)
{
	// again just set the variable
	NameGeneratorHardCoded::m_uiNameCounter = 0;
}


NameGeneratorHardCoded::~NameGeneratorHardCoded(void)
{
}

// here goes the work
std::string NameGeneratorHardCoded::DoGetName()
{
	std::string t_strReturn = "";

	// this is really ugly.
	if (m_uiNameCounter%5 == 0 )
	{
		t_strReturn = "Paul";
	}
	else if (m_uiNameCounter%5 == 1 )
	{
		t_strReturn = "Gilbert";
	}
	else if (m_uiNameCounter%5 == 2 )
	{
		t_strReturn = "Jean";
	}
	else if (m_uiNameCounter%5 == 3 )
	{
		t_strReturn = "Linda";
	}
	else if (m_uiNameCounter%5 == 4 )
	{
		t_strReturn = "Julia";
	}

	if ( m_uiNameCounter > 5 )
	{
		t_strReturn += boost::lexical_cast<std::string>((m_uiNameCounter/5));
	}

	m_uiNameCounter++;
	return t_strReturn;

}

}