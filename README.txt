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


MERGE Function bigO

BigO(n^2 + n^2) -> BigO(n^2)

Node 1 = otherlist head
Node 2 = currentlist head
While(node 1 isnt at end of list) -------------n
{
	NODE1 = currentList head
	while(node 2 isnt at end  of list) ----n
	{
		compare(node1,node2)-----------1
		advance node2
	} // while
	advance node1
} // while
node1 = otherlist head
while (node1 isnt at end of list) ------------n
{
	insert item in main list -------------n  (dependent on insert item which is bigO n)
	advance node1
} // while

--------------------------------------------------

Common Elements Function bigO
bigO(n^2 + n + n^3) -> bigO(n^3)

Create tempList
Node 1 = otherlist head;
Node 2;
while (node1 is not at end of list) -------------n
{
	node2 = currentList head;
	while (node2 isnt at end of list) -------n
	{
		if(compare(node1,node2)) --------1
			insert item in tempList -n
		advance node2
	} // while
	advance node1
} // while
clear currentList ------------------------------n
node1 = templist head
while (node1 isnt at end of list) --------------n
{
	insert item from templist to current list -n^2 (because its a two step find in templist is n and insert in current list is n)
	advance node1
} // while
delete temp list

-------------------------------------------------
