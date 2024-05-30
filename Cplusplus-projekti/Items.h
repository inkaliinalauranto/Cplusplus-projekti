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

	// Privaattien j‰senmetodien esittely:
	int setSize(vector<string> rows);

	string changeRentalState(vector<string>& rows, const string id, const bool propertyState, const string emsg);
	
	void printByCategory(string categoryName, vector<string>& categoryRows);

protected:
	/* Merkkijonomuotoa olevan fileName-nimisen periytyv‰n j‰senmuuttujan 
	esittely:
	*/
	string fileName;

	// Periytyv‰t j‰senmetodit:
	void readFileToRows(vector<string>& rows);

	void filterByCategory(vector<string>& rows, const string cname, vector<string>& categoryRows);

public:
	// Julkisen oletusrakentajan esittely:
	Items();

	// Tuhoaja:
	~Items();

	// Julkisten j‰senmetodien esittely:
	virtual void listItems();

	string rentItem(string id);

	string revertItem(string id);

	size_t appendItem(Item item);

	string removeItem(string id);
};

#endif // ITEMS_H

