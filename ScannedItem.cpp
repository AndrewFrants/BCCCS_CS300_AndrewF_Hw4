#include "ScannedItem.h"


ScannedItem::ScannedItem()
{
}

ScannedItem::ScannedItem(const ScannedItem& o)
{
	this->barcode = o.barcode;
	this->description = o.description;
}

ScannedItem::ScannedItem(double& barcode, string desc)
{
	this->barcode = barcode;
	this->description = desc;
}

ScannedItem::~ScannedItem()
{
}

const ScannedItem& ScannedItem::operator=(ScannedItem& o) {
	if (!(*this == o)) {
		this->barcode = o.barcode;
		this->description = o.description;
	}
	return *this;
}

bool operator<(ScannedItem& left, ScannedItem& right) {
	return (left.barcode < right.barcode);
}

bool operator>(ScannedItem& left, ScannedItem& right) {
	return (left.barcode > right.barcode);
}

// The Key for scannedItem is First and Last
// so we use these to determine if the scanned item
// is the same; we use the barcode only as comparison
// op
bool operator==(ScannedItem& left, ScannedItem& right)
{
	return (left.barcode == right.barcode);
}

// get barcode
double ScannedItem::getBarcode() const
{
	return barcode;
}

// get desc
string ScannedItem::getDescription() const
{
	return description;
}