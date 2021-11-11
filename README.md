# Collection Registry



This is a console application for cataloguing collection items, such as music records.

## Functionality

The program provides following functionality:
<li>Loading the registry from file
<li>Saving the registry to file
<li>Adding different types of items to the registry, such as music records, books and plants.
<li>Searching for an item in the registry
<li>Sorting the registry
<li>Deleting item(s) from the registry
  
## Technical Features

The program is written in C++ with following technical features:
<li>Object oriented design
<li>Pure virtual base class and derived classes to support polymorphism of collection items
<li>Template class for performing functions on generic types of collection items
<li>Exception handling

## Challenges
  
My goal was to create the program with a modular design so that the registry itself could host 
various types of items that could be plugged into the program.
This goal is partly achieved through the use of template class for the registry itself 
and a base class pointer and derived sub classes for the different types of items.
However, the Collection Registry template class needs to make use of the specific item types 
when adding items to the registry (such as "Book" or "Music Record") and when counting items.
In case a derived class for another type of collection item would be added to the program,
the functions for adding items and the parts where items are counted should be adjusted for 
being able to handle that specific type.
  
## Instructions for compiling and running the program
  
The program consists of the following files that should be compiled together:
<li> main.cpp
<li> CollectionRegistry.tpl
<li> BaseCollectionItem.h
<li> SubCollectionItem1.h & SubCollectionItem1.cpp
<li> SubCollectionItem2.h & SubCollectionItem2.cpp
<li> SubCollectionItem3.h & SubCollectionItem3.cpp
<li> Menu.h & Menu.cpp
  
Moreover, the program makes use of the text file CollectionRegistry.txt to save the items in file.
This file includes a sample collection of items and it should be located in the same folder with
the source files when the program is compiled. When he program runs it prompts the user to start
by loading the registry from file. All other program functionality is also disabled until the
registry has been loaded from file.
