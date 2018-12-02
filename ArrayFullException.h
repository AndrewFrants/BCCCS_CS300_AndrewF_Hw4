#pragma once
#include <iostream>

// Array list full exception
class ArrayFullException : virtual public std::exception {
	std::string message;
public:
	// c'tor
	ArrayFullException(std::string msg)
	{
		message = msg;
	}

	virtual const char* what() const noexcept
	{
		return message.c_str();
	}
};