// Menu.h
// Author: Malla Grönqvist
// Date: 28.05.2021
// Description: Contains classes MenuItem and Menu for creating a program menu.
//********************************************************************************


#pragma once
#ifndef DT019G_MENU_H
#define DT019G_MENU_H

#include <string>
#include <vector>
using std::string;
using std::vector;

class MenuItem {
private:
	string menuText;
	bool option;

public:
	MenuItem();
	MenuItem(std::string pMenuText, bool pOption);
	void setMenuText(std::string pMenuText);
	void setOption(bool pOption);
	string getMenuText();
	bool getOption();
};

class Menu {
private:
	vector<MenuItem>menuItems;
	string menuTitle;

public:
	Menu();
	~Menu();
	void addItem(string pMenuText, bool pOption);
	void setMenuTitle(string pMenuTitle);
	void printMenuItems();
	int getMenuChoice();
	void setMenuItemOptions(bool pOption);		// Enable or disable all items in a menu.
	void enableMenuItem(int pItemIndex, bool pOption);		// Enable or disable one item in a menu.
};

#endif //DT019G_MENU_H


