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
  
My goal was to create the program in a modular way so that the registry itself could host 
various types of items that could be plugged into the program.
This goal is partly achieved through the use of template class for the registry itself 
and a base class pointer and derived sub classes for the different types of items.
However, the Collection Registry template class needs to make use of the specific item types 
when adding items to the registry (such as "Book" or "Music Record") and when counting items.
In case a derived class for another type of collection item would be added to the program,
the functions for adding items and the parts where items are counted should be adjusted for 
being able to handle that specific type.
