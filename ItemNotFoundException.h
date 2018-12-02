#pragma once
#include <iostream>

// Part of the OrderedLinkedList interface
// helps identify cases when an item doesnt exist
// in the list
class ItemNotFoundException : virtual public std::exception {
	std::string message;
public:
	// c'tor
	ItemNotFoundException(std::string msg)
	{
		message = msg;
	}

	virtual const char* what() const noexcept
	{
		return message.c_str();
	}
};