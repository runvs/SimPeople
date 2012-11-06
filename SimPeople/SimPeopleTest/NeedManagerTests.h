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

#include "stdafx.h"

#include "../SimPeopleLibrary/NeedManager.h"
#include "../SimPeopleLibrary/INeed.h"
#include "../SimPeopleLibrary/SimPeopleExceptions.h"
#include "../SimPeopleImplementation/BasicNeedPersonCommand.h"
#include "../SimPeopleLibrary/TimeDependenceLinear.h"

using namespace SimPeople;

namespace SimPeopleTest
{		
	class NeedManagerTest
	{
	public:
		void RunTests()
		{
			NeedManagerConstructorDestructorTest();
			NeedManagerConstructorDestructorExceptionTest();
			NeedManagerAddTest();
			NeedManagerUpdateTest();
			NeedManagerChangeCompletionTest();
		}


	private:
		void NeedManagerConstructorDestructorTest ()
		{
			NeedManager* t_pNeedManager = new NeedManager();
			delete t_pNeedManager;
		}


		void NeedManagerConstructorDestructorExceptionTest()
		{
			 NeedManager* t_pNeedManager = NULL;
			 try
			 {
				t_pNeedManager = new NeedManager(NULL);
			 }
			 catch ( SimPeople::Exceptions::NullPointerError)
			 {

			 }
			 catch (...)
			 {
				abort;
			 }

			 t_pNeedManager = new NeedManager(new BasicNeedPersonCommand(new IPersonCommand()));
			 delete t_pNeedManager;
		}

		void NeedManagerAddTest()
		{
			NeedManager* t_pNeedManager = new NeedManager();

			t_pNeedManager->AddNeed(new INeed("TestNeed"), 15);

			try	// check for Adding NULL
			{
				t_pNeedManager->AddNeed(NULL, 24);
				abort;
			}
			catch (SimPeople::Exceptions::NullPointerError)
			{}
			catch (...)
			{
				abort;
			}

			try		// check for negative Priority
			{
				t_pNeedManager->AddNeed(new INeed("TestNeed2"), -24);
				abort;
			}
			catch (SimPeople::Exceptions::ArgumentError)
			{}
			catch (...)
			{
				abort;
			}


			try		// check for a double need
			{
				t_pNeedManager->AddNeed(new INeed("TestNeed"), 14);
				abort;
			}
			catch (SimPeople::Exceptions::DistinctError)
			{}
			catch (...)
			{
				abort;
			}

			try		// check for a double priority
			{
				t_pNeedManager->AddNeed(new INeed("TestNeed3"), 15);
				abort;
			}
			catch (SimPeople::Exceptions::DistinctError)
			{}
			catch (...)
			{
				abort;
			}
			delete t_pNeedManager;
		}


		void NeedManagerUpdateTest()
		{
			NeedManager* t_pNeedManager = new NeedManager(new BasicNeedPersonCommand(new IPersonCommand()));

			INeed* t_pNeed = new INeed("TestNeed");
			t_pNeed->SetTimeDependence(new TimeDependenceLinear());
			t_pNeed->AddAction(0.5, "TestAction");
			t_pNeedManager->AddNeed(t_pNeed, 15);

			
			t_pNeedManager->Update(1.0f);

			 delete t_pNeedManager;
		}


		
		void NeedManagerChangeCompletionTest()
		{
			NeedManager* t_pNeedManager = new NeedManager(new BasicNeedPersonCommand(new IPersonCommand()));

			INeed* t_pNeed = new INeed("TestNeed");
			t_pNeedManager->AddNeed(t_pNeed, 15);

			t_pNeedManager->ChangeNeedCompletion("TestNeed", -0.5);

			//
			try 
			{
				t_pNeedManager->ChangeNeedCompletion("TestNeed2", -0.5);
			}
			catch (SimPeople::Exceptions::UnkownStringError)
			{
			}
			catch (...)
			{
				abort;
			}

			delete t_pNeedManager;
		}

	};
}