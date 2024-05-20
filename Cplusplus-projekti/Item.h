#ifndef ITEM_H
#define ITEM_H

#include <iostream>

using namespace std;

class Item
{
protected:
	int id;
	string name;
	int category;
	bool isRented;

public:
	static int itemCount;

	// Oletusrakentaja:
	Item();

	// Kuormitettu rakentaja:
	Item(string name, int category, bool isRented);

	// Julkiset metodit:
	void borrow();
	void revert();
	void printInformation();
};

#endif // ITEM_H

