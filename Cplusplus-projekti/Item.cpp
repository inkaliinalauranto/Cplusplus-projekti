#include "Item.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

/* Staattisen luokkamuuttujan m��rittely. Muuttujan arvoa kasvatetaan 
* luokan rakentajissa, mink� ansiosta muuttujassa on tallessa arvo, joka 
* kertoo luokasta luotujen instanssien m��r�n. 
*/
size_t Item::count = 0;


/* Luokan privaatti j�senmetodi, joka luo tunnuksen. Funktiossa on useita 
* apumuuttujia, joista row- ja rows-muuttujia hy�dynnet��n tiedoston 
* lukemisessa. size_t-tietotyyppi� oleva biggestNumber-apumuuttuja alustetaan 
* arvoon 0. size_t-tietotyyppi� k�ytet��n tietotyypin int-sijassa, koska 
* my�hemmin hy�dynnet��n vector<>-tietotyypin size-metodia, joka palauttaa 
* size_t-tietotyyppi� olevan luvun.
* 
* itemsFileForReading-apumuuttujaan ifstream-luokan instanssi, jota 
* kuormitetaan luettavan tiedoston nimell� eli items_file.txt-merkkijonolla. 
* Jos tiedosto on olemassa eli itemsFileForReading-muuttujassa olevan 
* instanssin good-j�senmetodin kutsu palauttaa true-arvon, luetaan tiedoston 
* sis�lt� rows-muuttujaan siten, ett� yksi rivi vastaa yht� alkiota. Lopuksi 
* kutsutaan itemsFileForReading-muuttujaan talletetun instanssin 
* close-metodia.
* 
* Jos rows-muuttujan vectorissa olevien alkioiden lukum��r� on suurempi kuin 
* nelj�, eli tiedostossa on rivej�, ja jos lukum��r�n jakoj��nn�s on 0 eli 
* rivit on kirjoitettu tiedostoon oikealla tavalla, iteroidaan kaikki 
* tavaroiden tunnuksia kuvaavat rivit l�pi.
* 
* Jokaisella iteraatiolla apumuuttujaan idAsInt tallennetaan kulloisenkin 
* iteraatiokierroksen alkion kokonaisluvuksi muutettu arvo. Arvo muutetaan 
* kokonaisluvuksi string-kirjaston string to integer -metodia hy�dynt�m�ll�. 
* Sitten arvoa verrataan silmukan ulkopuolella aiemmin alustettuun 
* biggestNumber-muuttujan arvoon. Jos isAsInt-muuttujan arvo on suurempi, 
* vaihdetaan sen arvo biggestNumber-muuttujan arvoksi ja type castataan 
* se samalla vastaamaan size_t-tietotyyppi�.
* 
* N�in tavaralle saadaan generoitua yksil�llinen id, joka ei ole sama muiden 
* tiedostoissa olevien tavaroiden tunnusten kanssa. Uloimmassa else-haarassa 
* biggestNumberille asetetaan arvo count - 4, koska silloin tavaratiedosto 
* on tyhj�. Kuitenkin t�ss� t�st� luokasta on luotu kolme instanssia 
* Items-luokan oletusrakentajassa. N�in ollen countin arvo t�ss� tilanteessa 
* on kolme. 
*
* N�it� kolmea tyhj�� instanssia ei kuitenkaan tallennetta 
* tiedostoon, joten niiden lukum��r� ei haluta tunnuksia generoitaessa 
* ottaa huomioon. Siksi biggestNumber-muuttujaan on asetettava count - 3, 
* mutta koska funktion return-lausekkeessa palautetaan biggestNumber + 1, 
* on else-haarassa biggestNumberista v�hennett�v� viel� luku 1, mink� vuoksi 
* v�hennett�v� luku countista on 4.
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
		/* Ensimm�isen tavaran tunnuksesta kertova arvo on rivill� 2 eli
		* rows-muuttujan indeksiss� 1.
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

/* Oletusrakentaja, jossa asetetaan j�senmuuttujille oletusarvot ja 
* p�ivitet��n staattisen luokkamuuttujan lukema. Lukema p�ivitet��n heti 
* rakentajan alussa, koska ajantasaista lukemaa tarvitaan 
* generateId-metodissa. 
*/ 
Item::Item()
{
	count++;
	this->id = generateId();
	this->name = "ei nime�";
	this->category = "muu";
	this->isRented = false;
}


/* Kuormitettu rakentaja, jossa p�ivitet��n staattisen luokkamuuttujan 
* lukema ja generoidaan instanssille tunnus. Muiden j�senmuuttujien arvoiksi 
* asetetaan parametrien v�lityksell� saatavat arvot. category-j�senmuuttujan 
* kohdalla k�ytet��n switch-case-rakennetta, jonka ehtoihin verraten 
* category-parametrina saadun kokonaisluvun perusteella asetetaan arvo luokan 
* category-j�senmuuttujalle.
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


// id-j�senmuuttujan getter-metodi:
size_t Item::getId()
{
	return this->id;
}


// name-j�senmuuttujan getter-metodi:
string Item::getName()
{
	return this->name;
}


// category-j�senmuuttujan getter-metodi:
string Item::getCategory()
{
	return this->category;
}


// isRented-j�senmuuttujan getter-metodi:
bool Item::getRentalState()
{
	return this->isRented;
}
