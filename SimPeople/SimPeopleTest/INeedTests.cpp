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
#include "CppUnitTest.h"

#include "../SimPeople/INeed.h"
#include "../SimPeople/TimeDependenceLinear.h"
#include "../SimPeople/SimPeopleExceptions.h"

	using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace SimPeople;

namespace SimPeopleTest
{		
	TEST_CLASS(NeedManagerTest)
	{
	public:
		
		TEST_METHOD(INeedGetNameTest)
		{
			INeed* t_pNeed = new INeed("TestNeed");
			Assert::AreEqual(t_pNeed->GetName(), (std::string)("TestNeed"));
			delete t_pNeed;
		}

		TEST_METHOD(INeedSetTimeDependenceTest)
		{
			INeed* t_pNeed = new INeed("TestNeed");
			t_pNeed->SetTimeDependence(new TimeDependenceLinear());

			try 
			{
				t_pNeed->SetTimeDependence(NULL);
				Assert::Fail(L"Never reach this point", LINE_INFO());
			}
			catch (SimPeople::Exceptions::NullPointerError)
			{
			}
			catch (...)
			{
				Assert::Fail(L"Wrong Exception", LINE_INFO());
			}

			delete t_pNeed;
		}

		TEST_METHOD(INeedUpdateTest)
		{
			INeed* t_pNeed = new INeed("TestNeed");
			try
			{
				t_pNeed->Update(1.0f);
				Assert::Fail(L"Never reach this point", LINE_INFO());
			}
			catch (SimPeople::Exceptions::NullPointerError)
			{}
			catch (...)
			{
				Assert::Fail(L"Wrong Exception", LINE_INFO());
			}



			t_pNeed->SetTimeDependence(new TimeDependenceLinear());
			t_pNeed->Update(1.0f);
			t_pNeed->Update(2.3f);

			delete t_pNeed;
		}

		TEST_METHOD(INeedConstructorTest)
		{
			INeed* t_pNeed = new INeed("TestNeed");
			t_pNeed->SetTimeDependence(new TimeDependenceLinear());
			Assert::AreEqual(t_pNeed->GetCompletion(), 1.0f);

			delete t_pNeed;
		}

		TEST_METHOD(INeedChangeCompletionTest)
		{
			INeed* t_pNeed = new INeed("TestNeed");	// Completion is 1.0f here
			t_pNeed->AddAction(0.75f, "TestAction");
			t_pNeed->ChangeCompletion(-0.5f);
			Assert::AreEqual(t_pNeed->GetCompletion(), 0.5f);
			t_pNeed->ChangeCompletion(-1.5f);
			Assert::AreEqual(t_pNeed->GetCompletion(), 0.0f);
			t_pNeed->ChangeCompletion(+2.5f);
			Assert::AreEqual(t_pNeed->GetCompletion(), 1.0f);
			delete t_pNeed;
		}

		TEST_METHOD(INeedAddActionTest)
		{
			INeed* t_pNeed = new INeed("TestNeed");
			
			// check if addAction is working properly
			t_pNeed->AddAction(0.25f, "TestAction");

			try 
			{
				t_pNeed->AddAction(0.1f, "");
				Assert::Fail(L"Never reach this point", LINE_INFO());
			}
			catch (SimPeople::Exceptions::UnkownStringError)
			{}
			catch (...)
			{
				Assert::Fail(L"Wrong Exception", LINE_INFO());
			}


			// check for exceptions
			for (float f = -0.5f; f <= 1.5f; f += 2)
			{
				try 
				{
					t_pNeed->AddAction(f, "TestAction");
					Assert::Fail(L"Never reach this point", LINE_INFO());
				}
				catch (SimPeople::Exceptions::CompletionError)
				{continue;	// with loop over different f values
				}
				catch (...)
				{
					Assert::Fail(L"Wrong Exception", LINE_INFO());
				}
			}

			
			delete t_pNeed;
		}

		TEST_METHOD(INeedGetActionListTest)
		{
			INeed* t_pNeed = new INeed("TestNeed");
			Assert::AreEqual(static_cast<int>(t_pNeed->GetActionList().size()), 0);

			t_pNeed->AddAction(0.75f, "TestAction");
			t_pNeed->ChangeCompletion(-0.5f);
			
			Assert::AreEqual(static_cast<int>(t_pNeed->GetActionList().size()), 1);
			Assert::AreEqual(t_pNeed->GetActionList().back(), static_cast<std::string>("TestAction"));

			t_pNeed->ClearActionList();
			delete t_pNeed;
		}


	};
}