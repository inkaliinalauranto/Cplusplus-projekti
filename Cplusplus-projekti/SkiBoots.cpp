#include "SkiBoots.h"

#include "Items.h"

using namespace std;


SkiBoots::SkiBoots() : Items()
{
	this->categoryName = "monot";
}


// Tuhoaja
SkiBoots::~SkiBoots() {}


void SkiBoots::listItems()
{
	vector<string> rows;
	vector<string> rowsOfCategory;

	Items::readFileToRows(rows);

	Items::filterByCategory(rows, this->categoryName, rowsOfCategory);
}