#ifndef OTHERS_H
#define OTHERS_H

#include "Items.h"

// Luokka perii Items-luokan
class Others : public Items
{
private:
	// Privaatin j�senmuuttujan esittely:
	string categoryName;

public:
	// Oletusrakentajan esittely:
	Others();

	// Tuhoajan esittely:
	~Others();

	// Julkisen j�senmetodin esittely:
	void listItems();
};

#endif // OTHERS_H

