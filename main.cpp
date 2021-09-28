#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <fstream> 
#include <string>
#include <sstream>
#include <string>
#include "SortedLinkedList.h"
#include "ItemType.h"

using namespace std;

int main(int argc, char *argv[]) 
{
  SortedLinkedList listy;
  char userSelct;
  bool exit = false;
  ifstream inFile; 
  inFile.open(argv[1]);
  if (!inFile.is_open())
  {
    cout << "Unable to open file";
  }
  else
  {
    string line;
    int valueOfNode;
    while (getline(inFile, line))
    {
      while (1)
      {
	//i really dont want to do this right now its 404 cant sleep oof
	//but this is searching for a space in the line string to seperate the 
	//numbers given to us by the text document
	//if end should break
	//else should truncate the string
	string subLine = line; // assuming the above portion has been done and set into subline
	stringstream ss;
	ss << subLine;
	ss >> valueOfNode;
	ItemType* newItem = new ItemType();
	newItem -> initialize(valueOfNode); // not sure this is functional or written yet
	listy.insertItem(*newItem);
      }
    } 
  }
  
  cout << "Commands:" << endl;
  cout << "(i) - Insert value" << endl;
  cout << "(d) - Delete value" << endl;
  cout << "(s) - Search value" << endl;
  cout << "(n) - Print next iterator value" << endl;
  cout << "(r) - Reset iterator" << endl;
  cout << "(a) - Delete alternate nodes" << endl;
  cout << "(m) - Merge two lists" << endl;
  cout << "(t) - Intersection" << endl;
  cout << "(p) - Print list" << endl;
  cout << "(l) - Print length" << endl;
  cout << "(q) - Quit program" << endl;
  while(exit == false)
  {
    cout << "Enter a command: ";
    cin >> userSelct;
    // Make a method to check for only one char
    switch(userSelct)
    {
      case 'i': //(i) - Insert value
        cout << "Insert value test" << endl; 
        break; 
      case 'd': //(d) - Delete value
        cout << "Delete value test" << endl; 
        break;
      case 's': //(s) - Search value
        cout << "Search value test" << endl; 
        break;
      case 'n': //(n) - Print next iterator value
        cout << "Print next iterator value test" << endl;
        break;
      case 'r': //(r) - Reset iterator
        cout << "Reset iterator test" << endl;
        break;
      case 'a': //(a) - Delete alternate nodes
        cout << "Delete alternate nodes test" << endl;
        break;
      case 'm': //(m) - Merge two lists
        cout << "Merge two lists test" << endl; 
        break;
      case 't': //(t) - Intersection
        cout << "Intersection test" << endl;
        break;
      case 'p': //(p) - Print list
        cout << "Print list test" << endl;
        break;
      case 'l': //(l) - Print length
        cout << "Print length test";
        break;
      case 'q': //(q) - Quit program
        cout << "Quitting..." << endl;
        exit = true;
        break;
      default: //default case so if the input is not a selection
         cout << "Invalid selection" << endl;
    }
  }  
  return 1; 
}
