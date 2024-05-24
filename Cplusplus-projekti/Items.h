#ifndef ITEMS_H
#define ITEMS_H

#include "Item.h"
#include <iostream>
#include <vector>

using namespace std;

class Items
{
private:
	/* Lis‰t‰‰n demotarkoituksessa oletusrakentajassa kolmen alkion
	* mittaiseen items-taulukkoon kolme tavaraa:
	*/
	Item items[3] = 
	{ 
		Item("Rossignol Xium", 1, false),  
		Item("Leki HRC", 2, false), 
		Item("Ficher Speedmax Skate", 3, false) 
	};
	const string fileName = "items_file.txt";

	// Privaatit j‰senmetodit:
	void readFileToRows(const string filename, vector<string>& rows);

	int setSize(vector<string> rows);

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

