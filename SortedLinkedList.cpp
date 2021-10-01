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
}

void SortedLinkedList::printList()
{
	currentPos = head;
	while(currentPos != NULL)
	{
		cout << currentPos->item.getValue() << " ";
		currentPos = currentPos->next;
	}
	cout << endl;
}

void SortedLinkedList::deleteItem(ItemType items)
{
	ListNode* temp = head;
	ListNode* prev = NULL; 

	if(temp != NULL && EQUAL== items.compareTo(temp->item))
	{
		
	}
}
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
}
/*ItemType SortedLinkedList::GetNextItem()
{
    
}*/
void SortedLinkedList::ResetList()
{
	currentPos = NULL;
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
    
