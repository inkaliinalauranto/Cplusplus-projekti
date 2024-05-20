#ifndef ITEMS_H
#define ITEMS_H

#include "Item.h"

class Items
{
private:
	Item items[3];

public:
	// Oletusrakentaja:
	Items();

	// Julkiset metodit:
	//void appendItem(Item item);

	//void removeItem(Item item);

	void listItems();
};

#endif // ITEMS_H

