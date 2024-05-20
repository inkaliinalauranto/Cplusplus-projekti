#include "Items.h"

#include "Item.h"
#include <iostream>

using namespace std;

Items::Items()
{
	this->items[0] = Item("Testitavara1", 1, false);
	this->items[1] = Item("Testitavara2", 2, false);
	this->items[2] = Item("Testitavara3", 3, false);
}

//void appendItem(Item item);
//
//void removeItem(Item item);

void Items::listItems()
{
	cout << "----- Kaikki tavarat ------" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << "." << endl;
		items[i].printInformation();
	}
	cout << "---------------------------" << endl;
}