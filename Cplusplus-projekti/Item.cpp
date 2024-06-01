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
* lukemisessa. size_t-tietotyyppi� oleva newId-apumuuttuja alustetaan
* arvoon 0. size_t-tietotyyppi� k�ytet��n tietotyypin int-sijasta, koska 
* muualla koodissa hy�dynnet��n vector<>-tietotyypin size-metodia, joka 
* palauttaa size_t-tietotyyppi� olevan luvun.
*
* itemsFileForReading-apumuuttujaan talletetaan ifstream-luokan instanssi, 
* jota kuormitetaan luettavan tiedoston nimell� eli 
* items_file.txt-merkkijonolla. Jos tiedosto on olemassa eli 
* itemsFileForReading-muuttujassa olevan instanssin good-j�senmetodin kutsu 
* palauttaa true-arvon, luetaan tiedoston sis�lt� rows-muuttujaan siten, ett� 
* yksi rivi vastaa yht� alkiota. Lopuksi kutsutaan 
* itemsFileForReading-muuttujaan talletetun instanssin close-metodia.
*
* Jos items_file.txt-tiedostoa ei ole olemassa, luodaan muualla ohjelmassa 
* t�m� tiedosto ja lis�ksi kolme demotavaraa Item-alkioiseen taulukkoon. 
* Koska taulukko on j�senmuuttuja, ja se esitell��n Items.h-tiedostossa 
* kolmipaikkaisena, luodaan t�st� luokasta siis 3 + 3 eli kuusi instanssia. 
*
* Jos instanssien lukum��r� t�st� luokasta on kuusi tai v�hemm�n, ei tiedostoa 
* v�ltt�m�tt� ole viel� olemassa, mink� vuoksi kolmelle demomieless� tehdylle 
* instanssille generoituisi kesken��n sama id, jos se luotaisiin else if 
* -haaran toteutusosan perusteella. Siksi if-lauseessa annetaan  
* newId-muuttujalle arvo luokasta tehtyjen instanssien lukum��r�n perustella. 
*
* Instanssien m��r�st� v�hennet��n kolme, koska ohjelma luo Items-listan 
* alustuksessa kolme merkitykset�nt� instanssia, joita ei tuoda n�kyviin 
* eik� tallenneta tiedostoon. Niiden lukum��r�� ei haluta ottaa my�sk��n 
* huomioon muille tavaroille tunnuksia generoitaessa. Siksi 
* newId-muuttujaan if-lauseessa asetetaan arvoksi count - 3.
*
* Jos ohjelma on esimerkiksi aloittanut ensimm�isen demoinstanssin luomisen, 
* on countin arvo nelj�. Silloin newId-muuttujaan tallennetaan arvo 4 - 3 eli 
* 1. N�in ensimm�inen demoinstanssi t�st� luokasta saa tunnuksen 1. Kun 
* ohjelma etenee luomaan toista demoinstanssia, on countin arvo 5, ja 
* newId-muuttujan arvo siten 5 - 3 eli 2. N�in toisen demoinstanssin 
* tunnukseksi tulee 2.
* 
* Jos ensimm�inen ehto ei t�yty ja siirryt��n else if -haaraan ja jos siis 
* rows-muuttajassa olevien alkioiden lukum��r�n jakoj��nn�s nelj�n suhteen on 
* 0 eli rivien ollessa kirjoitettuna tiedostoon oikealla tavalla, iteroidaan 
* kaikki tavaroiden tunnuksia kuvaavat rivit l�pi.
*
* Jokaisella iteraatiolla apumuuttujaan idAsInt tallennetaan kulloisenkin
* iteraatiokierroksen alkion kokonaisluvuksi muutettu arvo. Arvo muutetaan
* kokonaisluvuksi string-kirjaston string to integer -metodia hy�dynt�m�ll�.
* Sitten arvoa verrataan silmukan ulkopuolella aiemmin alustettuun
* newId-muuttujan arvoon. Jos idAsInt-muuttujan arvo on suurempi, vaihdetaan 
* sen arvo newId-muuttujan arvoksi ja type castataan se samalla vastaamaan 
* size_t-tietotyyppi�. Suurimpaa tiedostosta l�ytyv�� id:n arvoa kasvatetaan 
* lopuksi newId-muuttujaan tallennettuna yhdell�, ja n�in tavaralle saadaan 
* generoitua yksil�llinen id, joka ei ole sama muiden tiedostoissa olevien 
* tavaroiden tunnusten kanssa ja joka on aina edellisen tavaran tunnusta yht� 
* isompi. 
* 
* Jos else-haaraan p��dyt��n, tiedoston sis�lt� on todenn�k�isesti 
* v��r�nlainen, eik� tiedostonk�sittely t�llaisessa tilanteessa toimi en�� 
* luotettavasti. Niinp� newId:n arvo pysyy 0:na. Lis�ksi k�ytt�j�lle 
* tulostetaan virheilmoitus.
*/
size_t Item::generateId()
{
	string row;
	vector<string> rows;
	size_t newId = 0;
	ifstream itemsFileForReading = ifstream("items_file.txt");

	if (itemsFileForReading.good())
	{
		while (getline(itemsFileForReading, row))
		{
			rows.push_back(row);
		}
	}

	itemsFileForReading.close();

	if (count <= 6)
	{
		newId = count - 3;
	}
	else if (rows.size() % 4 == 0)
	{
		/* Ensimm�isen tavaran tunnuksesta kertova arvo on rivill� 2 eli
		* rows-muuttujan indeksiss� 1. Seuraavan tavaran tunnus on 
		* nelj�n alkion p��ss� edellisest�.
		*/
		for (int i = 1; i < rows.size(); i += 4)
		{
			int idAsInt = stoi(rows[i]);
			if (idAsInt > newId)
			{
				newId = (size_t)idAsInt;
			}
		}
		newId++;
	}
	else
	{
		cout << "Tiedostossa olevat tiedot ovat puutteellisia.\n" << endl;
	}

	return newId;
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


// Tuhoaja:
Item::~Item() {}


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
