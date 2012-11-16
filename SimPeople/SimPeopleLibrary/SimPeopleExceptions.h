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


#ifndef SIMPEOPLELIBRARY_SIMPEOPLEEXCEPTIONS_H
#define SIMPEOPLELIBRARY_SIMPEOPLEEXCEPTIONS_H

#include <boost/exception/all.hpp>

namespace SimPeople
{
namespace Exceptions
{
/// basic Exception. Derive from this for all SimPeople Exceptions
struct ExceptionBase: virtual std::exception, virtual boost::exception { };

/// IO Error Exception. Use this for FileNotFoud, wrong input Type, wrong cmdl arguments, invalid data types
struct IOError: virtual ExceptionBase { };


/// Basic Exception for all Pointer Errors
struct PointerError : virtual ExceptionBase {};

/// Special Exception if a Pointer is NULL
struct NullPointerError : virtual PointerError{};

/// Basic Exception for Wrong Arguments
struct ArgumentError : virtual ExceptionBase {};

/// Special Exception for unknown Strings
struct UnkownStringError : virtual ArgumentError
{
public:
	UnkownStringError(std::string strUnknown) {m_strUnknownString = strUnknown;};
	~UnkownStringError() throw() {};
	inline std::string GetString (void) {return m_strUnknownString;};
private:
	std::string m_strUnknownString;
};

/// Special Exception for wrong Completion Values
struct CompletionError : virtual ArgumentError {};

/// Logical Error for things that might not be (race conditions, etc)
struct LogicalError: virtual ExceptionBase{};

/// Error if some distinct Values are not distinct
struct DistinctError : virtual LogicalError{};

}
}

#endif
