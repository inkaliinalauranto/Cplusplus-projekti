// Cplusplus-projekti.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/* Yksinkertainen varastonhallintajärjestelmä:
* - tavaroiden lainaus ja palautus, %
* - luokat: tavara, tavarat, valikko %
* - periytyminen: tavaroiden eri kategoriat
* - funktiot: lisää, lainaa ja palauta tavara sekä listaa tavarat %
* - standardi C++ -kirjastot: vector, string, iostream, fstream, %
* - komentokehoterajapinta toimii eri yllä mainittuihin operaatioihin %
* - README: ohje käyttöön sekä tarvittaessa ohje VS Community 2022 asennukseen
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

	// Käynnistetään ohjelma Menu-instanssin start-metodia kutsumalla: 
	return program.start();
}

