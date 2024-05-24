#include "Item.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

size_t Item::count = 0;

size_t Item::generateId()
{
	string row;
	vector<string> rows;
	size_t biggestNumber = 0;
	ifstream itemsFileForReading3 = ifstream("items_file.txt");

	if (itemsFileForReading3.good())
	{
		while (getline(itemsFileForReading3, row))
		{
			rows.push_back(row);
		}
	}

	itemsFileForReading3.close();

	if (rows.size() >= 4 && rows.size() % 4 == 0)
	{
		for (int i = 1; i < rows.size(); i += 4)
		{
			int idAsInt = stoi(rows[i]);
			if (idAsInt > biggestNumber)
			{
				biggestNumber = (size_t)idAsInt;
			}
		}
	}
	else
	{
		/* Koska muuttuja count kertoo instanssien lukumäärän, 
		*/
		biggestNumber = count - 4;
	}

	return biggestNumber + 1;
}

// Oletusrakentaja:
Item::Item()
{
	count++;
	this->id = generateId();
	this->name = "ei nimeä";
	this->category = "muu";
	this->isRented = false;
}


// Kuormitettu rakentaja:
Item::Item(string name, int category, bool isRented)
{
	count++;
	this->id = generateId();
	this->name = name;

	switch (category)
	{
	case 1:
		this->category = "sukset";
		break;

	case 2:
		this->category = "sauvat";
		break;

	case 3:
		this->category = "monot";
		break;

	default:
		this->category = "muu";
		break;
	}

	this->isRented = isRented;
}


void Item::printInformation()
{
	cout << "Tavaran nimi: " << this->name << endl;
	cout << "Tavaran id: " << this->id << endl;
	cout << "Tavaran kategoria: " << this->category << endl;
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


size_t Item::getId()
{
	return this->id;
}


string Item::getName()
{
	return this->name;
}


string Item::getCategory()
{
	return this->category;
}


bool Item::getRentalState()
{
	return this->isRented;
}


void Item::setRentalState(bool state)
{
	this->isRented = state;
}