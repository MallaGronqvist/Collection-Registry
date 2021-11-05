// main.cpp
// Author: Malla Grönqvist
// Date: 28.05.2021
// Description: A cataloguing program for saving and handling collection items.
// The program provides functionality for adding, searching, deleting and sorting items 
// and for saving to and loading from file.
//******************************************************************************************

#include "BaseCollectionItem.h"
#include "SubCollectionItem1.h"
#include "SubCollectionItem2.h"
#include "SubCollectionItem3.h"
#include "CollectionRegistry.tpl"
#include "Menu.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class App {
public:
	int run();
	App();
private:
	CollectionRegistry<BaseCollectionItem> colReg;
	Menu mainMenu, fileMenu, printMenu, printSubMenu, removingMenu, addingMenu, searchMenu, sortMenu;
};

App::App() {
	mainMenu.setMenuTitle("***MAIN MENU***");
	mainMenu.addItem("Load from file / Save to file.", true);
	mainMenu.addItem("View items in registry.", false);
	mainMenu.addItem("Add an item to the registry.", false);
	mainMenu.addItem("Remove item(s) from the registry.", false);
	mainMenu.addItem("Search for an item in the registry.", false);
	mainMenu.addItem("Sort registry.", false);
	mainMenu.addItem("Exit program.", true);

	fileMenu.setMenuTitle("***FILE ACTIONS***");
	fileMenu.addItem("Load from file", true);
	fileMenu.addItem("Save to file", false);
	fileMenu.addItem("Back to main menu", true);

	printMenu.setMenuTitle("***VIEW ITEM(S)***");
	printMenu.addItem("Print one item by item ID.", true);
	printMenu.addItem("Print all items in registry.", true);
	printMenu.addItem("Print all items of a specific type in registry.", true);
	printMenu.addItem("Back to main menu", true);

	printSubMenu.setMenuTitle("***CHOOSE ITEM TYPE TO BE PRINTED***");
	printSubMenu.addItem("Print books.", true);
	printSubMenu.addItem("Print music records.", true);
	printSubMenu.addItem("Print plants.", true);
	printSubMenu.addItem("Back to main menu.", true);

	removingMenu.setMenuTitle("***REMOVE ITEM(S)***");
	removingMenu.addItem("Remove one item.", true);
	removingMenu.addItem("Remove all items in registry.", true);
	removingMenu.addItem("Back to main menu.", true);

	addingMenu.setMenuTitle("***ADD AN ITEM TO REGISTRY***");
	addingMenu.addItem("Add a book.", true);
	addingMenu.addItem("Add a music record.", true);
	addingMenu.addItem("Add a plant.", true);
	addingMenu.addItem("Back to main menu.", true);

	searchMenu.setMenuTitle("***SEARCH FOR AN ITEM IN REGISTRY***");
	searchMenu.addItem("Search for an item.", true);
	searchMenu.addItem("Back to main menu.", true);

	sortMenu.setMenuTitle("***SORT REGISTRY***");
	sortMenu.addItem("Sort in ascending order.", true);
	sortMenu.addItem("Sort in descending order.", true);
	sortMenu.addItem("Back to main menu.", true);
}

int App::run() {

	cout << "~~ WELCOME TO COLLECTION REGISTRY ~~" << endl
		<< "Start by loading registry from file." << endl << endl
		<< "Press enter to proceed to main menu." << endl;
	cin.get();
	
	bool again = true;
	do // Repeat until user chooses to exit program
	{	
		mainMenu.printMenuItems();
		switch (mainMenu.getMenuChoice()) // Let the user select a menu item
		{
		case 1: {
			bool printFileMenu = true;
			do {
				fileMenu.printMenuItems();
				switch (fileMenu.getMenuChoice()) {
				case 1: if (colReg.loadReg()) {		// If loading was succesful enable other menu options.
					mainMenu.setMenuItemOptions(true);
					fileMenu.enableMenuItem(1, true);
				}
					break;
				case 2: colReg.saveReg();
					break;
				case 3: printFileMenu = false;
				}
			} while (printFileMenu);
		}
			break;
		case 2: {
			bool printPrintMenu = true;
			do {
				printMenu.printMenuItems();
				switch (printMenu.getMenuChoice()) {
				case 1: colReg.showOneItem();
					break;
				case 2: colReg.showItems();
					break;
				case 3: { 
					bool printPrintSubMenu = true;
					do {
						printSubMenu.printMenuItems();
						switch (printSubMenu.getMenuChoice()) {
						case 1: colReg.showItemsOfAType("Book");
							break;
						case 2: colReg.showItemsOfAType("Music Record");
							break;
						case 3: colReg.showItemsOfAType("Plant");
							break;
						case 4: printPrintSubMenu = false;
						}
					} while (printPrintSubMenu);
				}
				case 4: printPrintMenu = false;
				}
			} while (printPrintMenu);
		}
			break;
		case 3: {
			bool printAddingMenu = true;
			do {
				if (colReg.checkMaxNumberBooks()) {			// Check if max nr items has been reached.
					addingMenu.enableMenuItem(0, false);	// If so, disable adding more items.
				}
				if (colReg.checkMaxNumberMusicRecords()) {
					addingMenu.enableMenuItem(1, false);
				}
				if (colReg.checkMaxNumberPlants()) {
					addingMenu.enableMenuItem(2, false);
				}

				addingMenu.printMenuItems();
				BaseCollectionItem* p = nullptr;
				switch (addingMenu.getMenuChoice()) {
				case 1: 
					p = new SubCollectionItem1;
					p->insertInfo();
					colReg.addItem(p);
					break;
				case 2: 
					p = new SubCollectionItem2;
					p->insertInfo();
					colReg.addItem(p);
					break;
				case 3: 
					p = new SubCollectionItem3;
					p->insertInfo();
					colReg.addItem(p);
					break;
				case 4: printAddingMenu = false;
				}
			} while (printAddingMenu);
		}
			break;
		case 4: {
			bool printRemovingMenu = true;
			do {
				removingMenu.printMenuItems();
				switch (removingMenu.getMenuChoice()) {
				case 1: colReg.removeItem();
					break;
				case 2: colReg.removeAllItems();
					break;
				case 3: printRemovingMenu = false;
				}
			} while (printRemovingMenu);
		}
			break;
		case 5: {
			bool printSearchMenu = true;
			do {
				searchMenu.printMenuItems();
				switch (searchMenu.getMenuChoice()) {
				case 1: colReg.searchForItem();
					break;
				case 2: printSearchMenu = false;
				}
			} while (printSearchMenu);
		}
			break;
		case 6: {
			bool printSortMenu = true;
			do {
				sortMenu.printMenuItems();
				switch (sortMenu.getMenuChoice()) {
				case 1: colReg.sortAscendingOrder();
					break;
				case 2: colReg.sortDescendingOrder();
					break;
				case 3: printSortMenu = false;
				}
			} while (printSortMenu);
		}
			break;
		case 7: again = false;
		}
	} while (again);

	return 0;
}

int main() {
	App CollectionRegistry;
	CollectionRegistry.run();
}