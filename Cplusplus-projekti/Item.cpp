#include "Item.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

/* Staattisen luokkamuuttujan määrittely. Muuttujan arvoa kasvatetaan 
* luokan rakentajissa, minkä ansiosta muuttujassa on tallessa arvo, joka 
* kertoo luokasta luotujen instanssien määrän. 
*/
size_t Item::count = 0;


/* Luokan privaatti jäsenmetodi, joka luo tunnuksen. Funktiossa on useita 
* apumuuttujia, joista row- ja rows-muuttujia hyödynnetään tiedoston 
* lukemisessa. size_t-tietotyyppiä oleva biggestNumber-apumuuttuja alustetaan 
* arvoon 0. size_t-tietotyyppiä käytetään tietotyypin int-sijassa, koska 
* myöhemmin hyödynnetään vector<>-tietotyypin size-metodia, joka palauttaa 
* size_t-tietotyyppiä olevan luvun.
* 
* itemsFileForReading-apumuuttujaan ifstream-luokan instanssi, jota 
* kuormitetaan luettavan tiedoston nimellä eli items_file.txt-merkkijonolla. 
* Jos tiedosto on olemassa eli itemsFileForReading-muuttujassa olevan 
* instanssin good-jäsenmetodin kutsu palauttaa true-arvon, luetaan tiedoston 
* sisältö rows-muuttujaan siten, että yksi rivi vastaa yhtä alkiota. Lopuksi 
* kutsutaan itemsFileForReading-muuttujaan talletetun instanssin 
* close-metodia.
* 
* Jos rows-muuttujan vectorissa olevien alkioiden lukumäärä on suurempi kuin 
* neljä, eli tiedostossa on rivejä, ja jos lukumäärän jakojäännös on 0 eli 
* rivit on kirjoitettu tiedostoon oikealla tavalla, iteroidaan kaikki 
* tavaroiden tunnuksia kuvaavat rivit läpi.
* 
* Jokaisella iteraatiolla apumuuttujaan idAsInt tallennetaan kulloisenkin 
* iteraatiokierroksen alkion kokonaisluvuksi muutettu arvo. Arvo muutetaan 
* kokonaisluvuksi string-kirjaston string to integer -metodia hyödyntämällä. 
* Sitten arvoa verrataan silmukan ulkopuolella aiemmin alustettuun 
* biggestNumber-muuttujan arvoon. Jos isAsInt-muuttujan arvo on suurempi, 
* vaihdetaan sen arvo biggestNumber-muuttujan arvoksi ja type castataan 
* se samalla vastaamaan size_t-tietotyyppiä.
* 
* Näin tavaralle saadaan generoitua yksilöllinen id, joka ei ole sama muiden 
* tiedostoissa olevien tavaroiden tunnusten kanssa. Uloimmassa else-haarassa 
* biggestNumberille asetetaan arvo count - 4, koska silloin tavaratiedosto 
* on tyhjä. Kuitenkin tässä tästä luokasta on luotu kolme instanssia 
* Items-luokan oletusrakentajassa. Näin ollen countin arvo tässä tilanteessa 
* on kolme. 
*
* Näitä kolmea tyhjää instanssia ei kuitenkaan tallennetta 
* tiedostoon, joten niiden lukumäärä ei haluta tunnuksia generoitaessa 
* ottaa huomioon. Siksi biggestNumber-muuttujaan on asetettava count - 3, 
* mutta koska funktion return-lausekkeessa palautetaan biggestNumber + 1, 
* on else-haarassa biggestNumberista vähennettävä vielä luku 1, minkä vuoksi 
* vähennettävä luku countista on 4.
*/
size_t Item::generateId()
{
	string row;
	vector<string> rows;
	size_t biggestNumber = 0;
	ifstream itemsFileForReading = ifstream("items_file.txt");

	if (itemsFileForReading.good())
	{
		while (getline(itemsFileForReading, row))
		{
			rows.push_back(row);
		}
	}

	itemsFileForReading.close();

	if (rows.size() >= 4 && rows.size() % 4 == 0)
	{
		/* Ensimmäisen tavaran tunnuksesta kertova arvo on rivillä 2 eli
		* rows-muuttujan indeksissä 1.
		*/ 
		for (int i = 1; i < rows.size(); i += 4)
		{
			int idAsInt = stoi(rows[i]);
			if (idAsInt > biggestNumber)
			{
				biggestNumber = (size_t)idAsInt;
			}
		}
	}
	else
	{
		biggestNumber = count - 4;
	}

	return biggestNumber + 1;
}

/* Oletusrakentaja, jossa asetetaan jäsenmuuttujille oletusarvot ja 
* päivitetään staattisen luokkamuuttujan lukema. Lukema päivitetään heti 
* rakentajan alussa, koska ajantasaista lukemaa tarvitaan 
* generateId-metodissa. 
*/ 
Item::Item()
{
	count++;
	this->id = generateId();
	this->name = "ei nimeä";
	this->category = "muu";
	this->isRented = false;
}


/* Kuormitettu rakentaja, jossa päivitetään staattisen luokkamuuttujan 
* lukema ja generoidaan instanssille tunnus. Muiden jäsenmuuttujien arvoiksi 
* asetetaan parametrien välityksellä saatavat arvot. category-jäsenmuuttujan 
* kohdalla käytetään switch-case-rakennetta, jonka ehtoihin verraten 
* category-parametrina saadun kokonaisluvun perusteella asetetaan arvo luokan 
* category-jäsenmuuttujalle.
*/
Item::Item(string name, int category, bool isRented)
{
	count++;
	this->id = generateId();
	this->name = name;

	switch (category)
	{
	case 1:
		this->category = "sukset";
		break;

	case 2:
		this->category = "sauvat";
		break;

	case 3:
		this->category = "monot";
		break;

	default:
		this->category = "muu";
		break;
	}

	this->isRented = isRented;
}


// id-jäsenmuuttujan getter-metodi:
size_t Item::getId()
{
	return this->id;
}


// name-jäsenmuuttujan getter-metodi:
string Item::getName()
{
	return this->name;
}


// category-jäsenmuuttujan getter-metodi:
string Item::getCategory()
{
	return this->category;
}


// isRented-jäsenmuuttujan getter-metodi:
bool Item::getRentalState()
{
	return this->isRented;
}
