#ifndef SKIS_H
#define SKIS_H

#include "Items.h"

// Luokka perii Items-luokan:
class Skis : public Items
{
private:
	// Privaatin j�senmuuttujan esittely:
	string categoryName;

public:
	// Oletusrakentajan esittely:
	Skis();

	// Tuhoajan esittely:
	~Skis();

	// Julkisen j�senmetodin esittely:
	void listItems();
};

#endif // SKIS_H

