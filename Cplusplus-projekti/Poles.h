#ifndef POLES_H
#define POLES_H

#include "Items.h"

class Poles : public Items
{
private:
	string categoryName;

public:
	Poles();

	// Tuhoaja:
	~Poles();

	void listItems();
};

#endif // POLES_H

