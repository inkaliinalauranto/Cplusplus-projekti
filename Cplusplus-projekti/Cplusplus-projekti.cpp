// Cplusplus-projekti.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/* Yksinkertainen varastonhallintajärjestelmä:
* - tavaroiden lainaus ja palautus,
* - luokat: tavara, jäsen
* - periytyminen: tavaroiden eri kategoriat
* - funktiot: lisää, lainaa ja palauta tavara sekä listaa tavarat
* - standardi C++ -kirjastot: vector, string, iostream, fstream,
* - komentokehoterajapinta toimii eri yllä mainittuihin operaatioihin
* - README: ohje käyttöön sekä tarvittaessa ohje VS Community 2022 asennukseen
*/

#include <iostream>
#include "Items.h"
#include <string>

using namespace std;


void printEndLine()
{
	cout << "---------------------------\n" << endl;
}


int handleError()
{
	cout << "Ohjelmassa tapahtui virhetilanne - vääränlainen syöte." << endl;
	cout << "Jos haluat jatkaa, aja ohjelma uudestaan." << endl;
	cout << "Kiitos ohjelman käytöstä!" << endl;
	return 1;
}


void rentItem(Items items)
{
	items.listItems();
	string itemId;
	cout << "Syötä vuokrattavan tavaran id: ";
	cin >> itemId;
	cout << endl;
	string renting = items.rentItem(itemId);
	if (renting != "")
	{
		cout << renting << " id:llä " << itemId << " vuokrattu onnistuneesti.\n" << endl;
	}
	printEndLine();
}


void revertItem(Items items)
{
	items.listItems();
	string itemId;
	cout << "Syötä palautettavan tavaran id: ";
	cin >> itemId;
	cout << endl;
	string reverting = items.revertItem(itemId);
	if (reverting != "")
	{
		cout << reverting << " id:llä " << itemId << " palautettu onnistuneesti.\n" << endl;
	}
	printEndLine();
}


int addItem(Items items)
{
	printEndLine();
	string itemName;
	int category;
	cout << "Syötä tavaran nimi: ";
	cin.ignore();
	getline(cin, itemName);
	cout << endl;

	if (itemName == "")
	{
		cout << "Tavaraa ei voida lisätä, koska sitä ei ole nimetty.\n" << endl;
		printEndLine();
		return 2;
	}

	cout << "Syötä tavaran kategoria (1 -> sukset, 2 -> sauvat, 3 -> monot, 4 -> muu): ";
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
			cout << itemName << " lisätty järjestelmään onnistuneesti id:llä " << appending << "\n" << endl;
		}
		printEndLine();
		return 0;
	}
}


void deleteItem(Items items)
{
	items.listItems();
	string itemId;
	cout << "Syötä poistettavan tavaran id: ";
	cin >> itemId;
	cout << endl;
	string removing = items.removeItem(itemId);
	if (removing != "")
	{
		cout << removing << " poistettu järjestelmästä onnistuneesti id:llä " << itemId << "\n" << endl;
	}
	printEndLine();
}


int main()
{
	// Huomioidaan tulostuksissa skandinaaviset aakkoset:
	setlocale(LC_ALL, "fi-FI");

	Items items = Items();

	int choice;

	cout << "Tervetuloa hiihtotarvikkeiden varausjärjestelmään!\n" << endl;

	while (true)
	{
		cout << "Mitä haluat tehdä? " << endl;
		cout << "1 -> Listaa tavarat" << endl; // Tehty
		cout << "2 -> Vuokraa tavara" << endl; // Tehty
		cout << "3 -> Palauta tavara" << endl; // Tehty
		cout << "4 -> Lisää tavara" << endl; // Tehty
		cout << "5 -> Poista tavara" << endl; // Tehty
		cout << "6 -> Poistu järjestelmästä\n" << endl; // Tehty

		cout << "Syötä valintasi: ";
		cin >> choice;
		cout << endl;

		if (choice == 1)
		{
			items.listItems();
		}
		else if (choice == 2)
		{
			rentItem(items);
		}
		else if (choice == 3)
		{
			revertItem(items);
		}
		else if (choice == 4)
		{
			int additionEvent = addItem(items);
			
			if (additionEvent == 1)
			{
				return 1;
			}
			else if (additionEvent == 2)
			{
				continue;
			}
		}
		else if (choice == 5)
		{
			deleteItem(items);
		}
		else if (choice == 6)
		{
			printEndLine();
			cout << "Kiitos ohjelman käytöstä!" << endl;
			break;
		}
		else
		{
			return handleError();
		}
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu

