// BaseCollectionItem.h
// Author: Malla Grönqvist
// Date: 28.05.2021
// Description: Base Class for Items to be saved in Collection Registry
//**********************************************************************

#pragma once
#include<string>
using std::string;

class BaseCollectionItem
{

private:
	string _itemID;
	string _itemType;
public:	
	virtual string getID() const = 0;
	virtual string show() = 0;
	virtual void insertInfo() = 0;
	virtual string getItemType() = 0;
	virtual void assignID() = 0;
	virtual void setItemFields(string pString) = 0;
};




