#ifndef MENU_H
#define MENU_H

#include "Items.h"

class Menu
{
private:
	// Privaattien j�senmuuttujien esittely:
	Items items;

	int choice;

	// Privaattien j�senmetodien esittely:
	void printEndLine();

	int listItemsByCategory();

	void borrowItem(Items& items);

	void returnItem(Items& items);

	int handleError();

	int addItem(Items& items);

	void deleteItem(Items& items);

public:
	// Julkisen oletusrakentajan esittely:
	Menu();

	// Tuhoaja:
	~Menu();

	// Julkisen metodin esittely:
	int start();
};

#endif // MENU_H
