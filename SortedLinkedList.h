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
    void insertItem(ItemType items);
    void deleteItem(ItemType items);
    int searchItem(ItemType item);
    ItemType GetNextItem();
    void ResetList();
    
    
    void merge(SortedLinkedList *otherList); 
    void dan();
    void commonElements(SortedLinkedList *otherList);
    void printList();
    
    
  private:
    ListNode *head;
    ListNode *currentPos;
    int mergeStop;
    
   
    
};
#endif
