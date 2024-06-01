#include "Items.h"

#include "Item.h"
#include <iostream> 
#include <fstream>
#include <string>
#include <vector>

using namespace std;


/* M‰‰ritell‰‰n oletusrakentajassa fileName-j‰senmuuttujan arvoksi 
* merkkijonomuotoinen tiedostonimi items_file.txt. Tallennetaan
* itemsFileForReading-muuttujaan instanssi ifstream-luokasta, jolle
* v‰litet‰‰n parametrina fileName-muuttujaan tallennettu merkkijono.
*
* Ehtolausella tarkistetaan, onko itemsFileForReading-muuttuja luettavissa.
* Jos ei, tiedostoa ei ole olemassa, jolloin asetetaan demotarkoituksessa 
* itsem‰‰ritellyt arvot items-taulukon kullekin alkiolle. Alkiot luetaan 
* fileName-muuttujan arvon nimiseen tekstitiedostoon silmukassa, jos 
* kirjoittaminen tiedostoon onnistuu. Muussa tapauksessa tulostetaan viesti 
* virhetilanteesta.
*
* Lopuksi kutsutaan sek‰ tiedostoon kirjoittamiseen liittyv‰n 
* ofstream-instanssin ett‰ tiedostosta lukemiseen liittyv‰n 
* ifstream-instanssin close-metodeja. 
*/
Items::Items()
{
	this->fileName = "items_file.txt";

	// Avataan lukuyhteys:
	ifstream fileReading = ifstream(this->fileName);

	/* Jos items_file.txt-tiedostoa ei viel‰ ole olemassa eli jos ohjelma
	* ajetaan ensimm‰isen kerran, luodaan tiedosto ja lis‰t‰‰n siihen
	* silmukassa items-taulukon alkioiden tiedot.
	*/
	if (!fileReading.good())
	{
		this->items[0] = Item("Rossignol Xium", 1, false);
		this->items[1] = Item("Leki HRC", 2, false);
		this->items[2] = Item("Ficher Speedmax Skate", 3, false);

		// Avataan kirjoitusyhteys:
		ofstream fileWriting = ofstream(this->fileName);

		if (fileWriting.fail())
		{
			cout << "Ohjelmassa tapahtui virhetilanne - tiedostoon ei voi kirjoittaa.\n" << endl;
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				int id = i + 1;
				fileWriting
					<< items[i].getName() << "\n"
					<< items[i].getId() << "\n"
					<< items[i].getCategory() << "\n"
					<< items[i].getRentalState() << "\n";
			}
		}


		// Suljetaan kirjoitusyhteys:
		fileWriting.close();
	}

	// Suljetaan lukuyhteys:
	fileReading.close();
}


// Tuhoaja:
Items::~Items() {}


/* M‰‰ritell‰‰n privaatti j‰senmetodi, joka ottaa parametrina
* merkkijonoalkioista koostuvan vector-listan. T‰ss‰ funktiossa parametrina
* v‰litetyst‰ muuttujasta tehd‰‰n kopio, eiv‰tk‰ funktion parametriin tekem‰t
* muutokset tapahdu itse muuttujalle.
*
* Alustetaan kokonaislukumuuttuja size arvoon 0. Jos parametrin‰ v‰litetyss‰
* muuttujassa on alkioita eli jos se ei ole tyhj‰, asetetaan size-muuttujan
* arvoksi alkioiden m‰‰r‰ hyˆdynt‰m‰ll‰ parametrin size-j‰senmetodia. Koska
* metodi palauttaa size_t-tietotyyppi‰ olevan arvon, tehd‰‰n sille type
* castaus. Lopuksi palautetaan size-muutujan arvo.
*/
int Items::setSize(vector<string> rows)
{
	int size = 0;

	if (!rows.empty())
	{
		size = (int)rows.size();
	}

	return size;
}


/* M‰‰ritell‰‰n privaatti j‰senmetodi, joka ottaa parametreina
* merkkijonoalkioista koostuvan vector-listan pass by reference -tyylill‰ sek‰
* vakioarvoisina tunnuksesta kertovan merkkijonon, tilanteesta kertovan
* totuusarvon ja virheest‰ kertovan merkkijonon.
*
* M‰‰ritet‰‰n ensin funktiossa useita apumuuttujia alustusarvoilla. Sen
* j‰lkeen tallennetaan muuttujaan fileWriting ofstream-luokan instanssi,
* jolle parametriksi annetaan fileName-j‰senmuuttujan arvo. Jos muuttujan
* j‰senmetodi fail palauttaa arvon true eli tiedostoon kirjoittaminen ei
* onnistu, tulostetaan siit‰ viesti.
*
* Jos taas parametrina v‰litetyn vector-listan alkioiden lukum‰‰r‰ on
* nelj‰ tai suurempi, eli tiedostossa on rivej‰, ja jos lukum‰‰r‰n
* jakoj‰‰nnˆs on 0 eli rivit on kirjoitettu tiedostoon oikealla tavalla,
* iteroidaan kaikki vuokrauksen tilasta kertova rivit l‰pi. Jos parametrina
* v‰litetyn tunnuksen arvo vastaa iteraatiokierroksen arvoa, asetetaan
* arvot myˆs muihin apumuuttujiin ja poistutaan silmukasta.
*
* Sen j‰lkeen iteroidaan parametrina v‰litetyn rows-muuttujan kaikki alkiot
* l‰pi. Jos iteraation indeksi vastaa apumuuttujaan indexOfValueToBeChanged
* tallennettua indeksi‰ ja jos indeksi‰ vastaavan alkion arvo ei ole sama kuin
* parametrin‰ v‰litetyn propertyState-muttujan arvo eli vuokraustilaa ei
* koiteta muuttaa jo olemassa olevaksi, asetetaan arvoksi
* propertyState-parametriss‰ v‰litetty totuusarvo merkkijonoksi muutettuna.
* Muussa tapauksessa isAlreadyInAction-apumuuttujan arvo vaihdetaan todeksi
* ja tulostetaan parametrina saatu virheviesti.
*
* Jos sen sijaan indeksi vastaa indexOfItemName-apumuuttujaan talletettua
* indeksi‰, annetaan itemName-apumuuttujan arvoksi alkion arvo
* rows-vectorissa ko. indeksin kohdalta. Silmukan lopuksi kirjoitetaan
* iteroitava rivi fileWriting-muuttujaan.
*
* Uloimmassa else-haarassa tulostetaan virheviesti, ja lopuksi kutsutaan
* fileWriting-muuttujaan talletetun instanssin close-metodia. Sen j‰lkeen
* tarkastetaan, onko isIdInFile-apumuuttujan arvo muuttunut funktion aikana
* todeksi. Jos ei, tulostetaan siit‰ tieto ja poistutaan funktiosta tyhj‰n
* merkkijonon muotoa olevalla paluuarvolla. Jos isAlreadyInAction-muuttujan
* arvo on funktiossa muutettu todeksi, poistutaan funktiosta niin ik‰‰n
* tyhj‰ll‰ merkkijonolla. Muussa tapauksessa poistutaan funktiossa
* itemName-apumuuttujaan talletetuulla arvolla.
*/
string Items::changeRentalState(vector<string>& rows, const string id, const bool propertyState, const string emsg)
{
	// Haetaan rows-vectorissa olevien alkioiden lukum‰‰r‰: 
	int rowsSize = setSize(rows);
	/* Alustetaan tavaran nimen osoittavan indeksin arvoksi indeksi, jota ei
	* varmasti lˆydy rows-muuttujasta antamalla arvoksi alkioiden lukum‰‰r‰.
	* rows-muuttujassa viimeisen alkion indeksi on aina lukum‰‰r‰ - 1.
	*/
	int indexOfItemName = rowsSize;
	/* Alustetaan myˆs muutettavan arvon osoittavan indeksin arvoksi indeksi,
	* jota ei varmasti lˆydy rows-muuttujasta.
	*/
	int indexOfValueToBeChanged = rowsSize;
	bool isIdInFile = false;
	bool isAlreadyInAction = false;
	string itemName = "";

	ofstream fileWriting = ofstream(this->fileName);

	if (fileWriting.fail())
	{
		cout << "Ohjelmassa tapahtui virhetilanne - tiedostoon ei voi kirjoittaa.\n" << endl;
	}
	else if (rows.size() >= 4 && rows.size() % 4 == 0)
	{
		/* Ensimm‰isen tavaran tunnuksesta kertova arvo on rivill‰ 2 eli
		* rows-muuttujan indeksiss‰ 1. Seuraavan tavaran vastaava arvo on
		* edellisest‰ nelj‰n alkion p‰‰ss‰.
		*/
		for (int i = 1; i < rows.size(); i += 4)
		{
			if (rows[i] == id)
			{
				// Tavaran nimi on tunnuksen indeksi‰ edelt‰v‰ss‰ indeksiss‰: 
				indexOfItemName = i - 1;
				/* Tavaran vuokrauksesta kertovan tilan indeksi on kahden
				indeksin p‰‰ss‰ tunnuksen indeksist‰:
				*/
				indexOfValueToBeChanged = i + 2;
				/* Jos parametrin‰ v‰litetty id lˆytyy, vaihdetaan siit‰
				kertovan totuusarvomuuttujan arvo todeksi:
				*/
				isIdInFile = true;
				break;
			}
		}

		for (int i = 0; i < rows.size(); i++)
		{
			if (i == indexOfValueToBeChanged)
			{
				/* Hyˆdynnet‰‰n vertailussa string-kirjaston
				string to integer -metodia, ja lis‰ksi type castataan
				kokonaisluvuksi muutettu arvo totuusarvoksi:
				*/
				if ((bool)stoi(rows[i]) == propertyState)
				{
					isAlreadyInAction = true;
					cout << emsg << endl;
				}
				else
				{
					rows[i] = to_string(propertyState);
				}
			}
			else if (i == indexOfItemName)
			{
				itemName = rows[indexOfItemName];
			}
			fileWriting << rows[i] << endl;
		}
	}
	else
	{
		cout << "Tiedosto on tyhj‰ tai siin‰ olevat tiedot ovat puutteellisia.\n" << endl;
	}

	fileWriting.close();

	if (!isIdInFile)
	{
		cout << "Tavaraa syˆtt‰m‰ll‰si tunnuksella ei lˆydy j‰rjestelm‰st‰.\n" << endl;
		return "";
	}
	else if (isAlreadyInAction)
	{
		return "";
	}
	else
	{
		return itemName;
	}
}


/* M‰‰ritell‰‰n privaatti j‰senmetodi, joka ottaa vastaan kategorian nime‰
* indikoivan vakiomerkkijonon ja merkkijonoalkioista koostuvan
* vector-listan pass by reference -tyylill‰. Metodissa m‰‰ritell‰‰n
* apumuuttuja index, jonka avulla ja arvoa silmukassa muuttamalla 
* m‰‰ritell‰‰n, mink‰lainen teksti tulostetaan ennen iteraatiokierroksella
* k‰sitelt‰v‰n alkion arvon tulostamista. For-silmukassa k‰yd‰‰n siis l‰pi
* parametrina v‰litetyn vectorin alkiot, jotka switch-rakenteen ja
* index-apumuuttujan avulla tulostetaan formatoituun muotoon.
*/
void Items::printByCategory(const string categoryName, vector<string>& categoryRows)
{
	int index = 0;

	cout << "-- Tavarat kategoriassa " << categoryName << " --\n " << endl;
	for (int i = 0; i < categoryRows.size(); i++)
	{
		switch (index)
		{
		case 0:
			cout << "Tavaran nimi: " << categoryRows[i] << endl;
			break;

		case 1:
			cout << "Tavaran id: " << categoryRows[i] << endl;
			break;

		case 2:
			cout << "Tavaran kategoria: " << categoryRows[i] << endl;
			break;

		case 3:
			cout << "Tavaran vuokraustilanne: ";
			if (stoi(categoryRows[i]) == 1)
			{
				cout << "varattu\n" << endl;
			}
			else
			{
				cout << "vapaa\n" << endl;
			}
			index = -1;
			break;
		}
		index++;
	}

	cout << "---------------------------------\n" << endl;
}


/* Funktiolle v‰litet‰‰n parametrina merkkijonoalkioista koostuva dynaaminen
* vector-lista pass by reference -tyylill‰ eli funktiossa parametrin arvoon
* teht‰v‰t muutokset j‰‰v‰t voimaan parametrina v‰litetylle muuttujalle
* funktiossa k‰ynnin j‰lkeen. Funktiossa ei siis k‰sitell‰ parametrina
* v‰litetyst‰ muuttujasta tehty‰ kopiota vaan muuttujaa itse.
*
* T‰ss‰ funktiossa esitell‰‰n merkkijonomuotoa oleva muuttuja row ja
* alustetaan fileReading-niminen instanssi ifstream-luokasta. Instanssille
* v‰litet‰‰n parametriksi fileName-j‰senmuuttujan arvo. Jos tiedoston
* lukeminen onnistuu eli fileReading-instanssin good-j‰senmetodi palauttaa
* arvon true, luetaan while-silmukassa tiedoston rivit parametrina v‰litetyn
* rows-vectorin alkioiksi.
*
* Muussa tapauksessa tulostetaan virheilmoitus. Lopuksi kutsutaan
* fileReading-muuttujaan talletetun ifstream-instanssin close-metodia.
*/
void Items::readFileToRows(vector<string>& rows)
{
	string row;
	ifstream fileReading = ifstream(this->fileName);

	if (fileReading.good())
	{
		while (getline(fileReading, row))
		{
			rows.push_back(row);
		}
	}
	else
	{
		cout << "Ohjelmassa tapahtui virhetilanne: tiedostoa ei ole olemassa.\n" << endl;
	}

	fileReading.close();
}


/* M‰‰ritell‰‰n periytyv‰ j‰senmetodi, joka ottaa parametreina vastaan
* kaksi eri merkkijonoalkioista koostuvaa vectoria pass by reference -tyylill‰
* sek‰ kategorian nime‰ kuvaavan vakiomerkkijonon. Jos parametrin‰ v‰litetyn
* rows-vektorin alkioiden lukum‰‰r‰ on nelj‰ tai suurempi ja jos lukum‰‰r‰n
* jakoj‰‰nnˆs on 0 eli rivit on lis‰tty vectoriin oikealla logiikalla,
* iteroidaan kaikki kategorian kertovat rivit l‰pi.
*
* Jos parametrina v‰litetyn kategorian nimi vastaa iteraatiokierroksen alkion
* arvoa, lis‰t‰‰n parametrina v‰litettyyn categoryRows-vectoriin tiedot siit‰
* tavarasetist‰, jonka kategoriakohta on kyseess‰. Sitten kutsutaan metodia,
* jossa categoryRows-vectoriin tallennetut tiedot tulostetaan formatoidussa
* muodossa ja jolle sen vuoksi v‰litet‰‰n parametrit categoryName ja
* categoryRows.

* Jos rows-parametrin alkioiden lukum‰‰r‰ ei vastaa ensimm‰isiin ehtoihin,
* siirryt‰‰n else-haaraan, jossa k‰ytt‰j‰lle tulostetaan virheviesti.
*/
void Items::filterByCategory(vector<string>& rows, const string categoryName, vector<string>& categoryRows)
{
	if (rows.size() >= 4 && rows.size() % 4 == 0)
	{
		/* Ensimm‰isen tavaran kategorian kertova arvo on kolmannessa alkiossa
		* eli indeksiss‰ 2. Seuraavan tavaran vastaava arvo on edellisest‰
		* nelj‰n alkion p‰‰ss‰.
		*/
		for (int i = 2; i < rows.size(); i += 4)
		{
			if (rows[i] == categoryName)
			{
				/* Tavaran nimen kertova alkio lˆytyy kategorian kertovan
				 * alkion edellist‰ alkiota edelt‰v‰st‰ alkiosta:
				 */
				string name = rows[i - 2];
				categoryRows.push_back(name);

				/* Tavaran tunnuksen kertova alkio lˆytyy kategorian kertovaa
				 * alkiota edelt‰v‰st‰ alkiosta:
				 */
				string id = rows[i - 1];
				categoryRows.push_back(id);

				string category1 = rows[i];
				categoryRows.push_back(category1);

				/* Tavaran varaustilanteen kertova alkio lˆytyy kategorian
				 * kertovaa alkiota seuraavasta alkiosta:
				 */
				string isRented = rows[i + 1];
				categoryRows.push_back(isRented);
			}
		}

		printByCategory(categoryName, categoryRows);
	}
	else
	{
		cout << "Tiedosto on tyhj‰ tai siin‰ olevat tiedot ovat puutteellisia.\n" << endl;
	}
}


/* Luokan julkinen j‰senmetodi, jonka aluksi alustetaan useampia apumuuttujia.
* fileReading-muuttujaan alustetaan luokasta ifstream instanssi, jolle
* v‰litet‰‰n parametriksi fileName-j‰senmuuttuja. Sen j‰lkeen while-silmukassa
* luetaan funktion alussa alustettuun row-merkkijonoapumuuttujaan
* fileReading-muuttujaan m‰‰ritellyn tiedoston rivi iteraatiokierroksen
* mukaan. Switch-rakenteella valitaan tulostettava teksti, jonka per‰‰n
* tulostetaan row-muuttujaan kyseisell‰ iteraatiolla tallennettu rivi.
* Switch-rakenteessa vertailtavaa index-apumuuttujan arvoa kasvatetaan
* while-silmukan eri iteraatioilla, kunnes sen arvo on 3.
*
* Indeksin arvon ollessa kolme, vertaillaan row-muuttujaan talletettua arvoa.
* Arvon mukaan tulostetaan tavaran vuokraustilanteeksi joko varattu tai vapaa.
* Sitten index-muuttujan arvo "nollataan" arvoon -1. Yksi nelj‰n iteraation
* yhdistelm‰ vastaa yhden tavaran tietojen l‰pik‰ynti‰. Lis‰ksi k‰ytˆss‰ on
* apumuuttuja itemOrdinary, jota kasvatetaan joka nelj‰nnen rivin eli jokaisen
* tavaratietosetin v‰lein. Muuttuja kertoo listatun tavaran j‰rjestysnumeron,
* joka tulostetaan. Lopuksi kutsutaan fileReading-muuttujaan talletun
* instanssin close-metodia.
*/
void Items::listItems()
{
	cout << "----- Kaikki tavarat ------\n" << endl;

	string row;

	ifstream fileReading = ifstream(this->fileName);

	int index = 0;
	int itemOrdinary = 1;

	while (getline(fileReading, row))
	{
		switch (index)
		{
		case 0:
			cout << itemOrdinary << ". --\n" << "Tavaran nimi: " << row << endl;
			itemOrdinary++;
			break;

		case 1:
			cout << "Tavaran id: " << row << endl;
			break;

		case 2:
			cout << "Tavaran kategoria: " << row << endl;
			break;

		case 3:
			cout << "Tavaran vuokraustilanne: ";
			if (row[0] == '1')
			{
				cout << "varattu\n" << endl;
			}
			else
			{
				cout << "vapaa\n" << endl;
			}
			index = -1;
			break;
		}
		index++;
	}

	fileReading.close();

	cout << "---------------------------\n" << endl;
}


/* Luokan julkinen j‰senmetodi, joka ottaa vastaan merkkijonomuotoa olevan
* vakioparametrin. Funktion alussa esitell‰‰n apumuuttuja rows, joka
* v‰litet‰‰n parametrina readFileToRows-funktiokutsuun. Sen j‰lkeen alustetaan
* totuusarvoapumuuttuja propertyState arvoon true, koska vuokratessa halutaan
* vaihtaa tavaran isRented-arvo ep‰todesta todeksi.
*
* Alustetaan myˆs errorMessage-niminen apumuuttuja virheviestin kertovalla
* merkkijonolla. Palautetaan funktiosta arvo, joka saadaan kutsumalla
* changeRentalState-j‰senmetodia. Parametreiksi funktiokutsuun asetetaan
* t‰m‰n funktion id-vakioparametri sek‰ apumuuttujien arvot. Paluuarvona
* changeRentalState-funktiosta saadaan merkkijono.
*/
string Items::rentItem(const string id)
{
	vector<string> rows;

	/* Luetaan tiedoston sis‰ltˆ rows-muuttujaan hyˆdynt‰m‰ll‰
	* pass by reference -tekniikkaa:
	*/
	readFileToRows(rows);

	bool propertyState = true;
	string errorMessage = "Tavara on jo varattu, ei vuokrattavissa.\n";

	// Varsinainen varaaminen:
	return changeRentalState(rows, id, propertyState, errorMessage);
}


/* Luokan julkinen j‰senmetodi, joka ottaa vastaan merkkijonomuotoa olevan
* vakioparametrin. Funktion alussa esitell‰‰n apumuuttuja rows, joka
* v‰litet‰‰n parametrina readFileToRows-funktiokutsuun. Sen j‰lkeen alustetaan
* totuusarvoapumuuttuja propertyState arvoon false, koska palautettaessa
* halutaan vaihtaa tavaran isRented-arvo todesta ep‰todeksi.
*
* Alustetaan myˆs errorMessage-niminen apumuuttuja virheviestin kertovalla
* merkkijonolla. Palautetaan funktiosta arvo, joka saadaan kutsumalla
* changeRentalState-j‰senmetodia. Parametreiksi funktiokutsuun asetetaan
* t‰m‰n funktion id-vakioparametri sek‰ apumuuttujien arvot. Paluuarvona
* changeRentalState-funktiosta saadaan merkkijono.
*/
string Items::revertItem(string id)
{
	vector<string> rows;

	/* Luetaan tiedoston sis‰ltˆ rows-muuttujaan hyˆdynt‰m‰ll‰
	* pass by reference -tekniikkaa:
	*/
	readFileToRows(rows);

	bool propertyState = false;
	string errorMessage = "Tavara on jo palautettu.\n";

	// Varsinainen palauttaminen:
	return changeRentalState(rows, id, propertyState, errorMessage);
}


/* Luokan julkinen j‰senmetodi, joka ottaa vastaan Item-luokan muotoa
* olevan parametrin. itemsFile-apumuuttujaan tallennetaan luokasta ofstream
* luotu instanssi, jota kuormitetaan t‰m‰n luokan fileName-j‰senmuuttujalla
* sek‰ ios_base-nimiavaruuteen kuuluvilla app- ja out-parametreill‰.
* Parametrin ios_base::app | ios_base::out avulla tiedoston loppuun pystyt‰‰n
* lis‰‰m‰‰n teksti‰.
*
* Jos fileReading-muuttujaan talletetun instanssin fail-metodin palauttama 
* arvo ei ole tosi, lis‰t‰‰n tiedostoon nelj‰ uutta rivi‰ eli uuden tavaran 
* tiedot, jotka saadaan v‰litetyn item-parametrin getter-metodeilla. Lis‰ksi 
* kutsutaan fileReading-muuttujassa olevan instanssin close-metodia ja 
* poistutaan funktiosta siten, ett‰ paluuarvoksi asetetaan itemin tunnus. 
* Muussa tapauksessa tulostetaan virheviesti ja palautetaan -1 merkkin‰ siit‰, 
* ettei tavaran lis‰‰minen onnistu.
*/
size_t Items::appendItem(Item item)
{
	/* Lis‰t‰‰n items_file.txt-tiedoston loppuun teksti‰ antamalla
	* ofstream-instanssille toiseksi parametriksi
	* ios_base::app | ios_base::out. Tekstiksi lis‰t‰‰n uuden tavaran
	* tiedot, jotka saadaan v‰litetyn item-parametrin getter-metodeilla.
	*/
	ofstream fileReading = ofstream(fileName, ios_base::app | ios_base::out);

	if (fileReading.fail())
	{
		cout << "Ohjelmassa tapahtui virhetilanne - tiedostoon ei voi kirjoittaa.\n" << endl;
		return -1;
	}
	else
	{
		fileReading
			<< item.getName() << "\n"
			<< item.getId() << "\n"
			<< item.getCategory() << "\n"
			<< item.getRentalState() << "\n";

		fileReading.close();

		return item.getId();
	}
}


/* M‰‰ritell‰‰n julkinen j‰senmetodi, joka ottaa vastaan merkkijonomuotoa
* olevan tavaran tunnusta indikoivan vakioparametrin. Funktion alussa
* esitell‰‰n apumuuttuja rows, joka v‰litet‰‰n parametrina
* readFileToRows-funktiokutsuun. Sen j‰lkeen alustetaan useita apumuuttujia
* alustusarvoilla.
*
* Sen j‰lkeen tallennetaan muuttujaan fileWriting ofstream-luokan instanssi,
* jolle parametriksi annetaan fileName-j‰senmuuttujan arvo. Jos muuttujan
* j‰senmetodi fail palauttaa arvon true eli tiedostoon kirjoittaminen ei
* onnistu, tulostetaan siit‰ viesti.
*
* Jos taas parametrina v‰litetyn vector-listan alkioiden lukum‰‰r‰ on
* nelj‰ tai suurempi, eli tiedostossa on rivej‰ ja jos lukum‰‰r‰n
* jakoj‰‰nnˆs on 0 eli rivit on kirjoitettu tiedostoon oikealla tavalla,
* iteroidaan kaikki tunnuksen kertovat rivit l‰pi. Jos parametrina v‰litetyn
* tunnuksen arvo vastaa iteraatiokierroksen arvoa, asetetaan arvot
* tilanteeseen liittyviin apumuuttujiin ja poistutaan silmukasta.
*
* Sen j‰lkeen iteroidaan parametrina v‰litetyn rows-muuttujan kaikki alkiot
* l‰pi. Kirjoitetaan iteroitava alkio tiedostoon, jos iteraatiokierros ei
* vastaa yhteenk‰‰n edellisess‰ silmukassa p‰ivitetyist‰ muuttujien arvoista. 
* Jos iteraatiokierroksen numero sen sijaan vastaa aiemmassa silmukassa
* firstRemovableIndex-apumuuttujaan talletettua indeksi‰, annetaan
* itemName-apumuuttujan arvoksi alkion arvo rows-vectorissa ko. indeksin
* kohdalta.
*
* Uloimmassa else-haarassa tulostetaan virheviesti, ja lopuksi kutsutaan
* fileWriting-muuttujaan talletetun instanssin close-metodia. Sen j‰lkeen
* tarkastetaan, onko isIdInFile-apumuuttujan arvo muuttunut funktion aikana
* todeksi. Jos ei, tulostetaan siit‰ tieto ja poistutaan funktiosta tyhj‰n
* merkkijonon muotoa olevalla paluuarvolla. Muussa tapauksessa poistutaan
* funktiossa itemName-apumuuttujaan talletetulla arvolla.
*/
string Items::removeItem(const string id)
{
	vector<string> rows;

	// V‰litet‰‰n rows-muuttuja pass by reference -tekniikalla:
	readFileToRows(rows);

	// Haetaan rows-vectorissa olevien alkioiden lukum‰‰r‰: 
	int rowsSize = setSize(rows);
	string itemName = "";
	/* Alustetaan ensimm‰isen poistettavan indeksin arvoksi indeksi, jota ei
	* varmasti lˆydy rows-muuttujasta asettamalla
	* firstRemovableIndex-muuttujan arvoksi alkioiden lukum‰‰r‰.
	* rows-muuttujassa viimeisen alkion indeksi on aina lukum‰‰r‰ - 1.
	*/
	int firstRemovableIndex = rowsSize;
	/* Alustetaan myˆs kolmea muuta poistettavaa arvoa osoittavan indeksin
	* arvoiksi indeksit, joita ei varmasti lˆydy rows-muuttujasta.
	*/
	int secondRemovableIndex = rowsSize + 1;
	int thirdRemovableIndex = rowsSize + 2;
	int fourthRemovableIndex = rowsSize + 3;
	bool isIdInFile = false;

	ofstream fileWriting = ofstream(this->fileName);

	if (fileWriting.fail())
	{
		cout << "Ohjelmassa tapahtui virhetilanne - tiedostoon ei voi kirjoittaa.\n" << endl;
	}
	else if (rows.size() >= 4 && rows.size() % 4 == 0)
	{
		for (int i = 1; i < rows.size(); i += 4)
		{
			if (rows[i] == id)
			{
				firstRemovableIndex = i - 1;
				secondRemovableIndex = i;
				thirdRemovableIndex = i + 1;
				fourthRemovableIndex = i + 2;
				isIdInFile = true;
				break;
			}
		}

		for (int i = 0; i < rows.size(); i++)
		{
			if (i != firstRemovableIndex && i != secondRemovableIndex && i != thirdRemovableIndex && i != fourthRemovableIndex)
			{
				fileWriting << rows[i] << endl;
			}
			else if (i == firstRemovableIndex)
			{
				itemName = rows[firstRemovableIndex];
			}
		}
	}
	else
	{
		cout << "Tiedosto on tyhj‰ tai siin‰ olevat tiedot ovat puutteellisia.\n" << endl;
	}

	fileWriting.close();

	if (!isIdInFile)
	{
		cout << "Tavaraa syˆtt‰m‰ll‰si tunnuksella ei lˆydy j‰rjestelm‰st‰.\n" << endl;
		return "";
	}
	else
	{
		return itemName;
	}
}
