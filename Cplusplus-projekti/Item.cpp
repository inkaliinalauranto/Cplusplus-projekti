#include "Item.h"

#include <iostream>

using namespace std;

int Item::itemCount = 0;

// Oletusrakentaja:
Item::Item()
{
	itemCount++;
	this->id = itemCount;
	this->name = "";
	this->category = 4;
	this->isRented = false;
}


// Kuormitettu rakentaja:
Item::Item(string name, int category, bool isRented)
{
	itemCount++;
	this->id = itemCount;
	this->name = name;
	this->category = category;
	this->isRented = isRented;
}


void Item::borrow()
{
	this->isRented = true;
	cout << "Tavara vuokrattu" << endl;
}


void Item::revert()
{
	this->isRented = false;
	cout << "Tavara palautettu" << endl;
}


void Item::printInformation()
{
	cout << "Tavaran nimi: " << this->name << endl;
	cout << "Tavaran id: " << this->id << endl;
	cout << "Tavaran kategoria: ";
	switch (category)
	{
	case 1:
		cout << "sukset" << endl;
		break;

	case 2:
		cout << "sauvat" << endl;
		break;

	case 3:
		cout << "monot" << endl;
		break;
	default:
		cout << "muu" << endl;
		break;
	}
	
	cout << "Tavaran vuokraustilanne: ";
	if (isRented)
	{ 
		cout << "varattu\n" << endl;
	}
	else
	{
		cout << "vapaa\n" << endl;
	}
}