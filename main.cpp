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
  char userSelect;
  int numbSelect;
  int length;
  bool exit = false;

  ifstream inFile;
  inFile.open(argv[1]);
  if (!inFile.is_open())
  {
    cout << "Unable to open file" << endl;
  }
  else
  {
    string subLine;
    int valueOfNode;
    ItemType newItem;
    //Gets each variable until it hits a space or EOF
    while (getline(inFile, subLine,' '))
    {
      valueOfNode = stoi(subLine);
      //cout << subLine << endl;
      newItem = ItemType();
      newItem.initialize(valueOfNode); // not sure this is functional or written yet
      listy.insertItem(newItem);
    }
    listy.printList();
    cout << endl;

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
      cin >> userSelect;
      // Make a method to check for only one char
      switch(userSelect)
      {
        case 'i': //(i) - Insert value
          cout << "Enter a numer to insert: ";
          cin >> numbSelect; 
          newItem = ItemType();
          newItem.initialize(numbSelect); // not sure this is functional or written yet
          listy.insertItem(newItem);
          listy.printList();
          break; 
        case 'd': //(d) - Delete value
          cout << "Enter a numer to delete: ";
          cin >> numbSelect;
          newItem = ItemType();
          newItem.initialize(numbSelect);
          listy.deleteItem(newItem);
          listy.printList();
          break;
        case 's': //(s) - Search value
          cout << "Enter a numer to search for: ";
          cin >> numbSelect;
          newItem = ItemType();
          newItem.initialize(numbSelect);
          listy.searchItem(newItem);
          break;
        case 'n': //(n) - Print next iterator value
          listy.GetNextItem();
          break;
        case 'r': //(r) - Reset iterator
          cout << "Iterator Reset" << endl;
          listy.ResetList();
          break;
        case 'a': //(a) - Delete alternate nodes
          cout << "Delete alternate nodes test" << endl;
	  listy.dan();
          listy.printList();
          break;
        case 'm': //(m) - Merge two lists
          cout << "Merge two lists test" << endl; 
          break;
        case 't': //(t) - Intersection
          cout << "Intersection test" << endl;
          break;
        case 'p': //(p) - Print list
          cout << "Print the list: ";
          listy.printList();
          break;
        case 'l': //(l) - Print length
          length = listy.length();
          cout << "Linked List is of length : " << length << endl;
          break;
        case 'q': //(q) - Quit program
          cout << "Quitting..." << endl;
          exit = true;
          break;
        default: //default case so if the input is not a selection
          cout << "Invalid selection" << endl;
      }
    }  
  }
  return 1; 
}
