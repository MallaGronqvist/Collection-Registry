// SubCollectionItem1.cpp
// Author: Malla Grönqvist
// Date: 28.05.2021
//******************************************************************************************

#include "SubCollectionItem1.h"
#include <vector>
using std::vector;
#include <string>
using std::to_string;
using std::getline;
#include <sstream>
using std::istringstream;
#include <random>
#include <ctime>

// Function for inserting an item from the UI.
void SubCollectionItem1::insertInfo() {

		string tempTitle, tempAuthor, tempGenre;

		cout << "Insert book title:";
		getline(cin, tempTitle);
		_bookTitle = tempTitle;

		cout << "Insert name of author: ";
		getline(cin, tempAuthor);
		_authorName = tempAuthor;

		cout << "Insert genre: ";
		getline(cin, tempGenre);
		_genre = tempGenre;

		bool again = true;
		do {

			int tempYear;
			cout << "Insert year of publication: ";
			cin >> tempYear;

			if ((cin.fail()) || (cin.fail() || tempYear < 1600 || tempYear > 2021)) {
				cin.clear();
				// discard remaining unprocessed characters in the input stream
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Invalid input. Press enter to try again." << endl;
				cin.get();

			}
			else {
				_publicationYear = tempYear;
				again = false;
			}

		} while (again);

	cin.get();
}

// Function for setting an item's fields with a string parameter.
void SubCollectionItem1::setItemFields(string pString) {

	vector<string>tempVector;
	string tempString;
	istringstream iss(pString);
	char delim = '|';

	while (getline(iss, tempString, delim)) {
		tempVector.push_back(tempString);
	}
	
	_itemID = tempVector[1];
	_bookTitle = tempVector[2];
	_authorName = tempVector[3];
	_publicationYear = stoi(tempVector[4]);
	_genre = tempVector[5];	
}

// Function for printing the item.
string SubCollectionItem1::show() {

	const string DELIM = "|";

	return string(_itemType + " " + DELIM + _itemID + DELIM + _bookTitle + DELIM + _authorName + DELIM
	+ to_string(_publicationYear) + DELIM + _genre + DELIM);
}

// Assigns an ID to the item by combining a letter with three numbers.
void SubCollectionItem1::assignID() {

	const int MAX = 999;
	std::srand(std::time(nullptr));
	int randomNumber = rand() % MAX;

	string numbers;

	if (randomNumber > 100) {	// Convert numbers to string and add zero(s).

		numbers = to_string(randomNumber);

	} else if (100 > randomNumber && randomNumber > 10) {

		numbers = "0" + to_string(randomNumber);

	} else if (randomNumber < 10) {

		numbers = "00" + to_string(randomNumber);
	}

	_itemID = "B" + numbers;
}
