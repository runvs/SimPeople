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

#ifndef SIMPEOPLELIBRARY_TIMEDEPENDENCELINEAR_H
#define SIMPEOPLELIBRARY_TIMEDEPENDENCELINEAR_H

#include "ITimeDependence.h"


namespace SimPeople
{
/// Implementation of the Time Dependance for Linear Behaviour
class TimeDependenceLinear :
	public ITimeDependence
{
public:
	TimeDependenceLinear(void);
	~TimeDependenceLinear(void);

	virtual void UpdateValue(float& Value, float fTimeIncrement);

	inline void SetSlope ( float Slope) {m_fSlope = Slope; };

private:
	float m_fSlope;
};

}

#endif
