#ifndef POLES_H
#define POLES_H

#include "Items.h"

// Luokka perii Items-luokan:
class Poles : public Items
{
private:
	// Privaatin j�senmuuttujan esittely:
	string categoryName;

public:
	// Oletusrakentajan esittely:
	Poles();

	// Tuhoajan esittely:
	~Poles();

	// Julkisen j�senmetodin esittely:
	void listItems();
};

#endif // POLES_H

