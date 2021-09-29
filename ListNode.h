#ifndef LISTNODE_H 
#define LISTNODE_H
#include "ItemType.h"

class ListNode
{
	public:
	ListNode(){}
	ItemType item; 
	ListNode *next; 
};

#endif
