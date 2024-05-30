#ifndef SKIBOOTS_H
#define SKIBOOTS_H

#include "Items.h"

class SkiBoots : public Items
{
private:
	string categoryName;

public:
	SkiBoots();

	// Tuhoaja:
	~SkiBoots();

	void listItems();
};

#endif // SKIBOOTS_H

