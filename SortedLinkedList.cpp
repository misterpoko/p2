#include <iostream>
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
		return i;
	} // if
} // length

void SortedLinkedList::insertItem(ItemType item)
{

}
void SortedLinkedList::deleteItem(ItemType item)
{

}
int SortedLinkedList::searchItem(ItemType item)
{
    return 1;
}
ItemType SortedLinkedList::GetNextItem()
{
    
}
void SortedLinkedList::ResetList()
{

}
    
//Extra Methods
void SortedLinkedList::merge(SortedLinkedList *otherList)
{

}
void SortedLinkedList::dan()
{

}
void SortedLinkedList::commonElements(SortedLinkedList *otherList)
{

}
    
