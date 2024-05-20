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
#include "Item.h"
#include "Items.h"



int main()
{
    Items items = Items();
    items.listItems();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu

