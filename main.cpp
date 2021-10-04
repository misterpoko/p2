#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <fstream> 
#include <string.h>
#include <sstream>
#include <string>
#include "SortedLinkedList.h"
#include "ItemType.h"

using namespace std;
int main(int argc, char *argv[]) 
{
  SortedLinkedList listy;
  SortedLinkedList listy2;
  string userSelect;
  char userSelectChar;
  string otherList;
  int numbSelect;
  int length;
  bool exit = false;
  bool hold = true;

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
    int numOfElements;
    ItemType newItem;
    //Gets each variable until it hits a space or EOF
    while (getline(inFile, subLine,' '))
    {
      valueOfNode = stoi(subLine);
      newItem = ItemType();
      newItem.initialize(valueOfNode);
      listy.insertItem(newItem);
    }
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
      while(userSelect.size()!=1) 
      {
        cout << "Invalid command, try again!" <<endl;
        cout << "Enter a command: ";
        cin >> userSelect;
      }
      userSelectChar = userSelect[0];
      switch(userSelectChar)
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
		      numOfElements = listy.GetNextItem().getValue();
          if (numOfElements != -1)
          {
            cout << numOfElements << endl;
          }//if
          else 
          {
            cout << endl;
          } // if
          break;
        case 'r': //(r) - Reset iterator
            cout << "Iterator Reset" << endl;
            listy.ResetList();
          break;
        case 'a': //(a) - Delete alternate nodes
            cout << "List before alternate delete: ";
		        listy.printList();
	          listy.dan();
		        cout << endl << "List after alternate delete: ";
            listy.printList();
          break;
        case 'm': //(m) - Merge two lists
            cout << "Length of list to find intersection: ";
            cin >> numOfElements;
            while ((getchar()) != '\n'); // clears the cin buffer
  	        cout << "List elements separated by spaces in order: ";
  	        getline(cin, otherList);
            listy2.createList(otherList);
            cout << "List 1: ";
            listy.printList();
            cout << "List 2: ";
            listy2.printList();
            listy.merge(&listy2);
            listy.printList();
		        listy2.clear();
	        break;
        case 't': //(t) - Intersection
		        cout << "Length of list to find intersection: ";
		        cin >> numOfElements;
            while ((getchar()) != '\n'); // clears the cin buffer
  	        cout << "List elements separated by spaces in order: ";
  	        getline(cin, otherList);
            listy2.createList(otherList);
            cout << "List 1: ";
            listy.printList();
            cout << "List 2: ";
            listy2.printList();
            listy.commonElements(&listy2);
            cout << "Intersection: ";
            listy.printList();
		        listy2.clear();
          break;
        case 'p': //(p) - Print list
            listy.printList();
          break;
        case 'l': //(l) - Print length
            length = listy.length();
            cout << "Linked List is of length : " << length << endl;
          break;
        case 'q': //(q) - Quit program
            cout << "Quitting program..." << endl;
            exit = true;
          break;
        default: //default case so if the input is not a selection
            cout << "Invalid command, try again!" << endl;
            while ((getchar()) != '\n'); // clears the cin buffer
      }
    }  
  }
  return 0; 
}
