#ifndef SKIS_H
#define SKIS_H

#include "Items.h"

class Skis : public Items
{
private:
	string categoryName;

public:
	Skis();

	// Tuhoaja:
	~Skis();

	void listItems();
};

#endif // SKIS_H

