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
    Big O: O(n)
    pseudo code

        int num;
        int n = length of user input
        char charList[n+1];
        char* token;
        string copy to charList from user input
        token = value before a space
        while(token while not  NULL)
        {
            if(mergeStop == true)
		    {
			    break
		    }
            convert char* to int
            insert item into linked list
        }
        return