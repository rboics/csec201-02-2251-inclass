#pragma once
//This will be for type definitions
//And function prototypes


//Defintion of a node
struct node {
	//The data stored in the linked list
	char name[50];	//string of max length 50
					//50 bytes

	//Pointer to the next node in the list
	struct node* next; //4 bytes
};
//Note: The size of a single node is....54 bytes

struct LinkedList {
	int size;	//track the number of nodes in the list	(4 bytes)
	struct node* head; //track the most recently added node in the list (4 bytes)
};
//The size of a LinkedList (not including the nodes of the LinkedList) is.... 8 bytes


//Function prototypes
//
void initialize(struct LinkedList* list);

void addNode(struct LinkedList* list, char* person);

void printList(struct LinkedList* list);