// CollectionRegistry.tpl
// Author: Malla Grönqvist
// Date: 28.05.2021
// Description: Template class for holding and handling a catalogue of books, plant and music records.
//******************************************************************************************************

#pragma once
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::fstream;
#include <sstream>
using std::stringstream;
#include <algorithm>
#include "SubCollectionItem1.h"
#include "SubCollectionItem2.h"
#include "SubCollectionItem3.h"

template <class T>
class CollectionRegistry
{
private:
	vector< T* >_pCollectionReg;
	vector<string>_usedIDs;
	int _countBooks;
	int _countMusicRecords;
	int _countPlants;
	const int MAX_NUMBER_ITEMS_PER_TYPE = 300;
	const string FILENAME = "CollectionRegistry.txt";
public:
	CollectionRegistry(){ _countBooks = 0, _countMusicRecords = 0, _countPlants = 0; }
	~CollectionRegistry();
	void addItem(T* pItem);
	void showOneItem();
	void showItems();
	void showItemsOfAType(string pType);
	void saveReg();
	bool loadReg();
	void removeItem();
	void removeAllItems();	
	void searchForItem();
	void sortAscendingOrder();
	void sortDescendingOrder();
	static bool compare(string pString, T* pItem);
	static bool compareID(string pString, T* pItem);
	static bool sortAscending(T* pItem1, T* pItem2);
	static bool sortDescending(T* pItem1, T* pItem2);
	static void waitForEnter();

	bool checkMaxNumberBooks() { return _countBooks == MAX_NUMBER_ITEMS_PER_TYPE; }
	bool checkMaxNumberMusicRecords() { return _countMusicRecords == MAX_NUMBER_ITEMS_PER_TYPE; }
	bool checkMaxNumberPlants() { return _countPlants == MAX_NUMBER_ITEMS_PER_TYPE; }
};

// Destructor for removing pointers and dynamically allocated objects.
template <class T>
CollectionRegistry<T>::~CollectionRegistry() {

	for (int index = 0; index < _pCollectionReg.size(); ++index) {

		delete _pCollectionReg[index];  // Destruct objects and deallocate memory.
	}

	_pCollectionReg.clear();	// Remove pointers.
}

// Adds and item to the registry, gives it an ID and counts it.
template <class T>
void CollectionRegistry<T>::addItem(T* pItem) {

	pItem->assignID();
	string IDcheck = pItem->getID();

	// Check if ID is already in use.
	while (find(_usedIDs.begin(), _usedIDs.end(), IDcheck) != _usedIDs.end()) {		
		pItem->assignID();		// If ID is already in use, assign a new one.
		IDcheck = pItem->getID();
	}

	// Check item type and count it.
	string type = pItem->getItemType();

	if (type == "Book") {
		_countBooks++;

	} else if (type == "Music Record") {
		_countMusicRecords++;

	} else if (type == "Plant") {
		_countPlants++;
	}

	// Add item to registry.
	_pCollectionReg.push_back(pItem);	
	
	cout << endl << "Item was added to the registry." << endl;
	waitForEnter();
}

// Shows an item by ID.
template <class T>
void CollectionRegistry<T>::showOneItem() {
	
	cout << "Enter item ID: ";
	string searchTerm;
	getline(cin, searchTerm);

	auto searchIT = _pCollectionReg.begin();

	// First check if item exists. If it doesn't, print info to user.
	if (find_if(_pCollectionReg.begin(), _pCollectionReg.end(), [searchTerm](T* item) 
	{ return compareID(searchTerm, item);}) == _pCollectionReg.end()) {

		cout << "No item was found with ID: " << searchTerm << endl;

	} else if((searchIT = find_if(_pCollectionReg.begin(), _pCollectionReg.end(), [searchTerm](T* item) 
	{ return compareID(searchTerm, item);})) != _pCollectionReg.end()) {

		cout << "Item found with ID: " << searchTerm << endl
		<< (**searchIT).show() << endl;
	}

	waitForEnter();
}

// Prints all items in registry.
template <class T>
void CollectionRegistry<T>::showItems() {

	for (const auto& item: _pCollectionReg) {
        cout << item->show() << endl;
	}

	waitForEnter();
}

// Shows items of a specific type.
template <class T>
void CollectionRegistry<T>::showItemsOfAType(string pType) {

	for (const auto& item: _pCollectionReg) {
	
		if (item->getItemType() == pType) {
			cout << item->show() << endl;
		}
	}

	waitForEnter();
}

// Saves registry to a textfile.
template <class T>
void CollectionRegistry<T>::saveReg() {

	try {

		fstream outFile(FILENAME, std::ios::out); // Open file for writing.

		if (outFile.is_open()) {
    
			for (const auto& item: _pCollectionReg) {
				outFile << item->show() << endl;
			}

			outFile.close(); // Close the file.

			cout << "Collection Registry was saved to file." << endl;

		} else {

			throw string("Error. Unable to open file for saving.");
		}

	} catch (string error) {
		cout << error << endl;
	}

	waitForEnter();
}

// Loads registry from a textfile.
template <class T>
bool CollectionRegistry<T>::loadReg() {

	try {

		fstream inFile;
		inFile.open(FILENAME, std::ios::in);
		string buffer;

		if (inFile.is_open()) {

			while (!inFile.eof()) {  // Read in until end of file.

				if (getline(inFile, buffer)) {
					string itemType;
					stringstream ss(buffer);
					ss>> itemType;

					if (itemType == "Book") {
						T* item = new SubCollectionItem1;
						item->setItemFields(buffer);
						_usedIDs.push_back(item->getID());
						_pCollectionReg.push_back(item);

					} else if (itemType == "Music") {
						T* item = new SubCollectionItem2;
						item->setItemFields(buffer);
						_usedIDs.push_back(item->getID());
						_pCollectionReg.push_back(item);

					} else if (itemType == "Plant") {
						T* item = new SubCollectionItem3;
						item->setItemFields(buffer);
						_usedIDs.push_back(item->getID());
						_pCollectionReg.push_back(item);
					}
				}
			}

			cout << "The Collection Registry was loaded from file." << endl;

			inFile.close();

			waitForEnter();

			return true;

		} else {
		
			throw string("Error. The program was unable to open file for loading.");
		}

	} catch (string error) {
		
		cout << error << endl;

		return false;
	}	
}

// Removes an item by ID.
template <class T>
void CollectionRegistry<T>::removeItem() {

	cout << "Enter ID of the item you want to remove: ";
	string searchTerm;
	getline(cin, searchTerm);

	// First search for item in registry.
	auto position = find_if(_pCollectionReg.begin(), _pCollectionReg.end(), [searchTerm](T* item) 
	{ return compareID(searchTerm, item);});

	// If item was found, erase its ID from used IDs and adjust count.
	if (position != _pCollectionReg.end()) {

		string tempID = (**position).getID();
		auto it = find(_usedIDs.begin(), _usedIDs.end(), tempID);

		if (it != _usedIDs.end()) {
		_usedIDs.erase(it);
		}

		string itemType = (**position).getItemType();
		if (itemType == "Book") {
			_countBooks--;

		} else if (itemType == "Music Record") {
			_countMusicRecords--;

		} else if (itemType == "Plant") {
			_countPlants--;
		}

		// Then erase item from registry.

		cout << "Item with ID " << searchTerm << ":" << endl
		<< (**position).show() << endl
		<< "Item was deleted." << endl << endl;
		
		_pCollectionReg.erase(position);

	} else {
	
		cout << "No item was found with item ID: " << searchTerm << endl << endl;
	}

	waitForEnter();
}

// Removes all items from registry.
template <class T>
void CollectionRegistry<T>::removeAllItems() {

	for (int index = 0; index < _pCollectionReg.size(); ++index) {
		delete _pCollectionReg[index];  // Destruct objects and deallocate memory.
	}

	_pCollectionReg.clear();	// Remove pointers.

	_usedIDs.clear();	// Remove used IDs.

	_countBooks = 0;	// Set item counts to zero.
	_countMusicRecords = 0;
	_countPlants = 0;

	cout << "All items were removed from the Collection Registry." << endl << endl;

	waitForEnter();
}

// Searches for an item in registry by any user input.
template <class T>
void CollectionRegistry<T>::searchForItem() {

	cout<< "Enter search term (for ex. title, author, or ID: ";
	string searchTerm;
	getline(cin, searchTerm);

	// If no item is found, print info to user.
	if (find_if(_pCollectionReg.begin(), _pCollectionReg.end(), [searchTerm](T* item) 
	{ return compare(searchTerm, item);}) == _pCollectionReg.end()) {

		cout << "No item was found with the search term: " << searchTerm << endl << endl;

	} else {	// Otherwise iterate over registry and print all matches.

		auto searchIT = _pCollectionReg.begin();

		while ((searchIT = find_if(searchIT, _pCollectionReg.end(), [searchTerm](T* item) 
		{ return compare(searchTerm, item);})) != _pCollectionReg.end()) {

			cout << "Item found with the search term: " << searchTerm << endl
			<< (**searchIT).show() << endl;
			searchIT++;
		}
	}

	waitForEnter();
}

// Predicate function for find_if in SearchForItem().
template <class T>
bool CollectionRegistry<T>::compare(string pString, T* pItem) {

	string tempString;
	tempString = pItem->show();

	// Convert strings to uppercase for non case-sensitive comparison.
	for (auto & c: tempString) c = toupper(c);
	for (auto & c: pString) c = toupper(c);

	auto found = tempString.find(pString);

	return (found != string::npos);
}

// Predicate function for find_if in removeItem().
template <class T>
bool CollectionRegistry<T>::compareID(string pString, T* pItem) {

	// Convert to uppercase for non case-sensitive comparison.
	for (auto & c: pString) c = toupper(c);

	return (pString == pItem->getID());
}

// Sorts all items in registry by ID in ascending order.
template <class T>
void CollectionRegistry<T>::sortAscendingOrder() {

	sort(_pCollectionReg.begin(), _pCollectionReg.end(), sortAscending);

	cout << "Items were sorted by ID in ascending order." << endl << endl;

	waitForEnter();
}

// Predicate function for sorting in ascending order.
template <class T>
bool CollectionRegistry<T>::sortAscending(T* pItem1, T* pItem2) {

	string ID1, ID2;
	ID1 = pItem1->getID();
	ID2 = pItem2->getID();

	return ID1 < ID2;
}

// Sorts all items in registry by ID in descending order.
template <class T>
void CollectionRegistry<T>::sortDescendingOrder() {

	sort(_pCollectionReg.begin(), _pCollectionReg.end(), sortDescending);

	cout << "Items were sorted by ID in descending order." << endl << endl;

	waitForEnter();
}

// Predicate function for sorting in descending order.
template <class T>
bool CollectionRegistry<T>::sortDescending(T* pItem1, T* pItem2) {

	string ID1, ID2;
	ID1 = pItem1->getID();
	ID2 = pItem2->getID();

	return ID1 > ID2;
}

template <class T>
void CollectionRegistry<T>::waitForEnter() {
	cout << "Press ENTER to continue." << endl;
	cin.get();
}




