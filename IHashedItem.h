#pragma once

// Abstract class that allowes a hashed item
// to dip into its private data to generate
// a unique hash; this helps prevent clustering
// by using all the data in a class for hashing
class IHashedItem
{
public:
	// virtual method that a class should
	// implement if it would be stored in
	// a hashtable
	virtual long GetHash() const = 0;
};