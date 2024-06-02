#include "SkiBoots.h"

#include "Items.h"


/* Oletusrakentaja, joka kutsuu is‰nt‰luokan oletusrakentajaa. Luokan
* rakentajassa categoryName-j‰senmuuttujalle asetetaan arvoksi luokan
* nimi eli "monot".
*/
SkiBoots::SkiBoots() : Items()
{
	this->categoryName = "monot";
}


// Tuhoaja:
SkiBoots::~SkiBoots() {}


/* Is‰nt‰luokalta peritt‰v‰ j‰senmetodi, jonka toteutus ylikirjoitetaan
* t‰ss‰ luokan k‰yttˆtarkoitusta palvelevaksi. Metodin ylikirjoitettavassa
* versiossa esitet‰‰n kaksi string-alkioista koostuvaa vectoria. Sen
* j‰lkeen kutsutaan is‰nt‰luokan readFileToRows-metodia, jolle parametrina
* v‰litet‰‰n ensimm‰inen vector-muuttuja. Metodissa rows-muuttujaan luetaan
* items_file.txt-tiedoston rivit.
*
* Sen j‰lkeen kutsutaan is‰nt‰luokan filterByCategory-metodia, jossa haetaan
* ja tulostetaan kategorian tavarat rows-muuttujaan talletetuista alkioista.
* Metodille v‰litet‰‰n siis parametreiksi molemmat vector-apumuuttujat sek‰
* luokan j‰senmuuttuja categoryName.
*/
void SkiBoots::listItems()
{
	vector<string> rows;
	vector<string> categoryRows;

	Items::readFileToRows(rows);

	Items::filterByCategory(rows, this->categoryName, categoryRows);
}