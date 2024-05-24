#include "Items.h"

#include "Item.h"
#include <iostream> 
#include <fstream>
#include <string>
#include <vector>

using namespace std;


Items::Items()
{
	ifstream itemsFileForReading = ifstream(this->fileName);

	/* Jos items_file.txt-tiedostoa ei vielä ole olemassa eli jos ohjelma
	* ajetaan ensimmäisen kerran, luodaan tiedosto ja lisätään siihen
	* silmukassa items-taulukon alkioiden tiedot.
	*/
	if (!itemsFileForReading.good())
	{
		ofstream itemsFile = ofstream(this->fileName);
		/* Lisätään demotarkoituksessa oletusrakentajassa kolmen alkion
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

// Pass by reference
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


int Items::setSize(vector<string> rows)
{
	int size = 0;

	if (!rows.empty())
	{
		size = (int)rows.size();
	}

	return size;
}


string Items::changeRentalState(vector<string>& rows, const string id, const bool propertyState, const string emsg)
{
	int rowsSize = setSize(rows);
	int indexOfItemName = rowsSize;
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
		for (int i = 1; i < rows.size(); i += 4)
		{
			if (rows[i] == id)
			{
				indexOfItemName = i - 1;
				indexOfValueToBeChanged = i + 2;
				isIdInFile = true;
			}
		}

		for (int i = 0; i < rows.size(); i++)
		{
			if (i == indexOfValueToBeChanged)
			{
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
		cout << "Tiedosto on tyhjä tai siinä olevat tiedot ovat puutteellisia.\n" << endl;
	}

	fileWriting.close();

	if (!isIdInFile)
	{
		cout << "Tavaraa syöttämälläsi tunnuksella ei löydy järjestelmästä.\n" << endl;
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

	/* Luetaan tiedoston sisältö rows-muuttujaan hyödyntämällä 
	* pass by reference -tekniikkaa:
	*/
	readFileToRows(rows);

	bool propertyState = true;
	string errorMessage = "Tavara on jo varattu, ei vuokrattavissa.\n";

	// Varsinainen varaaminen:
	return changeRentalState(rows, id, propertyState, errorMessage);
}


string Items::revertItem(string id)
{
	string row;
	vector<string> rows;

	/* Luetaan tiedoston sisältö rows-muuttujaan hyödyntämällä
	* pass by reference -tekniikkaa:
	*/
	readFileToRows(rows);

	bool propertyState = false;
	string errorMessage = "Tavara on jo palautettu.\n";

	return changeRentalState(rows, id, propertyState, errorMessage);
}


size_t Items::appendItem(Item item)
{
	/* Lisätään items_file.txt-tiedoston loppuun tekstiä antamalla
	* ofstream-instanssille toiseksi parametriksi
	* ios_base::app | ios_base::out. Tekstiksi lisätään uuden tavaran
	* tiedot, jotka saadaan välitetyn item-parametrin getter-metodeilla.
	*/
	ofstream itemsFile = ofstream(fileName, ios_base::app | ios_base::out);

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

	// Pass by reference:
	readFileToRows(rows);

	// Varsinainen poisto:
	int rowsSize = setSize(rows);
	string itemName = "";
	int firstRemovableIndex = rowsSize;
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
		cout << "Tiedosto on tyhjä tai siinä olevat tiedot ovat puutteellisia.\n" << endl;
	}

	fileWriting.close();

	if (!isIdInFile)
	{
		cout << "Tavaraa syöttämälläsi tunnuksella ei löydy järjestelmästä.\n" << endl;
		return "";
	}
	else
	{
		return itemName;
	}
}