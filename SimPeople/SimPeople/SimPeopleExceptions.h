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


#pragma once
#include <boost/exception/all.hpp>

namespace SimPeople
{
namespace Exceptions
{
struct ExceptionBase: virtual std::exception, virtual boost::exception { };

struct IOError: virtual ExceptionBase { };

struct PointerError : virtual ExceptionBase {};
struct NullPointerError : virtual PointerError{};

struct ArgumentError : virtual ExceptionBase {};
struct UnkownStringError : virtual ArgumentError 
{
public:
	UnkownStringError(std::string strUnknown) {m_strUnknownString = strUnknown;};
	inline std::string GetString (void) {return m_strUnknownString;};
private:
	std::string m_strUnknownString;
};
struct CompletionError : virtual ArgumentError {};

struct LogicalError: virtual ExceptionBase{};

struct DistinctError : virtual LogicalError{};

}
}