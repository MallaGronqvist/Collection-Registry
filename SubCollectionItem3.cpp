// SubCollectionItem3.cpp
// Author: Malla Grönqvist
// Date: 28.05.2021
//******************************************************************************************

#include "SubCollectionItem3.h"
#include <vector>
using std::vector;
#include <string>
using std::to_string;
using std::getline;
#include <sstream>
using std::istringstream;
#include <random>
#include <ctime>

void SubCollectionItem3::insertInfo() {

	string tempName, tempLatin, tempNote;

	cout << "Insert plant name:";
	getline(cin, tempName);
	_plantName = tempName;

	cout << "Insert latin name: ";
	getline(cin, tempLatin);
	_plantNameLatin = tempLatin;

	cout << "Insert note: ";
	getline(cin, tempNote);
	_note = tempNote;

	cin.get();
}

void SubCollectionItem3::setItemFields(string pString) {

	vector<string>tempVector;
	string tempString;
	istringstream iss(pString);
	char delim = '|';

	while (getline(iss, tempString, delim)) {
		tempVector.push_back(tempString);
	}
	
	_itemID = tempVector[1];
	_plantName = tempVector[2];
	_plantNameLatin = tempVector[3];
	_note = tempVector[4];
}

string SubCollectionItem3::show() {

	const string DELIM = "|";
	
	return string(_itemType + " " + DELIM + _itemID + DELIM + _plantName + DELIM + _plantNameLatin + DELIM
		+ _note + DELIM);
}

void SubCollectionItem3::assignID() {

	const int MAX = 999;
	std::srand(std::time(nullptr));
	int randomNumber = rand() % MAX;

	string numbers;

	if (randomNumber > 100) {					// Convert numbers to string and add zero(s).

		numbers = to_string(randomNumber);

	} else if (100 > randomNumber && randomNumber > 10) {

		numbers = "0" + to_string(randomNumber);

	} else if (randomNumber < 10) {

		numbers = "00" + to_string(randomNumber);
	}

	_itemID = "P" + numbers;
}
