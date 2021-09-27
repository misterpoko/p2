CFLAGS = -g -Wall
CC = g++
LDFLAGS =

BIN = compile
all: $(BIN) 

compile: main.o ItemType.o SortedLinkedList.o
	$(CC) $(CFLAGS) -o compile main.o ItemType.o SortedLinkedList.o

main: main.o
	$(CC) $(CFLAGS) -c main.cpp

ItemType: ItemType.o
	$(CC) $(CFLAGS) -c ItemType.cpp
 
SortedLinkedList: SortedLinkedList.o
	$(CC) $(CFLAGS) -c SortedLinkedList.cpp
 

clean:
	-rm -f a.out *.o core atest
	-rm -f *.class
	-rm -f $(BIN) 