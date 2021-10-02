#ifndef LISTNODE_H 
#define LISTNODE_H
#include "ItemType.h"

class ListNode
{
	public:
	ListNode(){}
	//Need to be private 
	ItemType item; 
	ListNode *next; 
};

#endif
