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

#ifndef SIMPEOPLELIBRARY_ITIMEDEPENDENCE_H
#define SIMPEOPLELIBRARY_ITIMEDEPENDENCE_H

namespace SimPeople
{

	/// Basic Time Dependance Interface
class ITimeDependence
{
protected:
	/// ctor
	/// Can not be called from outside since it is protected. Suffer your Life in Denial!
	ITimeDependence(void);

public:
		/// dtor
	virtual ~ITimeDependence(void);

	/// This Method updates the passed Value
	/// overwrite in derived classes
	virtual void UpdateValue(float& Value, float fTimeIncrement) = 0;
};

}

#endif
