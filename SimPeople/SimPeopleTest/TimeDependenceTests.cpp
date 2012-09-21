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

#include "../SimPeople/TimeDependenceLinear.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace SimPeople;

namespace SimPeopleTest
{		
	TEST_CLASS(TimeDependeceTest)
	{
	public:
		
		TEST_METHOD(TimeDependenceLinearNormalBehaviourTest)
		{
			TimeDependenceLinear* t_pTimeDependenceLinear = NULL;
			t_pTimeDependenceLinear = new TimeDependenceLinear();
			t_pTimeDependenceLinear->SetSlope(-1);

			float f = 5.0f;
			t_pTimeDependenceLinear->UpdateValue(f, 1.0);
			Assert::AreEqual(f, 4.0f);

			t_pTimeDependenceLinear->UpdateValue(f, 1.0);
			Assert::AreEqual(f, 3.0f);

			t_pTimeDependenceLinear->SetSlope(-1.5);
			f = 3.5f;
			t_pTimeDependenceLinear->UpdateValue(f, 1.0);
			Assert::AreEqual(f, 2.0f);

			f = 3.5f;
			t_pTimeDependenceLinear->UpdateValue(f, 2.0);
			Assert::AreEqual(f, 0.5f);

			delete t_pTimeDependenceLinear;
		}

		TEST_METHOD(TimeDependenceLinearNegativeTest)
		{
			TimeDependenceLinear* t_pTimeDependenceLinear = NULL;
			t_pTimeDependenceLinear = new TimeDependenceLinear();
			t_pTimeDependenceLinear->SetSlope(-1);

			float f = -1.0f;
			t_pTimeDependenceLinear->UpdateValue(f, 1.0);
			Assert::AreEqual(f, 0.0f);

			delete t_pTimeDependenceLinear;
		}

		TEST_METHOD(TimeDependenceLinearZeroTest)
		{
			TimeDependenceLinear* t_pTimeDependenceLinear = NULL;
			t_pTimeDependenceLinear = new TimeDependenceLinear();
			t_pTimeDependenceLinear->SetSlope(-1);
			float f = 0.0f;
			t_pTimeDependenceLinear->UpdateValue(f, 1.0);
			Assert::AreEqual(f, 0.0f);

			delete t_pTimeDependenceLinear;
		}
	};
}