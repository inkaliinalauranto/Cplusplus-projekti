#include "Menu.h"

#include <iostream>
#include "Items.h"
#include <string>

using namespace std;


Menu::Menu()
{
	this->items = Items();
	this->choice = 6;
}


void Menu::printEndLine()
{
	cout << "---------------------------\n" << endl;
}


void Menu::rentItem(Items& items)
{
	items.listItems();
	string itemId;
	cout << "Syˆt‰ vuokrattavan tavaran id: ";
	cin >> itemId;
	cout << endl;
	string renting = items.rentItem(itemId);
	if (renting != "")
	{
		cout << renting << " id:ll‰ " << itemId << " vuokrattu onnistuneesti.\n" << endl;
	}
	printEndLine();
}


void Menu::returnItem(Items& items)
{
	items.listItems();
	string itemId;
	cout << "Syˆt‰ palautettavan tavaran id: ";
	cin >> itemId;
	cout << endl;
	string reverting = items.revertItem(itemId);
	if (reverting != "")
	{
		cout << reverting << " id:ll‰ " << itemId << " palautettu onnistuneesti.\n" << endl;
	}
	printEndLine();
}


int Menu::handleError()
{
	cout << "Ohjelmassa tapahtui virhetilanne - v‰‰r‰nlainen syˆte." << endl;
	cout << "Jos haluat jatkaa, aja ohjelma uudestaan." << endl;
	cout << "Kiitos ohjelman k‰ytˆst‰!" << endl;
	return 1;
}


int Menu::addItem(Items& items)
{
	printEndLine();
	string itemName;
	int category;
	cout << "Syˆt‰ tavaran nimi (v‰lt‰ skandinaavisia kirjaimia): ";
	cin.ignore();
	getline(cin, itemName);
	cout << endl;

	if (itemName == "")
	{
		cout << "Tavaraa ei voida lis‰t‰, koska sit‰ ei ole nimetty.\n" << endl;
		printEndLine();
		return 2;
	}

	cout << "Syˆt‰ tavaran kategoria (1 -> sukset, 2 -> sauvat, 3 -> monot, 4 -> muu): ";
	cin >> category;
	cout << endl;

	if (category <= 0)
	{
		return handleError();
	}
	else
	{
		Item appendableItem = Item(itemName, category, false);
		size_t appending = items.appendItem(appendableItem);
		if (appending >= 0)
		{
			cout << itemName << " lis‰tty j‰rjestelm‰‰n onnistuneesti id:ll‰ " << appending << "\n" << endl;
		}
		printEndLine();
		return 0;
	}
}


void Menu::deleteItem(Items& items)
{
	items.listItems();
	string itemId;
	cout << "Syˆt‰ poistettavan tavaran id: ";
	cin >> itemId;
	cout << endl;
	string removing = items.removeItem(itemId);
	if (removing != "")
	{
		cout << removing << " poistettu j‰rjestelm‰st‰ onnistuneesti id:ll‰ " << itemId << "\n" << endl;
	}
	printEndLine();
}


int Menu::start()
{
	cout << "Tervetuloa hiihtotarvikkeiden yll‰pitoj‰rjestelm‰‰n!\n" << endl;

	while (true)
	{
		cout << "Mit‰ haluat tehd‰? " << endl;
		cout << "1 -> Listaa tavarat" << endl; // Tehty
		cout << "2 -> Vuokraa tavara" << endl; // Tehty
		cout << "3 -> Palauta tavara" << endl; // Tehty
		cout << "4 -> Lis‰‰ tavara" << endl; // Tehty
		cout << "5 -> Poista tavara" << endl; // Tehty
		cout << "6 -> Poistu j‰rjestelm‰st‰\n" << endl; // Tehty

		cout << "Syˆt‰ valintasi: ";
		cin >> this->choice;
		cout << endl;

		if (this->choice == 1)
		{
			this->items.listItems();
		}
		else if (this->choice == 2)
		{
			rentItem(this->items);
		}
		else if (this->choice == 3)
		{
			returnItem(this->items);
		}
		else if (this->choice == 4)
		{
			int additionEvent = addItem(this->items);

			if (additionEvent == 1)
			{
				return 1;
			}
			else if (additionEvent == 2)
			{
				continue;
			}
		}
		else if (this->choice == 5)
		{
			deleteItem(this->items);
		}
		else if (this->choice == 6)
		{
			printEndLine();
			cout << "Kiitos ohjelman k‰ytˆst‰!" << endl;
			break;
		}
		else
		{
			return handleError();
		}
	}

	return 0;
}