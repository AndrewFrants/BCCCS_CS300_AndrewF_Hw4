#pragma once
#include <iostream>
#include "IHashedItem.h"

using namespace std;

// this is a scanned item
// because we will store it in a hashtable
// we need to implement IHashedItem interface
class ScannedItem : public IHashedItem
{
	double barcode;
	string description;

public:
	ScannedItem();
	ScannedItem(const ScannedItem& item);
	ScannedItem(double& barcode, string desc);
	double getBarcode() const;
	string getDescription() const;
	~ScannedItem();
	const ScannedItem& operator=(ScannedItem& o);

	// override hash function
	// we use the barcode, the hash function
	// uses the string ptr to hash so we wont
	// be passing description to the hash function
	// barcodes must be unique and are a good fit
	// for the input of a hashing function
	long GetHash() const
	{
		return hash<float>{}(this->barcode);
	}

	// used for comparisons
	friend bool operator==(ScannedItem& left, ScannedItem& right);
	friend bool operator>(ScannedItem& left, ScannedItem& right);
	friend bool operator<(ScannedItem& left, ScannedItem& right);
};