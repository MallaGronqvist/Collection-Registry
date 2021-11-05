// SubCollectionItem2.cpp
// Author: Malla Grönqvist
// Date: 28.05.2021
//******************************************************************************************

#include "SubCollectionItem2.h"
#include <vector>
using std::vector;
#include <string>
using std::to_string;
using std::getline;
#include <sstream>
using std::istringstream;
#include <random>
#include <ctime>

void SubCollectionItem2::setItemFields(string pString) {

	vector<string>tempVector;
	string tempString;
	istringstream iss(pString);
	char delim = '|';

	while (getline(iss, tempString, delim)) {
		tempVector.push_back(tempString);
	}

	_itemID = tempVector[1];
	_recordTitle = tempVector[2];
	_authorName = tempVector[3];
	_releaseYear = stoi(tempVector[4]);
}

void SubCollectionItem2::insertInfo() {

	string tempTitle, tempAuthor;

	cout << "Insert record title:";
	getline(cin, tempTitle);
	_recordTitle = tempTitle;

	cout << "Insert name of author: ";
	getline(cin, tempAuthor);
	_authorName = tempAuthor;

	bool again = true;
	do {
		int tempYear;
		cout << "Insert release year: ";
		cin >> tempYear;

		if ((cin.fail()) || (cin.fail() || tempYear < 1860 || tempYear > 2021)) {
			cin.clear();
			// discard remaining unprocessed characters in the input stream
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid input. Press enter to try again." << endl;
			cin.get();
		}
		else {
			_releaseYear = tempYear;
			again = false;
		}
	} while (again);

	cin.get();	
}

string SubCollectionItem2::show() {

	const string DELIM = "|";

	return string(_itemType + " " + DELIM + _itemID + DELIM + _recordTitle + DELIM + _authorName + DELIM
	+ to_string(_releaseYear) + DELIM );
}

void SubCollectionItem2::assignID() {
	
	const int MAX = 999;
	std::srand(std::time(nullptr));
	int randomNumber = rand() % MAX;

	string numbers;

	if (randomNumber > 100) {			// Convert numbers to string and add zero(s).

		numbers = to_string(randomNumber);

	} else if (100 > randomNumber && randomNumber > 10) {

		numbers = "0" + to_string(randomNumber);

	} else if (randomNumber < 10) {

		numbers = "00" + to_string(randomNumber);
	}

	_itemID = "M" + numbers;
}