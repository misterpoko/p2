Nathaniel Mathers            811053553   nbm54197@uga.edu
Orain Ferguson               811225938   onf32955@uga.edu
Assignment 2


The program makes a linked list and does some methods on the linked list it gets from a file from the command line


Citations
    Some logic and coding structure for the Insert Method from 
	https://www.youtube.com/watch?v=Gg89CzoRDfc&list=PLVZN-GUZ8jlQyzvGf8b6qeV8Anzje6k_2&index=3 

    PowerPoint Slides ch3_ch4 

How to compile 
    make
How to Run 
    compile input.txt(Can use any txt file as long as its ints seperated by spaces) takes in one input

Files needed to run code
    main.cpp
    SorteLinkedList.cpp 
    ItemType.cpp
    ItemType.h 
    SorteLinkedList.h
    ListNode.h 
    input.txt


Contributions
------------------------------------------------------
Nathaniel:

itemType.h
Itemptype.cpp
SortedLinkedList
	-Constructor and destructor
	- delete item
	- delete alternate nodes
	- common elements
bug fixing
mem leak fixing
helper methods not specified

------------------------------------------------------
Orain:

ListNode.h
SortedLinkedList
	- length
	- insert item
	- search
	- getNextItem
	- reset list
	- merge
main.cpp
bug fixing
helper methods not specified
-----------------------------------------------------








Merge Function Big O notation and pseudo code
    Big O: O(n^2+n^2) -> O(n^2)
    Pseudo code:
    
    checker = otherList->head;
	temp = head;
	while (checker not at end of list)
	{ --------------------------------------------------------------------------------------------\
		while (temp not end of list) -------------------------------------------------------\ |
		{                                                                                   | |
			if (checker->item == temp->item) -----------------------------------------\ | |
			{                                                                         | | |
				cout << "Sorry. You cannot insert the duplicate item" << endl;    1 n n           n * n
				return;                                                           | | |
			}                                                                         | | |
			advance temp;-------------------------------------------------------------/ | |
		} ----------------------------------------------------------------------------------/ |
		advance checker;                                                                      |
	} --------------------------------------------------------------------------------------------/
	checker = otherList->head;
	while (checker not at end of list)
	{ ----------------------------------\
		insert item into checker; n n (our insert item is of n time complexity) n * n
		advance checker;            |
	} ----------------------------------/

Find Common Elements Function Big O notation and pseudo code
    Big O: O(n^2+n) -> O(n^2)
    Pseudo Code:

    blankSlate = new SortedLinkedList();
	temp = otherList -> head;
	ListNode* original;
	while (temp not at end of list)
	{
		original = head;
		while (orginal not at end of list)
		{----------------------------------------------\
			if (temp item == original item)----- 1 |
			{                                    | n
				insert item into blankSlate; n |
			} -----------------------------------/ |       n * (n + 1)
			advance orginal                        |
		} ---------------------------------------------/
		advance temp
	}
	temp = head;
	while ( temp not at end of file and temp next isnt NULL)
	{ -----------------------------------------\
		advance temp                       |
		delete(head);                      n                         n
		head = temp;		           |
	} -----------------------------------------/
	head = blankSlate -> head;		
}
