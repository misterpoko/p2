#include <iostream>
#include <string.h>
#include <stdio.h>
#include "ListNode.h"
#include "ItemType.h"
#include "SortedLinkedList.h"


/**
 * This constructs a linked list with an empty head and empty currentpos
 */
SortedLinkedList::SortedLinkedList() 
{
	head = NULL;
	currentPos =  new ListNode;
	bool mergeStop = false;
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
	if (head == NULL) 
	{
		return 0;
	}
	else
	{
		int i = 1;
		ListNode* temp = head;
		while (temp != NULL)
		{
			temp = temp -> next;	
			i++;	
		}
		return i-1;
	} // if
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
    if (head==NULL || (LESS == items.compareTo(reader->item)))
    {
		new_node->next = head;
		head = new_node;
		if (head != NULL)
		{
			currentPos->next = head;
		}
    }//if
    else if (items.compareTo(reader->item) == EQUAL)
    {
		delete(new_node);
        cout << "Sorry. You cannot insert the duplicate item." << endl;
		mergeStop = true;
        return;
    }//else if
    else       
	{
    	while(reader->next != NULL && (GREATER == items.compareTo(reader->next->item) || items.compareTo(reader->next->item) == EQUAL))
        {
            if (items.compareTo(reader->next->item) == EQUAL)
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
}// insertItem

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

	if(reader != NULL && EQUAL== items.compareTo(reader->item))
	{
		prev = head;
		head = reader->next;
		delete(prev);
		return; 
	}
	else
	{
		while(reader != NULL && EQUAL != items.compareTo(reader->item))
		{
			prev = reader; 
			reader = reader->next;
		}
		if(reader == NULL) //Wrong print out for if an item isnt present in the list
		{
			cout << "List is Empty" << endl; 
			return;
		}
		prev -> next = reader->next;
		delete(reader);
	}
} // deleteItem

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
		if (item.compareTo(current->item)== EQUAL)
		{
			cout << "Index " << index << endl; 
			return index;
		}
		current = current->next;
		index++;
	}
	cout << "Item was not found" << endl;
	return -1; 

} // searchItem

/**
 * This method sets the currentPos to the beginning of the list
 */
void SortedLinkedList::ResetList()
{
	currentPos = head;
} // ResetList
    
/**
 * This method uses the currentPos and gets the next item in the list
 * @return The next item in the list
 */
ItemType SortedLinkedList::GetNextItem()
{
	ItemType empty = ItemType();
	empty.initialize(-1);
	if(currentPos == NULL)
	{
		cout << "The List is empty" << endl;
		return empty;
	}
	if(currentPos->next == NULL)
	{
		cout << "The end of the list has been reached" << endl;
		return empty;
	}
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
	while (checker != NULL)
	{
		while (temp != NULL) 
		{
			if (checker->item.compareTo(temp->item) == EQUAL)
			{
				cout << "dup";
				return;
			} // if
			temp = temp->next;
		} // while
		checker = checker->next;
	} // while
	checker = otherList->head;
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
	SortedLinkedList* blankSlate = new SortedLinkedList();
	ListNode* temp = otherList -> head;
	ListNode* original;
	while (temp != NULL)
	{
		original = head;
		while (original != NULL)
		{
			if (temp->item.compareTo(original->item) == EQUAL)
			{
				blankSlate -> insertItem(temp->item);
			} // if
			original = original -> next;
		} // while
		temp = temp->next;
	} // while
	temp = head;
	while (temp != NULL && temp -> next != NULL)
	{
		temp = temp->next;
		delete(head);
		head = temp;		
	} // while
	head = blankSlate -> head;		
} // commonElements
    
