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
#include "Item.h"
#include "Items.h"



int main()
{
    Items items = Items();
    items.listItems();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu

