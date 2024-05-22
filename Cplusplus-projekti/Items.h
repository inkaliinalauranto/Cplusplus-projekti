#ifndef ITEMS_H
#define ITEMS_H

#include "Item.h"
#include <iostream>

using namespace std;

class Items
{
private:
	Item items[3];

public:
	// Oletusrakentaja:
	Items();

	// Julkiset metodit:
	void appendItem(Item item);

	void removeItem(string id);

	void listItems();

	void rentItem(int id, string name);
};

#endif // ITEMS_H

