#include <boost\lexical_cast.hpp>

#include "PersonFactory.h"
#include "PersonWithNeeds.h"
#include "../SimPeople/INeed.h"
#include "../SimPeople/TimeDependenceLinear.h"


namespace SimPeople
{

unsigned int PersonFactory::m_uiNameCounter = 0;
PersonFactory::PersonFactory(void)
{
}


PersonFactory::~PersonFactory(void)
{
}

Person* PersonFactory::CreatePersonWithBasicNeeds ( void )
{
	Person* pPerson = new PersonWithNeeds();
	pPerson->SetName(CreateRandomName());
	AddNeeds(pPerson);

	return pPerson;

}


std::string PersonFactory::CreateRandomName(void)
{
	std::string t_strReturn = "";
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


void PersonFactory::AddNeeds( Person* pPerson)
{
	INeed* t_pNeed = new INeed("SleepNeed");
	t_pNeed->AddAction(0.33f, "sleep");
	t_pNeed->AddAction(0.01f, "collapse");
	TimeDependenceLinear* t_pTimeDependance = new TimeDependenceLinear();
	t_pTimeDependance->SetSlope(-0.623f);
	t_pNeed->SetTimeDependence(t_pTimeDependance);
	pPerson->AddNeed(t_pNeed, 12);

	t_pNeed = new INeed("FoodNeed");
	t_pNeed->AddAction(0.6f, "getfood");
	t_pNeed->AddAction(0.2f, "starve");
	t_pNeed->SetTimeDependence(new TimeDependenceLinear());
	pPerson->AddNeed(t_pNeed, 15);

	t_pNeed = new INeed("ShitNeed");
	t_pNeed->AddAction(0.24f, "shit");
	t_pTimeDependance = new TimeDependenceLinear();
	t_pTimeDependance->SetSlope(-0.435f);
	t_pNeed->SetTimeDependence(t_pTimeDependance);
	t_pNeed->SetTimeDependence(new TimeDependenceLinear());
	pPerson->AddNeed(t_pNeed, 25);
}

}