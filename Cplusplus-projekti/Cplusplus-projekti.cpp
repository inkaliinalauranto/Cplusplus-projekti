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

using namespace std;

int main()
{
    Items items = Items();

    int choice;
    
    cout << "Tervetuloa hiihtotarvikkeiden varausjärjestelmään!\n" << endl;

    while (true)
    {
        cout << "Mitä haluat tehdä? " << endl;
        cout << "1 -> Listaa tavarat" << endl; // Tehty
        cout << "2 -> Vuokraa tavara" << endl;
        cout << "3 -> Palauta tavara" << endl;
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
            cout << "Minkä tavaran haluat vuokrata (anna valinnan 1 tulostuksessa näkyvä id)?" << endl;
        }
        else if (choice == 3)
        {
            cout << "Valintaa ei ole vielä olemassa." << endl;
        }
        else if (choice == 4)
        {
            string itemName;
            int category;

            cout << "Syötä tavaran nimi: ";
            cin >> itemName;
            cout << "\nSyötä tavaran kategoria" << endl;
            cout << "(1 -> sukset, 2 -> sauvat, 3 -> monot, 4 -> muu):" << endl;
            cin >> category;
            
            if (category <= 0)
            {
                cout << "Ohjelmassa tapahtui virhetilanne - vääränlainen syöte." << endl;
                cout << "Jos haluat jatkaa, aja ohjelma uudestaan." << endl;
                cout << "Kiitos ohjelman käytöstä!" << endl;
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
            cout << "Syötä poistettavan tavaran id: " << endl;
            cin >> itemId;
            items.removeItem(itemId);
        }
        else if (choice == 6)
        {
            cout << "Kiitos ohjelman käytöstä!" << endl;
            break;
        }
        else
        {
            cout << "Ohjelmassa tapahtui virhetilanne - vääränlainen syöte." << endl;
            cout << "Jos haluat jatkaa, aja ohjelma uudestaan." << endl;
            cout << "Kiitos ohjelman käytöstä!" << endl;
            return 1;
        }
        cout << endl;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu

