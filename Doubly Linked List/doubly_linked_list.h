#include <stdio.h>
#include <stdlib.h>
#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}node;




node *createNode(int data);
int pushNode(node **head, int data);
int removeNodeAt(node **head, int index);
int popNode(node **head);
int sortedInsert(node **head, int data);
void sortDoublyLinkedList(node **head);
int doublyLinkedListLength(node *head);
void freeLinkedList(node *head);
void printDoublyLinkedList(node *head);
#endif /* DOUBLY_LINKED_LIST */
