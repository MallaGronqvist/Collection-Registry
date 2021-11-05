// Menu.cpp
// Author: Malla Grönqvist
// Date: 28.05.2021
//********************************************************************************


#include "Menu.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;


MenuItem::MenuItem() {
	menuText = "";
	option = false;
}

MenuItem::MenuItem(std::string pMenuText, bool pOption) {
	menuText = pMenuText;
	option = pOption;
}

void MenuItem::setMenuText(std::string pMenuText) {
	menuText = pMenuText;
}

void MenuItem::setOption(bool pOption) {
	option = pOption;
}

std::string MenuItem::getMenuText() {
	return menuText;
}

bool MenuItem::getOption() {
	return option;
}

Menu::Menu() {
	// menuTitle and vector are initiated as empty.
}

Menu::~Menu() {
	// Menu's vector and string are destructed when out of scope.
}

void Menu::addItem(std::string pMenuText, bool pOption) {
	// Declare a menu item and set its data members with function arguments.
	MenuItem tmpMenuItem;
	tmpMenuItem.setMenuText(pMenuText);
	tmpMenuItem.setOption(pOption);
	// Add menu item to the vector.
	menuItems.push_back(tmpMenuItem);
}

void Menu::setMenuTitle(std::string pMenuTitle) {
	menuTitle = pMenuTitle;
}

void Menu::printMenuItems() {
	system("cls");
	// Print menu title.
	cout << menuTitle << endl;
	// Print menu options.
	int optionNumber = 1;
	for (auto idx : menuItems) {
		cout << optionNumber << ". " << idx.getMenuText() << endl;
		optionNumber++;
	}
}

int Menu::getMenuChoice() {
	bool again = true;
	do {    // Repeat if menu item is not enabled
		int choice;
		cout << "Enter your choice from the menu options:" << endl;
		cin >> choice;  // Read user input into choice.
		cin.get();
		int idx = (choice - 1);

		if ((cin.fail()) || (cin.fail() || choice > menuItems.size() || choice == 0)) { 
			// clear failure state
			cin.clear();
			// discard remaining unprocessed characters in the input stream
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid input. Press enter to try again." << endl;
			cin.get();
		}
		else if (idx < menuItems.size()) {
			if (menuItems[idx].getOption()) {  // Check whether menuItem is enabled or not.
				again = false;  // Don't repeat if menu item is enabled
				return choice;  // Return user's choice
			}
			else {
				cout << "The menu item is not available." << endl;
			}
		}
		else {
			cout << "You need to choose a number from the menu." << endl;
		}
	} while (again);
}

void Menu::setMenuItemOptions(bool pOption) {
	// Set each menu item's option with the function argument.
	// Make menu items available or unavailable to the user.
	for (auto &idx : menuItems) {
		idx.setOption(pOption);
	}
}

void Menu::enableMenuItem(int pItemIndex, bool pOption)
{
	menuItems[pItemIndex].setOption(pOption);
}

