The program name is Assigment_2

The program makes a linked list and does some methods on the linked list it gets from a file from the command line

Authors: Nathanial Mathers Orain Ferguson

Citations
    Some logic and coding structure for the Insert Method from 
	https://www.youtube.com/watch?v=Gg89CzoRDfc&list=PLVZN-GUZ8jlQyzvGf8b6qeV8Anzje6k_2&index=3 

    PowerPoint Slides ch3_ch4 

How to compile 
    make
How to Run 
    compile input.txt(Can use any txt file as long as its ints seperated by spaces)

Files needed to run code
    main.cpp
    SorteLinkedList.cpp 
    ItemType.cpp
    ItemType.h 
    SorteLinkedList.h
    ListNode.h 
    input.txt

Merge Function Big O notation and pseudo code
    Big O: O(n^2+n)
    Pseudo code:
    
    checker = otherList->head;
	temp = head;
	while (checker not at end of list)
	{
		while (temp not end of list) 
		{
			if (checker->item == temp->item)
			{
				cout << "Sorry. You cannot insert the duplicate item" << endl;
				return;
			} 
			advance temp;
		} 
		advance checker;
	}
	checker = otherList->head;
	while (checker not at end of list)
	{
		insert item into checker;
		advance checker;
	} 

Find Common Elements Function Big O notation and pseudo code
    Big O: O(n^2+n)
    Pseudo Code:

    blankSlate = new SortedLinkedList();
	temp = otherList -> head;
	ListNode* original;
	while (temp not at end of list)
	{
		original = head;
		while (orginal not at end of list)
		{
			if (temp item == orginial item)
			{
				insert item into blankSlate;
			} 
			advance orginal
		} 
		advance temp
	}
	temp = head;
	while ( temp not at end of file and temp next isnt NULL)
	{
		advance temp
		delete(head);
		head = temp;		
	} 
	head = blankSlate -> head;		
}