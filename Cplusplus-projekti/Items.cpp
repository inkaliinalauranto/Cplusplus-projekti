#include "Items.h"

#include "Item.h"
#include <iostream> 
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Pass by reference
void Items::readFileToRows(const string filename, vector<string>& rows)
{
	string row;
	ifstream fileReading = ifstream(filename);

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


int Items::setSize(vector<string> rows)
{
	int size = 0;

	if (!rows.empty())
	{
		size = (int)rows.size();
	}

	return size;
}


Items::Items()
{
	ifstream itemsFileForReading = ifstream("items_file.txt");

	/* Jos items_file.txt-tiedostoa ei viel‰ ole olemassa eli jos ohjelma
	* ajetaan ensimm‰isen kerran, luodaan tiedosto ja lis‰t‰‰n siihen
	* silmukassa items-taulukon alkioiden tiedot.
	*/
	if (!itemsFileForReading.good())
	{
		ofstream itemsFile = ofstream("items_file.txt");
		/* Lis‰t‰‰n demotarkoituksessa oletusrakentajassa kolmen alkion
		* mittaiseen items-taulukkoon kolme tavaraa:
		*/
		for (int i = 0; i < 3; i++)
		{
			int id = i + 1;
			itemsFile
				<< items[i].getName() << "\n"
				<< items[i].getId() << "\n"
				<< items[i].getCategory() << "\n"
				<< items[i].getRentalState() << "\n";
		}
		itemsFile.close();
	}

	itemsFileForReading.close();
}


void Items::listItems()
{
	cout << "----- Kaikki tavarat ------\n" << endl;
	//for (int i = 0; i < 3; i++)
	//{
	//	cout << i + 1 << "." << endl;
	//	items[i].printInformation();
	//}

	//cout << endl;

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


string Items::rentItem(string id)
{
	string row;
	vector<string> rows;

	/* Luetaan tiedoston sis‰ltˆ rows-muuttujaan hyˆdynt‰m‰ll‰ 
	* pass by reference -tekniikkaa:
	*/
	readFileToRows(this->fileName, rows);

	int rowsSize = setSize(rows);
	int indexOfItemName = rowsSize;
	string itemName = "";
	int indexOfValueToBeChanged = rowsSize;
	bool isIdInFile = false;
	bool isAlreadyRented = false;

	// Varsinainen varaaminen:
	ofstream itemsFileForWriting = ofstream("items_file.txt");

	if (itemsFileForWriting.fail())
	{
		cout << "Ohjelmassa tapahtui virhetilanne - tiedostoon ei voi kirjoittaa.\n" << endl;
	}
	else if (rows.size() >= 4 && rows.size() % 4 == 0)
	{
		for (int i = 1; i < rows.size(); i += 4)
		{
			if (rows[i] == id)
			{
				indexOfItemName = i - 1;
				indexOfValueToBeChanged = i + 2;
				isIdInFile = true;
			}
		}

		for (int idx = 0; idx < rows.size(); idx++)
		{
			if (idx == indexOfValueToBeChanged)
			{
				if ((bool)stoi(rows[idx]) == true)
				{
					isAlreadyRented = true;
					cout << "Tavara on jo varattu, ei vuokrattavissa.\n" << endl;
				}
				else
				{
					rows[idx] = to_string(true);
				}
			}
			else if (idx == indexOfItemName)
			{
				itemName = rows[indexOfItemName];
			}
			itemsFileForWriting << rows[idx] << endl;
		}
	}
	else
	{
		cout << "Tiedosto on tyhj‰ tai siin‰ olevat tiedot ovat puutteellisia.\n" << endl;
	}

	itemsFileForWriting.close();

	if (!isIdInFile)
	{
		cout << "Tavaraa syˆtt‰m‰ll‰si tunnuksella ei lˆydy j‰rjestelm‰st‰.\n" << endl;
		return "";
	}
	else if (isAlreadyRented)
	{
		return "";
	}
	else
	{
		return itemName;
	}
}


string Items::revertItem(string id)
{
	string row;
	vector<string> rows;

	bool isIdInFile = false;
	bool isAlreadyReverted = false;

	/* Luetaan tiedoston sis‰ltˆ rows-muuttujaan hyˆdynt‰m‰ll‰
	* pass by reference -tekniikkaa:
	*/
	readFileToRows(this->fileName, rows);

	int rowsSize = 0;
	if (!rows.empty())
	{
		rowsSize = (int)rows.size();
	}

	int indexOfItemName = rowsSize;
	string itemName = "";
	int IndexOfValueToBeChanged = rowsSize;

	// Varsinainen palauttaminen:
	ofstream itemsFileForWriting = ofstream("items_file.txt");

	if (itemsFileForWriting.fail())
	{
		cout << "Ohjelmassa tapahtui virhetilanne - tiedostoon ei voi kirjoittaa.\n" << endl;
	}
	else if (rows.size() >= 4 && rows.size() % 4 == 0)
	{
		for (int i = 1; i < rows.size(); i += 4)
		{
			if (rows[i] == id)
			{
				indexOfItemName = i - 1;
				IndexOfValueToBeChanged = i + 2;
				isIdInFile = true;
			}
		}

		for (int idx = 0; idx < rows.size(); idx++)
		{
			if (idx == IndexOfValueToBeChanged)
			{
				if ((bool)stoi(rows[idx]) == false)
				{
					isAlreadyReverted = true;
					cout << "Tavara on jo palautettu.\n" << endl;
				}
				else
				{
					rows[idx] = to_string(false);
				}
			}
			else if (idx == indexOfItemName)
			{
				itemName = rows[indexOfItemName];
			}
			itemsFileForWriting << rows[idx] << endl;
		}
	}
	else
	{
		cout << "Tiedosto on tyhj‰ tai siin‰ olevat tiedot ovat puutteellisia.\n" << endl;
	}

	itemsFileForWriting.close();

	if (!isIdInFile)
	{
		cout << "Tavaraa syˆtt‰m‰ll‰si tunnuksella ei lˆydy j‰rjestelm‰st‰.\n" << endl;
		return "";
	}
	else if (isAlreadyReverted)
	{
		return "";
	}
	else
	{
		return itemName;
	}
}


size_t Items::appendItem(Item item)
{
	/* Lis‰t‰‰n items_file.txt-tiedoston loppuun teksti‰ antamalla
	* ofstream-instanssille toiseksi parametriksi
	* ios_base::app | ios_base::out. Tekstiksi lis‰t‰‰n uuden tavaran
	* tiedot, jotka saadaan v‰litetyn item-parametrin getter-metodeilla.
	*/
	ofstream itemsFile = ofstream("items_file.txt", ios_base::app | ios_base::out);

	if (itemsFile.fail())
	{
		cout << "Ohjelmassa tapahtui virhetilanne - tiedostoon ei voi kirjoittaa.\n" << endl;
		return -1;
	}
	else
	{
		itemsFile
			<< item.getName() << "\n"
			<< item.getId() << "\n"
			<< item.getCategory() << "\n"
			<< item.getRentalState() << "\n";

		itemsFile.close();
		return item.getId();
	}
}


string Items::removeItem(string id)
{
	string row;
	vector<string> rows;
	bool isIdInFile = false;

	// Pass by reference:
	readFileToRows(this->fileName, rows);

	// Varsinainen poisto:
	int rowsSize = 0;

	if (!rows.empty())
	{
		rowsSize = (int)rows.size();
	}

	string itemName = "";
	int firstRemovableIndex = rowsSize;
	int secondRemovableIndex = rowsSize + 1;
	int thirdRemovableIndex = rowsSize + 2;
	int fourthRemovableIndex = rowsSize + 3;

	ofstream itemsFileForWriting2 = ofstream("items_file.txt");

	if (itemsFileForWriting2.fail())
	{
		cout << "Ohjelmassa tapahtui virhetilanne - tiedostoon ei voi kirjoittaa.\n" << endl;
	}
	else if (rows.size() >= 4 && rows.size() % 4 == 0)
	{
		for (int i = 1; i < rows.size(); i += 4)
		{
			if (rows[i] == id)
			{
				//cout << "Poistettavat indeksit: ";
				firstRemovableIndex = i - 1;
				secondRemovableIndex = i;
				thirdRemovableIndex = i + 1;
				fourthRemovableIndex = i + 2;
				//cout << firstRemovableIndex << ", ";
				//cout << secondRemovableIndex << ", ";
				//cout << thirdRemovableIndex << ", ";
				//cout << fourthRemovableIndex << endl;
				isIdInFile = true;
			}
		}

		for (int idx = 0; idx < rows.size(); idx++)
		{
			if (idx != firstRemovableIndex && idx != secondRemovableIndex && idx != thirdRemovableIndex && idx != fourthRemovableIndex)
			{
				itemsFileForWriting2 << rows[idx] << endl;
			}
			else if (idx == firstRemovableIndex)
			{
				itemName = rows[firstRemovableIndex];
			}
		}
	}
	else
	{
		cout << "Tiedosto on tyhj‰ tai siin‰ olevat tiedot ovat puutteellisia.\n" << endl;
		return "";
	}

	itemsFileForWriting2.close();

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