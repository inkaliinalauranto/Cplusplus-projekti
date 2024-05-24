#ifndef ITEMS_H
#define ITEMS_H

#include "Item.h"
#include <iostream>
#include <vector>

class Items
{
private:
	/* Lis‰t‰‰n demotarkoituksessa oletusrakentajassa kolmen alkion
	* mittaiseen items-taulukkoon kolme tavaraa:
	*/
	Item items[3];

	string fileName;

	// Privaatit j‰senmetodit:
	void readFileToRows(vector<string>& rows);

	int setSize(vector<string> rows);

	string changeRentalState(vector<string>& rows, const string id, const bool propertyState, const string emsg);

public:
	// Oletusrakentaja:
	Items();

	// Julkiset metodit:
	void listItems();

	string rentItem(string id);

	string revertItem(string id);

	size_t appendItem(Item item);

	string removeItem(string id);
};

#endif // ITEMS_H

