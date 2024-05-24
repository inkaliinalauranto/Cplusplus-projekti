#ifndef MENU_H
#define MENU_H

#include "Items.h"

class Menu
{
private:
	// Privaatit jäsenmuuttujat:
	Items items;

	int choice;

	// Privaatit jäsenmetodit:
	void printEndLine();

	int handleError();

	void rentItem(Items& items);

	void returnItem(Items& items);

	int addItem(Items& items);

	void deleteItem(Items& items);

public:
	// Julkinen oletusrakentaja:
	Menu();

	// Julkinen metodi:
	int start();
};

#endif // MENU_H
