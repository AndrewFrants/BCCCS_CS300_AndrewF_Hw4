#pragma once
#include <assert.h>
#include "SepChainingHashtable.h"
#include "LinkedList.h"

// ADT for storing items in a hashtable
// this is an open hashtable
template <class T>
class SepChainingHashtable
{
	// we will be using IHashedItem interface of T, T MUST implement IHashedItem
	static_assert(is_base_of<IHashedItem, T>::value, "T must inherit from IHashedItem");

private:
	LinkedList<T>* hashTable;
	long count;

	// here we hash mod size; to get the
	// hash index for this hashtable
	long GetLocalHash(const T& item) const
	{
		IHashedItem* hashedItem = (IHashedItem*)&item; // we ensured item is convertible, see top of class
		return abs(hashedItem->GetHash()) % count;
	}

public:
	// designed to store billions of records
	SepChainingHashtable(unsigned long size)
	{
		initialize(size);
	}

	// initialize/reset array
	void initialize(unsigned long count)
	{
		hashTable = new LinkedList<T>[count];
		this->count = count;
	}

	// insert an item
	void insert(T& item)
	{
		long size_loc = GetLocalHash(item);
		hashTable[size_loc].insertFirst(item);
	}

	// search for an item
	bool search(T& item)
	{
		long size_loc = GetLocalHash(item);

		bool found = true;

		try
		{
			T& found_item = this->hashTable[size_loc].search(item);
		}
		catch (ItemNotFoundException) {
			found = false;
		}

		return found;
	}
};