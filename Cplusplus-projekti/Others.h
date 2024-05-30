#ifndef OTHERS_H
#define OTHERS_H

#include "Items.h"

class Others : public Items
{
private:
	string categoryName;

public:
	Others();

	// Tuhoaja:
	~Others();

	void listItems();
};

#endif // OTHERS_H

