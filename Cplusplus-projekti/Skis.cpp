#include "Skis.h"

#include "Items.h"

using namespace std;


Skis::Skis() : Items()
{
	this->categoryName = "sukset";
}


// Tuhoaja:
Skis::~Skis() {}


void Skis::listItems()
{
	vector<string> rows;
	vector<string> rowsOfCategory;

	Items::readFileToRows(rows);

	Items::filterByCategory(rows, this->categoryName, rowsOfCategory);
}