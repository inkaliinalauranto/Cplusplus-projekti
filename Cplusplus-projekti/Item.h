#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <vector>

using namespace std;

class Item
{
private:
	// Luokan privaatin j�senmetodin esittely:
	size_t generateId();

protected:
	// Luokan suojattujen j�senmuuttujien esittely:
	size_t id;
	string name;
	string category;
	bool isRented;

	// Luokan suojatun j�senmetodin esittely:
	void printInformation();

public:
	// Julkisen staattisen luokkamuuttujan esittely:
	static size_t count;

	// Julkisen oletusrakentajan esittely:
	Item();

	// Julkisen kuormitetun rakentajan esittely:
	Item(string name, int category, bool isRented);

	// Julkisten getter-metodien esittely:
	size_t getId();
	string getName();
	string getCategory();
	bool getRentalState();
};

#endif // ITEM_H

