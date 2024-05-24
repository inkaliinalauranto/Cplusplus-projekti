// Cplusplus-projekti.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/* Yksinkertainen varastonhallintaj�rjestelm�:
* - tavaroiden lainaus ja palautus,
* - luokat: tavara, j�sen
* - periytyminen: tavaroiden eri kategoriat
* - funktiot: lis��, lainaa ja palauta tavara sek� listaa tavarat
* - standardi C++ -kirjastot: vector, string, iostream, fstream,
* - komentokehoterajapinta toimii eri yll� mainittuihin operaatioihin
* - README: ohje k�ytt��n sek� tarvittaessa ohje VS Community 2022 asennukseen
*/

#include <iostream>
#include "Items.h"
#include <string>

using namespace std;


void printEndLine()
{
	cout << "---------------------------\n" << endl;
}


int main()
{
	// Huomioidaan tulostuksissa skandinaaviset aakkoset:
	setlocale(LC_ALL, "fi-FI");

	Items items = Items();

	int choice;

	cout << "Tervetuloa hiihtotarvikkeiden varausj�rjestelm��n!\n" << endl;

	while (true)
	{
		cout << "Mit� haluat tehd�? " << endl;
		cout << "1 -> Listaa tavarat" << endl; // Tehty
		cout << "2 -> Vuokraa tavara" << endl; // Tehty
		cout << "3 -> Palauta tavara" << endl; // Tehty
		cout << "4 -> Lis�� tavara" << endl; // Tehty
		cout << "5 -> Poista tavara" << endl; // Tehty
		cout << "6 -> Poistu j�rjestelm�st�\n" << endl; // Tehty

		cout << "Sy�t� valintasi: ";
		cin >> choice;
		cout << endl;

		if (choice == 1)
		{
			items.listItems();
		}
		else if (choice == 2)
		{
			items.listItems();
			string itemId;
			cout << "Sy�t� vuokrattavan tavaran id: ";
			cin >> itemId;
			cout << endl;
			string renting = items.rentItem(itemId);
			if (renting != "")
			{
				cout << renting << " id:ll� " << itemId << " vuokrattu onnistuneesti.\n" << endl;
			}
			printEndLine();
		}
		else if (choice == 3)
		{
			items.listItems();
			string itemId;
			cout << "Sy�t� palautettavan tavaran id: ";
			cin >> itemId;
			cout << endl;
			string reverting = items.revertItem(itemId);
			if (reverting != "")
			{
				cout << reverting << " id:ll� " << itemId << " palautettu onnistuneesti.\n" << endl;
			}
			printEndLine();
		}
		else if (choice == 4)
		{
			printEndLine();
			string itemName;
			int category;
			cout << "Sy�t� tavaran nimi: ";
			cin.ignore();
			getline(cin, itemName);
			cout << endl;

			if (itemName == "")
			{
				cout << "Tavaraa ei voida lis�t�, koska sit� ei ole nimetty.\n" << endl;
				printEndLine();
				continue;
			}

			cout << "Sy�t� tavaran kategoria (1 -> sukset, 2 -> sauvat, 3 -> monot, 4 -> muu): ";
			cin >> category;
			cout << endl;

			if (category <= 0)
			{
				cout << "Ohjelmassa tapahtui virhetilanne - v��r�nlainen sy�te." << endl;
				cout << "Jos haluat jatkaa, aja ohjelma uudestaan." << endl;
				cout << "Kiitos ohjelman k�yt�st�!" << endl;
				return 1;
			}
			else
			{
				Item appendableItem = Item(itemName, category, false);
				size_t appending = items.appendItem(appendableItem);
				if (appending >= 0)
				{
					cout << itemName << " lis�tty j�rjestelm��n onnistuneesti id:ll� " << appending << "\n" << endl;
				}
				printEndLine();
			}
		}
		else if (choice == 5)
		{
			items.listItems();
			string itemId;
			cout << "Sy�t� poistettavan tavaran id: ";
			cin >> itemId;
			cout << endl;
			string removing = items.removeItem(itemId);
			if (removing != "")
			{
				cout << removing << " poistettu j�rjestelm�st� onnistuneesti id:ll� " << itemId << "\n" << endl;
			}
			printEndLine();
		}
		else if (choice == 6)
		{
			printEndLine();
			cout << "Kiitos ohjelman k�yt�st�!" << endl;
			break;
		}
		else
		{
			cout << "Ohjelmassa tapahtui virhetilanne - v��r�nlainen sy�te." << endl;
			cout << "Jos haluat jatkaa, aja ohjelma uudestaan." << endl;
			cout << "Kiitos ohjelman k�yt�st�!" << endl;
			return 1;
		}
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu

