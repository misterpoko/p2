#ifndef SORTEDLINKEDLIST_H 
#define SORTEDLINKEDLIST_H
#include "ListNode.h"
#include "ItemType.h"

using namespace std;

class SortedLinkedList
{
  public:
    SortedLinkedList();
    ~SortedLinkedList();
    int length() const;
    void insertItem(ItemType item);
    void deleteItem(ItemType item);
    int searchItem(ItemType item);
    ItemType GetNextItem();
    void ResetList();
    
    
    void merge(SortedLinkedList *otherList); 
    void dan();
    void commonElements(SortedLinkedList *otherList);
    
  private:
    ListNode *head;
    ListNode *currentPos;
    
};
#endif
