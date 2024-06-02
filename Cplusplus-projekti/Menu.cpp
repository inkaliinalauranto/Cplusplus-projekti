#include "Menu.h"

#include <iostream>
#include <string>
#include "Items.h"
#include "Skis.h"
#include "SkiBoots.h"
#include "Poles.h"
#include "Others.h"

using namespace std;


/* Asetetaan oletusrakentajassa j‰senmuuttujille arvot. items-muuttujalle
* asetetaan arvoksi instanssi Items-luokasta ja choice-muuttujan arvoksi
* asetetaan 7, joka myˆhemm‰ss‰ k‰ytˆss‰ indikoi ohjelmasta poistumista.
*/
Menu::Menu()
{
	this->items = Items();
	this->choice = 7;
}



// Tuhoaja:
Menu::~Menu() {}


/* Metodi, jota kutsutaan luokan eri j‰senfunktioissa eri tulostusten 
* formatointiin katkoviivalla: 
*/
void Menu::printEndLine()
{
	cout << "---------------------------\n" << endl;
}


/* Metodi tulostaa virheviestit ja jatko-ohjeen sek‰ palauttaa virheest‰
* kertovan kokonaisluvun 1.
*/
int Menu::handleError()
{
	cout << "Ohjelmassa tapahtui virhetilanne - v‰‰r‰nlainen syˆte." << endl;
	cout << "Jos haluat jatkaa, aja ohjelma uudestaan." << endl;
	cout << "Kiitos ohjelman k‰ytˆst‰!" << endl;
	return 1;
}


/* Luokan privaatti j‰senmetodi, jossa kysyt‰‰n k‰ytt‰j‰lt‰ se kategoria, 
* jonka tavarat halutaan listata, ja toteutetaan kategorian tavaroiden 
* listaus. K‰ytt‰j‰n antama kategoriasta kertova valinta tallenetaan funktion 
* alussa esiteltyyn kokonaislukumuotoiseen category-muuttujaan. Jos syˆte on 0 
* tai pienempi eli joko v‰‰r‰nlainen kokonaisluku tai kokonaan v‰‰r‰‰ 
* tietotyyppi‰ oleva merkki, poistutaan funktiosta 
* handleError-funktiokutsulla, joka palauttaa virheest‰ kertovan 
* kokonaisluvun.
* 
* Muussa tapauksessa luodaan instanssit eri kategorioille tehdyist‰ luokista, 
* jotka kaikki perityvy‰t Items-luokasta. Sitten switch-case-rakenteella 
* tarkastetaan, mit‰ kategoriaa k‰ytt‰j‰n syˆte vastaa, mink‰ j‰lkeen 
* kutsutaan kategoriaa vastaavan luokan listItems-metodia, joka on 
* Items-luokalta perityv‰ ja lapsiluokan ylikirjoittama metodi. Lopuksi 
* eri kategorioita kuvaavat instanssit h‰vitet‰‰n.
*/
int Menu::listItemsByCategory()
{
	int category;

	cout << "Valitse listattava kategoria (1 -> sukset, 2 -> sauvat, 3 -> monot, 4 -> muu): ";
	cin >> category;
	cout << endl;

	if (category <= 0)
	{
		return handleError();
	}
	else
	{
		/* Luodaan instanssit Skis-, Poles-, SkiBoots- ja Others-luokista 
		* hyˆdynt‰m‰ll‰ dynaamista kekomuistia:
		*/
		Skis* skis = new Skis();
		Poles* poles = new Poles();
		SkiBoots* skiBoots = new SkiBoots();
		Others* others = new Others();

		switch (category)
		{
		case 1:
			/* Jos osoitin on sellainen jonka muistipaikassa oleva arvo on 
			* jonkin olion tietotyyppi‰ ja jos osoittimen avulla halutaan 
			* viitata muistipaikassa olevan arvon j‰senmetodiin, tehd‰‰n se 
			* k‰ytt‰m‰ll‰ -> merkki‰:
			*/
			skis->listItems();
			break;

		case 2:
			poles->listItems();
			break;

		case 3:
			skiBoots->listItems();
			break;

		default:
			others->listItems();
			break;
		}

		/* Vapautetaan dynaaminen muisti, kun instanssit tulevat 
		* elinkaariensa p‰ihin kutsumalla instanssien tuhoajia avainsanalla 
		* delete:
		*/
		delete skis;
		delete poles;
		delete skiBoots;
		delete others;

		return 0;
	}
}


/* Funktiolle v‰litet‰‰n parametrina instanssi Items-luokasta
* pass by reference -tyylill‰ eli funktiossa parametrin arvoon teht‰v‰t
* muutokset j‰‰v‰t voimaan parametrina v‰litetylle muuttujalle funktiossa
* k‰ynnin j‰lkeen.
*
* T‰ss‰ funktiossa kutsutaan ensin items-instanssin j‰senmetodia listItems,
* jolla listataan tiedostoon kirjatut tavarat. Sen j‰lkeen k‰ytt‰j‰lt‰
* kysyt‰‰n vuokrattavan tavaran tunnus, joka tallennetaan itemId-nimiseen
* merkkijonomuuttujaan.
*
* Sitten kutsutaan items-instanssin rentItem-j‰senmetodia ja parametriksi
* v‰litet‰‰n itemId-muuttujan arvo. Funktiokutsun merkkijonomuotoa oleva
* tulos tallennetaan renting-muuttujaan. Jos tulos on jotakin muuta kuin
* tyhj‰ merkkijono, tulostetaan viesti onnistuneesta vuokraustapahtumasta.
*/
void Menu::borrowItem(Items& items)
{
	items.listItems();

	string itemId;

	cout << "Syˆt‰ vuokrattavan tavaran id: ";
	cin >> itemId;
	cout << endl;

	string renting = items.rentItem(itemId);

	if (renting != "")
	{
		cout << renting << " id:ll‰ " << itemId << " vuokrattu onnistuneesti.\n" << endl;
	}

	printEndLine();
}


/* Funktiolle v‰litet‰‰n parametrina instanssi Items-luokasta
* pass by reference -tyylill‰. Funktiossa kutsutaan ensin items-instanssin
* j‰senmetodia listItems, jolla listataan tiedostoon kirjatut tavarat.
* Sen j‰lkeen k‰ytt‰j‰lt‰ kysyt‰‰n palautettavan tavaran tunnus, joka
* tallennetaan itemId-nimiseen merkkijonomuuttujaan.
*
* Sitten kutsutaan items-instanssin revertItem-j‰senmetodia ja parametriksi
* v‰litet‰‰n itemId-muuttujan arvo. Funktiokutsun merkkijonomuotoa oleva
* tulos tallennetaan reverting-muuttujaan. Jos tulos on jotakin muuta kuin
* tyhj‰ merkkijono, tulostetaan viesti onnistuneesta palautustapahtumasta.
*/
void Menu::returnItem(Items& items)
{
	items.listItems();

	string itemId;

	cout << "Syˆt‰ palautettavan tavaran id: ";
	cin >> itemId;
	cout << endl;

	string reverting = items.revertItem(itemId);

	if (reverting != "")
	{
		cout << reverting << " id:ll‰ " << itemId << " palautettu onnistuneesti.\n" << endl;
	}

	printEndLine();
}


/* Funktiolle v‰litet‰‰n parametrina instanssi Items-luokasta
* pass by reference -tyylill‰. K‰ytt‰j‰lt‰ kysyt‰‰n lis‰tt‰v‰n tavaran nimi,
* joka tallennetaan itemName-merkkijonomuuttujaan. K‰ytt‰j‰n syˆtteen
* k‰sittelyss‰ hyˆdynnet‰‰n string-kirjaston ignore- ja getline-metodeja,
* jotta k‰ytt‰j‰ pystyy syˆtt‰m‰‰n tavaran, jonka nimeen sis‰ltyy
* v‰lilyˆntej‰.
*
* Jos k‰ytt‰j‰n antama syˆte on tyhj‰ merkkijono, kerrotaan k‰ytt‰j‰lle,
* ettei tavaraa voida lis‰t‰ ja poistutaan funktiosta paluuarvolla 2.
* Muussa tapauksessa k‰ytt‰j‰lt‰ kysyt‰‰n kategoria, ja kokonaislukuna
* annettu syˆte tallennetaan category-muuttujaan. Jos syˆte on 0 tai
* pienempi eli joko v‰‰r‰nlainen kokonaisluku tai kokonaan v‰‰r‰‰ muotoa,
* poistutaan funktiosta handleError-j‰senmetodikutsulla, joka palauttaa 
* virheest‰ kertovan kokonaisluvun.
*
* Muussa tapauksessa tallennetaan appendableItem-muuttujaan instanssi
* Item-luokasta, ja instanssille syˆtet‰‰n parametreiksi itemName- ja
* category-muuttujiin talletetut arvot sek‰ totuusarvo false, jolla
* indikoidaan, ett‰ lis‰tty tavara on oletusarvoisesti vapaa. Sen j‰lkeen
* size_t-tietotyyppi‰ olevaan muuttujaan appending tallennetaan
* items-parametrin j‰senmetodin appendItem palauttama arvo. appendItem-metodin
* parametrina v‰litet‰‰n appendableItem.

* Palautettu arvo k‰sitell‰‰n ehtolauseella. Jos se on suurempi kuin nolla,
* tulostetaan viesti tavaran onnistuneesta lis‰‰misest‰. Lopuksi poistutaan
* funktiosta paluuarvolla 0.
*/
int Menu::addItem(Items& items)
{
	printEndLine();

	string itemName;
	int category;

	cout << "Syˆt‰ tavaran nimi (v‰lt‰ skandinaavisia kirjaimia): ";
	cin.ignore();
	getline(cin, itemName);
	cout << endl;

	if (itemName == "")
	{
		cout << "Tavaraa ei voida lis‰t‰, koska sit‰ ei ole nimetty.\n" << endl;
		printEndLine();
		return 2;
	}

	cout << "Syˆt‰ tavaran kategoria (1 -> sukset, 2 -> sauvat, 3 -> monot, 4 -> muu): ";
	cin >> category;
	cout << endl;

	if (category <= 0)
	{
		return handleError();
	}
	else
	{
		Item appendableItem = Item(itemName, category, false);
		size_t appending = items.appendItem(appendableItem);
		if (appending > 0)
		{
			cout << itemName << " lis‰tty j‰rjestelm‰‰n onnistuneesti id:ll‰ " << appending << "\n" << endl;
		}
		printEndLine();
		return 0;
	}
}


/* Funktiolle v‰litet‰‰n parametrina instanssi Items-luokasta
* pass by reference -tyylill‰. Funktiossa kutsutaan ensin items-instanssin
* j‰senmetodia listItems, jolla listataan tiedostoon kirjatut tavarat. Sitten
* k‰ytt‰j‰lt‰ kysyt‰‰n lis‰tt‰v‰n tavaran tunnus, joka tallennetaan
* itemId-merkkijonomuuttujaan.
*
* Sen j‰lkeen kutsutaan items-instanssin removeItem-j‰senmetodia ja
* parametriksi v‰litet‰‰n itemId-muuttujan arvo. Funktiokutsun
* merkkijonomuotoa oleva tulos tallennetaan removing-muuttujaan. Jos tulos
* on jotakin muuta kuin tyhj‰ merkkijono, tulostetaan viesti onnistuneesta
* poistamistapahtumasta.
*/
void Menu::deleteItem(Items& items)
{
	items.listItems();

	string itemId;

	cout << "Syˆt‰ poistettavan tavaran id: ";
	cin >> itemId;
	cout << endl;

	string removing = items.removeItem(itemId);

	if (removing != "")
	{
		cout << removing << " poistettu j‰rjestelm‰st‰ onnistuneesti id:ll‰ " << itemId << "\n" << endl;
	}

	printEndLine();
}


/* Funktio, joka k‰ynnist‰‰ hiihtotarvikkeiden hallinnointiohjelman.
* Tervehtemistulosteen j‰lkeen siirryt‰‰n while-silmukkaan, joka
* pyˆrii loppumattomasti (true), kunnes k‰ytt‰j‰ valitsee ehdon, jolla
* kutsutaan break-avainsanaa.
*
* Jokaisella silmukan kierroksella tulostetaan valikko ja pyydet‰‰n
* k‰ytt‰j‰‰ syˆtt‰m‰‰n valinta. Valinta tallennetaan choice-j‰senmuuttujaan,
* jonka arvoa vertaillaan lukuihin 1-7. Jos valinta t‰sm‰‰ johonkin n‰ist‰
* luvuista, toteutetaan ko. ehtoon liittyv‰t toiminnot tai funktiokutsu. 
* 
* Muussa tapauksessa palautetaan funktio, joka k‰sittelee virheellisen 
* syˆtteen ja paluttaa virheest‰ kertovan kokonaisluvun lopettaen ohjelman. 
* Jos ohjelma lopetetaan k‰ytt‰j‰n valinnasta, silmukasta poistumisen j‰lkeen 
* palautetaan kokonaisluku 0 merkkin‰ ohjelman onnistuneesta ajosta. 
*/
int Menu::start()
{
	cout << "Tervetuloa hiihtotarvikkeiden yll‰pitoj‰rjestelm‰‰n!\n" << endl;

	while (true)
	{
		cout << "Mit‰ haluat tehd‰? " << endl;
		cout << "1 -> Listaa tavarat" << endl;
		cout << "2 -> Listaa yksitt‰isen kategorian tavarat" << endl;
		cout << "3 -> Vuokraa tavara" << endl;
		cout << "4 -> Palauta tavara" << endl;
		cout << "5 -> Lis‰‰ tavara" << endl;
		cout << "6 -> Poista tavara" << endl;
		cout << "7 -> Poistu j‰rjestelm‰st‰\n" << endl;

		cout << "Syˆt‰ valintasi: ";
		cin >> this->choice;
		cout << endl;

		if (this->choice == 1)
		{
			// Kutsutaan metodia, joka listaa tavarat:
			this->items.listItems();
		}
		else if (this->choice == 2)
		{
			int categoryListing = listItemsByCategory();
			if (categoryListing != 0)
			{
				return categoryListing;
			}

		}
		else if (this->choice == 3)
		{
			/* Kutsutaan metodia, joka vaihtaa tiedostosta lˆytyv‰n
			* vuokrauksen tilasta kertovan arvon arvosta 0 arvoon 1.
			* Funktiossa selvitet‰‰n edelt‰v‰sti tavaran tunnus, jotta
			* statuksen vaihto voidaan toteuttaa.
			*/
			borrowItem(this->items);
		}
		else if (this->choice == 4)
		{
			/* Kutsutaan metodia, joka vaihtaa tiedostosta lˆytyv‰n
			* vuokrauksen tilasta kertovan arvon arvosta 1 arvoon 0.
			* Funktiossa selvitet‰‰n edelt‰v‰sti tavaran tunnus, jotta
			* statuksen vaihto voidaan toteuttaa.
			*/
			returnItem(this->items);
		}
		else if (this->choice == 5)
		{
			/* Tallennetaan muuttujaan tavaran lis‰‰v‰n funktion palauttama
			* arvo, joka voi olla 0-2.
			*/
			int additionEvent = addItem(this->items);

			/* Jos addItem-metodin palauttama arvo on 1, poistutaan ohjelmasta
			* virheest‰ kertovalla kokonaislukuarvolla.
			*/
			if (additionEvent == 1)
			{
				return 1;
			}
			/* Jos metodin palauttama arvo on 0 tai 2, jatketaan silmukassa 
			* seuraavaalle iteraatiokierrokselle.
			*/
			else
			{
				continue;
			}
		}
		else if (this->choice == 6)
		{
			/* Kutsutaan metodia, jolle syˆtet‰‰n parametriksi
			* items-j‰senmuuttujaan talletettu instanssi Items-luokasta.
			* Metodissa kysyt‰‰n poistettavan tavaran id, jonka perusteella
			* tavara poistetaan tiedostosta.
			*/
			deleteItem(this->items);
		}
		else if (this->choice == 7)
		{
			printEndLine();

			cout << "Kiitos ohjelman k‰ytˆst‰!" << endl;

			// Poistutaan silmukasta break-avainsanan avulla: 
			break;
		}
		else
		{
			/* Palautetaan handleError-metodin palauttama kokonaislukuarvo,
			* ja poistutaan ohjelmasta.
			*/
			return handleError();
		}
	}

	return 0;
}