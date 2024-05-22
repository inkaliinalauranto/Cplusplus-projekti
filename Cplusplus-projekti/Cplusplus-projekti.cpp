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

using namespace std;

int main()
{
    Items items = Items();

    int choice;
    
    cout << "Tervetuloa hiihtotarvikkeiden varausj�rjestelm��n!\n" << endl;

    while (true)
    {
        cout << "Mit� haluat tehd�? " << endl;
        cout << "1 -> Listaa tavarat" << endl; // Tehty
        cout << "2 -> Vuokraa tavara" << endl;
        cout << "3 -> Palauta tavara" << endl;
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
            cout << "Mink� tavaran haluat vuokrata (anna valinnan 1 tulostuksessa n�kyv� id)?" << endl;
        }
        else if (choice == 3)
        {
            cout << "Valintaa ei ole viel� olemassa." << endl;
        }
        else if (choice == 4)
        {
            string itemName;
            int category;

            cout << "Sy�t� tavaran nimi: ";
            cin >> itemName;
            cout << "\nSy�t� tavaran kategoria" << endl;
            cout << "(1 -> sukset, 2 -> sauvat, 3 -> monot, 4 -> muu):" << endl;
            cin >> category;
            
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
                items.appendItem(appendableItem);
            }

        }

        else if (choice == 5)
        {
            string itemId;
            cout << "Sy�t� poistettavan tavaran id: " << endl;
            cin >> itemId;
            items.removeItem(itemId);
        }
        else if (choice == 6)
        {
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
        cout << endl;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu

