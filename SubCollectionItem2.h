// SubCollectionItem2.h
// Author: Malla Grönqvist
// Date: 28.05.2021
// Description: Holds and handles info about music record items. Sub Class to BaseCollectionItem.
//***********************************************************************************************

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

class SubCollectionItem2 : public BaseCollectionItem {

private:
	string _itemType;
	string _itemID;
	string _recordTitle;
	string _authorName;
	int _releaseYear;
public:
	SubCollectionItem2() {
		_itemType = "Music Record";
		_recordTitle = " ";
		_authorName = " ";
		_releaseYear = 0;
	}
	void setItemID(string pItemID) { _itemID = pItemID; }
	string getID() const { return _itemID; }
	string getItemType() { return _itemType; }
	void assignID();
	void setItemFields(string pString);
	void insertInfo();
	string show();
};


