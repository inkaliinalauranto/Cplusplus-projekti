// Cplusplus-projekti.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Menu.h"

using namespace std;

int main()
{
	// Huomioidaan tulostuksissa skandinaaviset aakkoset:
	setlocale(LC_ALL, "fi-FI");

	// Luodaan instanssi Menu-luokasta:
	Menu program = Menu();

	// K‰ynnistet‰‰n ohjelma Menu-instanssin start-metodia kutsumalla: 
	return program.start();
}

