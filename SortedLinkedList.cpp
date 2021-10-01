#include <iostream>
#include <string>
#include "ListNode.h"
#include "ItemType.h"
#include "SortedLinkedList.h"


/**
 * This constructs a linked list with an empty head and empty currentpos
 */
SortedLinkedList::SortedLinkedList() 
{
	head = NULL;
	currentPos = head;
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
		free(currentPos);
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

/*
	Idea to get insert method https://www.youtube.com/watch?v=Gg89CzoRDfc&list=PLVZN-GUZ8jlQyzvGf8b6qeV8Anzje6k_2&index=3 
*/
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
	}
	else 
	{
		while(reader->next != NULL && (GREATER == items.compareTo(reader->next->item)))
		{
			if(reader != NULL)
			{
				cout << "Sorry. You cannot insert the duplicate item." << endl;
				return;
			}
			reader = reader->next;
		}
		new_node->next = reader->next;
		reader->next = new_node;
	}
} // insertItem

/**
 * This method prints out the list in the standard output
 */
void SortedLinkedList::printList()
{
	currentPos = head;
	while(currentPos != NULL)
	{
		cout << currentPos->item.getValue() << " ";
		currentPos = currentPos->next;
	}
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
		head = reader->next;
		return; 
	}
	else
	{
		while(reader != NULL && EQUAL != items.compareTo(reader->item))
		{
			prev = reader; 
			reader = reader->next;
		}
	}
	if(reader == NULL)
	{
		cout << "List is Empty" << endl; 
		return;
	}
} // deleteItem

/**
 * This method searches the list for the items a specific 
 * @param item the Item that we are searching for
 * @return the indice that the item is at or -1 if it doesnt exist
 */
int SortedLinkedList::searchItem(ItemType item)
{
	int i = 0;
	currentPos = head;
	while (1)
	{	
		i++;
		if (item.compareTo(currentPos -> item) == EQUAL)
		{
			break;
		}
		else if (item.compareTo(currentPos -> item) == GREATER)
		{
			i = -1;
			break;
		} // if
	} // while
	if (i == -1)
	{	
		cout << "Item not found" << endl;
	} // if
	return i;
} // searchItem

/**
 * This method uses the currentPos and gets the next item in the list
 * @return The next item in the list
 */
ItemType SortedLinkedList::GetNextItem()
{
} // GetNextItem

/**
 * This method sets the currentPos to Null
 */
void SortedLinkedList::ResetList()
{
	currentPos = NULL;
} // ResetList
    
//Extra Methods
/**
 * This method takes two list and merges them together under the condition
 * that they do not have duplicates to the initial list.
 * @param otherList is the other list being added to the original list.
 */
void SortedLinkedList::merge(SortedLinkedList *otherList)
{

} // merge

/**
 * This method deletes all alternate nodes in the list starting with the second
 * going to the 4th then the 6th and so on until the end of the list.
 */
void SortedLinkedList::dan()
{

} // dan

/**
 * This method takes two list and finds the intersection of them. It modifies the 
 * original to be the intersection and then prints it out.
 * @param otherList is the otherlist to be crosschecked with the initial list.
 */ 
void SortedLinkedList::commonElements(SortedLinkedList *otherList)
{
	
} // commonElements
    
