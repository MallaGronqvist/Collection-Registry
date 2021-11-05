// SubCollectionItem3.h
// Author: Malla Grönqvist
// Date: 28.05.2021
// Description: Holds and handles info about plant items. Sub Class to BaseCollectionItem.
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

class SubCollectionItem3 : public BaseCollectionItem {

private:
	string _itemType;
	string _itemID;
	string _plantName;
	string _plantNameLatin;
	string _note;
public:
	SubCollectionItem3() {
		_itemType = "Plant";
		_plantName = " ";
		_plantNameLatin = " ";
		_note = " ";
	}
	void setItemID(string pItemID) { _itemID = pItemID; }
	string getID() const { return _itemID; }
	string getItemType() { return _itemType; }
	void setItemFields(string pString);
	void assignID();
	void insertInfo();
	string show();
};


