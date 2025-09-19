//This will contain the implementions
//Of the functions whose prototypes are in ll.h
//Note: It's bad practice to not have the source file
//named consistently with the .h file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll.h"

void initialize(struct LinkedList* list) {
	//Use the arrow when the left is an address
	list->size = 0;
	list->head = NULL; //NULL is a memory address that doesn't exist
					   //Typically used to denote the end of something

	//IF the parameter was struct LinkedList list instead of struct LinkedList * list
	// list.size = 0;
	// list.head = NULL;
	//Note: The left is a thing, not an address
}

void addNode(struct LinkedList* list, char* person) {
	//Create a new node
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	//Above line in Java would be Node n = new Node();
	//Copy the data into the new node
	strcpy(newNode->name, person);

	//Connect the new node to the LinkedList
	newNode->next = list->head; //Make the new node point at the previous head
	list->head = newNode; //Make the new node into the new head
	list->size++;
}

void printList(struct LinkedList* list) {
	struct node* temp = list->head;
	if (temp == NULL) {
		printf("List is empty\n");
		return; //You can return with no argument if the type of the function is void
	}
	while (temp != NULL) {
		printf("%s -> ", temp->name);
		temp = temp->next;
	}
	printf("NULL\n");
}

