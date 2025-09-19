//This will be where we put main
#include <stdio.h> //carrots for built-in headers
#include <stdlib.h> //Contains malloc
#include "ll.h"	//"" for user-defined headers

int main(void) {
	struct LinkedList list1; //list1 is on the stack
	initialize(&list1);
	addNode(&list1, "Rob");
	addNode(&list1, "Matt");
	addNode(&list1, "Bill");
	printList(&list1);

	//List2 is a pointer on the stack
	//List2 will point at an unnamed LinkedList on the heap
	struct LinkedList* list2 = (struct LinkedList*) malloc(sizeof(struct LinkedList));
	initialize(list2);
	addNode(list2, "Rob");
	addNode(list2, "Matt");
	addNode(list2, "Bill");
	printList(list2);
	
}