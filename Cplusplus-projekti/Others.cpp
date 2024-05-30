#include "Others.h"

#include "Items.h"

using namespace std;


Others::Others() : Items()
{
	this->categoryName = "muu";
}


// Tuhoaja:
Others::~Others() {}


void Others::listItems()
{
	vector<string> rows;
	vector<string> rowsOfCategory;

	Items::readFileToRows(rows);

	Items::filterByCategory(rows, this->categoryName, rowsOfCategory);
}