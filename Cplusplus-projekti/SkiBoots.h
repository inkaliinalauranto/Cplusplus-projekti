#ifndef SKIBOOTS_H
#define SKIBOOTS_H

#include "Items.h"

// Luokka perii Items-luokan:
class SkiBoots : public Items
{
private:
	// Privaatin j�senmuuttujan esittely:
	string categoryName;

public:
	// Oletusrakentajan esittely:
	SkiBoots();

	// Tuhoajan esittely:
	~SkiBoots();

	// Julkisen j�senmetodin esittely:
	void listItems();
};

#endif // SKIBOOTS_H

