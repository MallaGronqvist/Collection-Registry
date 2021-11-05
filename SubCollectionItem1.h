// SubCollectionItem1.h
// Author: Malla Grönqvist
// Date: 28.05.2021
// Description: Holds and handles info about book items. Sub Class to BaseCollectionItem.
//******************************************************************************************

#pragma once
#include "BaseCollectionItem.h"
#include<iostream>
#include<string>
using std::ostream;
using std::istream;
using std::cout;
using std::cin;
using std::endl;
using std::string;

class SubCollectionItem1 : public BaseCollectionItem {
	
private:
	string _itemType;
	string _itemID;
	string _bookTitle;
	string _authorName;
	int _publicationYear;
	string _genre;
public:
	SubCollectionItem1() {
		_itemType = "Book";
		_bookTitle = " ";
		_authorName = " ";
		_publicationYear = 0;
		_genre = " ";
	}
	void setItemID(string pItemID) { _itemID = pItemID; }
	string getID() const { return _itemID; }
	string getItemType() { return _itemType; }
	void setItemFields(string pString);
	void assignID();
	void insertInfo();
	string show();
};



