// Cplusplus-projekti.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/* Yksinkertainen varastonhallintaj�rjestelm�:
* - tavaroiden lainaus ja palautus, %
* - luokat: tavara, tavarat, valikko %
* - periytyminen: tavaroiden eri kategoriat
* - funktiot: lis��, lainaa ja palauta tavara sek� listaa tavarat %
* - standardi C++ -kirjastot: vector, string, iostream, fstream, %
* - komentokehoterajapinta toimii eri yll� mainittuihin operaatioihin %
* - README: ohje k�ytt��n sek� tarvittaessa ohje VS Community 2022 asennukseen
* - kommentit
*/

#include <iostream>
#include "Menu.h"

using namespace std;

int main()
{
	// Huomioidaan tulostuksissa skandinaaviset aakkoset:
	setlocale(LC_ALL, "fi-FI");

	// Luodaan instanssi Menu-luokasta:
	Menu program = Menu();

	// K�ynnistet��n ohjelma Menu-instanssin start-metodia kutsumalla: 
	return program.start();
}

