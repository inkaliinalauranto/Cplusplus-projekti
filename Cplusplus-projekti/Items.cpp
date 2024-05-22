#include "Items.h"

#include "Item.h"
#include <iostream> 
#include <fstream>
#include <string>
#include <vector>

using namespace std;


Items::Items()
{
	ifstream itemsFileForReading = ifstream("items_file.txt");

	/* Jos items_file.txt-tiedostoa ei vielä ole olemassa eli jos ohjelma
	* ajetaan ensimmäisen kerran, luodaan tiedosto ja lisätään siihen 
	* silmukassa items-taulukon alkioiden tiedot.
	*/
	if (!itemsFileForReading.good())
	{
		ofstream itemsFile = ofstream("items_file.txt");
		/* Lisätään demotarkoituksessa oletusrakentajassa kolmen alkion 
		* mittaiseen items-taulukkoon kolme tavaraa:
		*/
 		this->items[0] = Item("Rossignol Xium", 1, false);
		this->items[1] = Item("Leki HRC", 2, false);
		this->items[2] = Item("Ficher Speedmax Skate", 3, false);

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

}


void Items::appendItem(Item item)
{
	/* Lisätään items_file.txt-tiedoston loppuun tekstiä antamalla 
	* ofstream-instanssille toiseksi parametriksi 
	* ios_base::app | ios_base::out. Tekstiksi lisätään uuden tavaran 
	* tiedot, jotka saadaan välitetyn item-parametrin getter-metodeilla.
	*/
	ofstream itemsFile = ofstream("items_file.txt", ios_base::app | ios_base::out);
	// Tästä voi miettiä, tekiskö oman funkkarin, pohjana ylempi looppi.
	itemsFile
		<< item.getName() << "\n"
		<< item.getId() << "\n"
		<< item.getCategory() << "\n"
		<< item.getRentalState() << "\n";

	itemsFile.close();
}


void Items::removeItem(string id)
{
	string row;
	vector<string> rows;
	bool isIdInFile = false;

	ifstream itemsFileForReading2 = ifstream("items_file.txt");

	if (itemsFileForReading2.good())
	{
		while (getline(itemsFileForReading2, row))
		{
			rows.push_back(row);
		}
	}
	else
	{
		cout << "Ohjelmassa tapahtui virhetilanne: tiedostoa ei ole olemassa." << endl;
	}

	itemsFileForReading2.close();


	// Varsinainen poisto:
	int rowsSize = 0;

	if (!rows.empty())
	{
		rowsSize = (int)rows.size();
	}

	int firstRemovableIndex = rowsSize;
	int secondRemovableIndex = rowsSize + 1;
	int thirdRemovableIndex = rowsSize + 2;
	int fourthRemovableIndex = rowsSize + 3;

	ofstream itemsFileForWriting2 = ofstream("items_file.txt");

	if (itemsFileForWriting2.fail())
	{
		cout << "Ohjelmassa tapahtui virhetilanne - tiedostoon ei voi kirjoittaa." << endl;
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
		}
	}
	else
	{
		cout << "Tiedosto on tyhjä tai siinä olevat tiedot ovat puutteellisia." << endl;
	}

	itemsFileForWriting2.close();

	if (!isIdInFile)
	{
		cout << "Tavaraa syöttämälläsi tunnuksella ei löydy järjestelmästä." << endl;
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

	ifstream itemsFileForReading3 = ifstream("items_file.txt");

	int index = 0;
	int itemOrdinary = 1;

	while (getline(itemsFileForReading3, row))
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

	itemsFileForReading3.close();

	cout << "---------------------------" << endl;
}


void Items::rentItem(string id)
{
	string row;
	vector<string> rows;
	bool isIdInFile = false;

	ifstream itemsFileForReading = ifstream("items_file.txt");

	if (itemsFileForReading.good())
	{
		while (getline(itemsFileForReading, row))
		{
			rows.push_back(row);
		}
	}
	else
	{
		cout << "Ohjelmassa tapahtui virhetilanne: tiedostoa ei ole olemassa." << endl;
	}

	itemsFileForReading.close();

	int rowsSize = 0;
	if (!rows.empty())
	{
		rowsSize = (int)rows.size();
	}

	int IndexOfValueToBeChanged = rowsSize;

	// Varsinainen varaaminen:
	ofstream itemsFileForWriting = ofstream("items_file.txt");

	if (itemsFileForWriting.fail())
	{
		cout << "Ohjelmassa tapahtui virhetilanne - tiedostoon ei voi kirjoittaa." << endl;
	}
	else if (rows.size() >= 4 && rows.size() % 4 == 0)
	{
		for (int i = 1; i < rows.size(); i += 4)
		{
			if (rows[i] == id)
			{
				IndexOfValueToBeChanged = i + 2;
				isIdInFile = true;
			}
		}

		for (int idx = 0; idx < rows.size(); idx++)
		{
			if (idx == IndexOfValueToBeChanged)
			{
				if ((bool)stoi(rows[idx]) == true)
				{
					cout << "Tavara on jo varattu, eikä sitä voi varata." << endl;
				}
				else
				{
					rows[idx] = to_string(true);
				}
			}
			itemsFileForWriting << rows[idx] << endl;
		}
	}
	else
	{
		cout << "Tiedoston on tyhjä tai siinä olevat tiedot ovat puutteellisia." << endl;
	}

	itemsFileForWriting.close();
	if (!isIdInFile)
	{
		cout << "Tavaraa syöttämälläsi tunnuksella ei löydy järjestelmästä." << endl;
	}
}