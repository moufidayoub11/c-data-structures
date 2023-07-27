#include <stdio.h>
#include <stdlib.h>

#ifndef LINKED_LIST 
#define LINKED_LIST
typedef struct node
{
	int data;
	struct node *next;
}node;

node *createNode(int data);
int pushNode(node **head, int data);
int removeNodeAt(node **head, int index);
int popNode(node **head);
int sortedInsert(node **head, int data);
void sortLinkedList(node **head);
void freeLinkedList(node *head);
int linkedListLength(node *head);
void printLinkedList(node *head);
#endif /* LINKED_LIST */
