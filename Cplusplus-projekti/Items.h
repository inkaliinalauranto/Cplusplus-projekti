#ifndef ITEMS_H
#define ITEMS_H

#include "Item.h"
#include <iostream>
#include <vector>

using namespace std;

class Items
{
private:
	/* Lisätään demotarkoituksessa oletusrakentajassa kolmen alkion
	* mittaiseen items-taulukkoon kolme tavaraa:
	*/
	Item items[3] = 
	{ 
		Item("Rossignol Xium", 1, false),  
		Item("Leki HRC", 2, false), 
		Item("Ficher Speedmax Skate", 3, false) 
	};
	const string fileName = "items_file.txt";

	// Privaatit jäsenmetodit:
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

