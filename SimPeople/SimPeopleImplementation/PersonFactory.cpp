#include "PersonFactory.h"
#include "PersonWithNeeds.h"
#include "../SimPeople/INeed.h"
#include "../SimPeople/TimeDependenceLinear.h"

namespace SimPeople
{
PersonFactory::PersonFactory(void)
{
}


PersonFactory::~PersonFactory(void)
{
}

Person* PersonFactory::CreatePersonWithBasicNeeds ( void )
{
	Person* pPerson = new PersonWithNeeds();
	//
	INeed* t_pNeed = new INeed("SleepNeed");
	t_pNeed->AddAction(0.5f, "sleep");
	t_pNeed->SetTimeDependence(new TimeDependenceLinear());
	pPerson->AddNeed(t_pNeed);

	return pPerson;

}

}