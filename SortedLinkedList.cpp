#include <iostream>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "ListNode.h"
#include "ItemType.h"
#include "SortedLinkedList.h"


/**
 * This constructs a linked list with an empty head and empty currentpos
 */
SortedLinkedList::SortedLinkedList() 
{
	head = NULL;
	currentPos = /*new ListNode()*/ head;
	bool headCheck = true;
} // SortedLinkedList

/**
 * This goes in and destroys a linked List node by node
 */
SortedLinkedList::~SortedLinkedList()
{
	currentPos = head;
	while (currentPos != NULL)
	{
		head = currentPos -> next;
		delete(currentPos);
		currentPos = head;	
	}
} // ~SortedLinkedList

/**
 * This method gets the length of the Linked List.
 * @return the length of this instance of a SortedLinkedLiset
 */
int SortedLinkedList::length() const
{
	ListNode* temp = head;
	int i = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	} // while
	return i;
} // length

/**
 * This puts in an item given its not a duplicate
 * @param items the item that is being inserted.
 */
void SortedLinkedList::insertItem(ItemType items)
{
    ListNode* new_node = new ListNode();
    ListNode* reader = head;
    new_node->item = items;
    new_node->next= NULL;
    if (head==NULL || (ItemType::LESS == items.compareTo(reader->item)))
    { 
		new_node->next = head;
		head = new_node;
    }//if
    else if (items.compareTo(reader->item) == ItemType::EQUAL)
    {
		delete(new_node);
        cout << "Sorry. You cannot insert the duplicate item." << endl;
		mergeStop = true;
        return;
    }//else if
    else       
	{
	// checks whether the next one is greater or equal returning without changing the list if there is a duplicate or getting
	// to the point of the list where it is supposed to add the element
    	while(reader->next != NULL && (ItemType::GREATER == items.compareTo(reader->next->item) || items.compareTo(reader->next->item) == ItemType::EQUAL))
        {
            if (items.compareTo(reader->next->item) == ItemType::EQUAL)
            {
				delete(new_node);
            	cout << "Sorry. You cannot insert the duplicate item." << endl;
				mergeStop = true;
                return;
            } // if
            reader = reader->next;
        }//while
        new_node->next = reader->next;
        reader->next = new_node;
	}
}
/**
 * This method prints out the list in the standard output
 */
void SortedLinkedList::printList()
{
	ListNode* printVar = head;
	printVar = head;
	while(printVar != NULL)
	{
		cout << printVar->item.getValue() << " ";
		printVar = printVar->next;
	}
	delete(printVar);
	cout << endl;
} // printList

/**
 * This method is used to delete Different nodes given an item that we specify to delete
 * if item doesnt exist gives friendly text that its impossible
 * @param items the item that is going to get deleted if it exists
 */
void SortedLinkedList::deleteItem(ItemType items)
{
	ListNode* reader = head;
	ListNode* prev = NULL; 
	if (reader == NULL)
	{
		cout << "You cannot delete from an empty list." << endl;
		return;
	} // if
	// edge case of first node
	if(reader != NULL && ItemType::EQUAL== items.compareTo(reader->item))
	{
		prev = head;
		head = reader->next;
		delete(prev);
		return; 
	}//if
	else
	{
		// find the item to delete
		while(reader != NULL && ItemType::EQUAL != items.compareTo(reader->item))
		{
			prev = reader; 
			reader = reader->next;
		}//while
		// item doesnt exist
		if(reader == NULL)
		{
			cout << "Item not found." << endl; 
			return;
		}//if
		prev -> next = reader->next;
		delete(reader);
	}
} // deleteItem

/**
 * This method clears the list using the delete command for main
 * helps with a memory leak.
 */
void SortedLinkedList::clear()
{
	while(head != NULL)
	{
		deleteItem(head->item);
	} // while
} // clear

/**
 * This method searches the list for the items a specific 
 * @param item the Item that we are searching for
 * @return the indice that the item is at or -1 if it doesnt exist
 */
int SortedLinkedList::searchItem(ItemType item)
{
	int index = 0; 
	ListNode* current = head;
	while (current != NULL)
	{
		if (item.compareTo(current->item)== ItemType::EQUAL)
		{
			cout << "Index " << index << endl; 
			return index;
		}
		current = current->next;
		index++;
	}
	cout << "Item not found" << endl;
	return -1; 

} // searchItem

/**
 * This method sets the currentPos to the beginning of the list
 */
void SortedLinkedList::ResetList()
{
	currentPos = NULL;
} // ResetList
    
/**
 * This method uses the currentPos and gets the next item in the list
 * @return The next item in the list
 */
ItemType SortedLinkedList::GetNextItem() 
{
	ItemType empty = ItemType();
	empty.initialize(-1);
	if(head == NULL)
	{
		cout << "List is empty" <<endl;
		return empty;
	}
	// edge case if it is the first element	
	if(currentPos == NULL)
	{
		currentPos = head;
		return currentPos->item;
	}
	// edge case if at end of list
	if (currentPos->next == NULL) {
		cout << "The end of the list has been reached";
		return empty;
	} // if
	currentPos = currentPos->next;
	return currentPos->item;
} // GetNextItem


//Extra Methods
/**
 * This method takes two list and merges them together under the condition
 * that they do not have duplicates to the initial list.
 * @param otherList is the other list being added to the original list.
 */
void SortedLinkedList::merge(SortedLinkedList *otherList)
{
	ListNode* checker = otherList->head;
	ListNode* temp = head;
	// this nested loop checks for duplicates and attempts to short
	while (checker != NULL)
	{
		while (temp != NULL) 
		{
			if (checker->item.compareTo(temp->item) == ItemType::EQUAL)
			{
				cout << "Sorry. You cannot insert the duplicate item" << endl;
				return;
			} // if
			temp = temp->next;
		} // while
		checker = checker->next;
	} // while
	checker = otherList->head;
	// starts adding other list given no duplicates
	while (checker != NULL)
	{ 
		insertItem(checker->item);
		checker = checker->next;
	} // while
} // merge

/**
 * This method deletes all alternate nodes in the list starting with the second
 * going to the 4th then the 6th and so on until the end of the list.
 */
void SortedLinkedList::dan()
{
	if (head != NULL && head->next != NULL)
	{
		ListNode* temp = head;
		ListNode* ahead = temp ->next;
		while (temp -> next != NULL)
		{
			deleteItem(ahead->item);
			if (temp -> next != NULL)
			{
				temp = temp -> next;
				ahead = temp -> next;
			} // if	
		} // while
	} // if
} // dan

/**
 * This method takes two list and finds the intersection of them. It modifies the 
 * original to be the intersection and then prints it out.
 * @param otherList is the otherlist to be crosschecked with the initial list.
 */ 
void SortedLinkedList::commonElements(SortedLinkedList *otherList)
{
	// create a brand new list and populate it with dups
	SortedLinkedList* blankSlate = new SortedLinkedList();
	ListNode* temp = otherList -> head;
	ListNode* original;
	// find dups
	while (temp != NULL)
	{
		original = head;
		while (original != NULL)
		{
			if (temp->item.compareTo(original->item) == ItemType::EQUAL)
			{
				blankSlate -> insertItem(temp->item);
			} // if
			original = original -> next;
		} // while
		temp = temp->next;
	} // while
	temp = blankSlate->head;
	// purge current list then set it to new list just created
	clear();
    while (temp!= NULL)
    {
    	insertItem(temp->item);
        temp = temp->next;
    } // while
    delete blankSlate;
} // commonElements
 
/**
 * This method takes in a string and turns it into a sorted linked list.
 * It is used in main to create list for the merge and intersect commands
 * @param inputList a string full of numbers seperated by spaces representing the list
 */   
void SortedLinkedList::createList(string inputList)
{
	int valueOfNode;
  	ItemType newMerge = ItemType();
	int num,n;
  	char* token;
	n = inputList.length();
	char charList[n+1];
	strcpy(charList,inputList.c_str());
	token = strtok(charList, " ");
	while(token != NULL )
	{
		//printf ("%s\n",token);
		num = atoi(token);
		token = strtok(NULL, " "); // Moves token to the next item.
		newMerge.initialize(num);
    	insertItem(newMerge);
	}
} // createList
