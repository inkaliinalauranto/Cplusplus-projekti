#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <vector>

using namespace std;

class Item
{
private:
	size_t generateId();

protected:
	size_t id;
	string name;
	string category;
	bool isRented;
	string row;
	vector<string> rows;

public:
	static size_t count;

	// Oletusrakentaja:
	Item();

	// Kuormitettu rakentaja:
	Item(string name, int category, bool isRented);

	// Julkiset metodit:
	void printInformation();
	size_t getId();
	string getName();
	string getCategory();
	bool getRentalState();
	void setRentalState(bool state);
};

#endif // ITEM_H

