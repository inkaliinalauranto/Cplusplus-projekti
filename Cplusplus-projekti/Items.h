#ifndef ITEMS_H
#define ITEMS_H

#include "Item.h"
#include <iostream>
#include <vector>

class Items
{
private:
	/* Esitell‰‰n privaatti j‰senmuuttuja, joka on kolmen Item-instanssin 
	* mittainen taulukko demotarkoituksessa. 
	*/
	Item items[3];

	/* Merkkijonomuotoa olevan fileName-nimisen privaatin j‰senmuuttujan 
	esittely:
	*/
	string fileName;

	// Privaattien j‰senmetodien esittely:
	void readFileToRows(vector<string>& rows);

	int setSize(vector<string> rows);

	string changeRentalState(vector<string>& rows, const string id, const bool propertyState, const string emsg);

public:
	// Julkisen oletusrakentajan esittely:
	Items();

	// Julkisten j‰senmetodien esittely:
	void listItems();

	string rentItem(string id);

	string revertItem(string id);

	size_t appendItem(Item item);

	string removeItem(string id);
};

#endif // ITEMS_H

