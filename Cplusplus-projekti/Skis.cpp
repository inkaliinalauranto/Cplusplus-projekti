#include "Skis.h"

#include "Items.h"


/* Oletusrakentaja, joka kutsuu isäntäluokan oletusrakentajaa. Luokan
* rakentajassa categoryName-jäsenmuuttujalle asetetaan arvoksi luokan
* nimi eli "sukset".
*/
Skis::Skis() : Items()
{
	this->categoryName = "sukset";
}


// Tuhoaja:
Skis::~Skis() {}


/* Isäntäluokalta perittävä jäsenmetodi, jonka toteutus ylikirjoitetaan
* tässä luokan käyttötarkoitusta palvelevaksi. Metodin ylikirjoitettavassa
* versiossa esitetään kaksi string-alkioista koostuvaa vectoria. Sen
* jälkeen kutsutaan isäntäluokan readFileToRows-metodia, jolle parametrina
* välitetään ensimmäinen vector-muuttuja. Metodissa rows-muuttujaan luetaan
* items_file.txt-tiedoston rivit.
*
* Sen jälkeen kutsutaan isäntäluokan filterByCategory-metodia, jossa haetaan 
* ja tulostetaan kategorian tavarat rows-muuttujaan talletetuista alkioista. 
* Metodille välitetään siis parametreiksi molemmat vector-apumuuttujat sekä
* luokan jäsenmuuttuja categoryName.
*/
void Skis::listItems()
{
	vector<string> rows;
	vector<string> categoryRows;

	Items::readFileToRows(rows);

	Items::filterByCategory(rows, this->categoryName, categoryRows);
}