#include "Poles.h"

#include "Items.h"

using namespace std;


Poles::Poles() : Items()
{
	this->categoryName = "sauvat";
}


// Tuhoaja
Poles::~Poles() {}


void Poles::listItems()
{
	vector<string> rows;
	vector<string> rowsOfCategory;

	Items::readFileToRows(rows);

	Items::filterByCategory(rows, this->categoryName, rowsOfCategory);
}