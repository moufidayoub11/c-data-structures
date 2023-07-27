#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/**
 * createNode - Create a new node with the given data
 *
 * @data: The data to be stored in the new node
 *
 * Return: A pointer to the newly created node or NULL on failure
 */
node *createNode(int data)
{
	node *new = malloc(sizeof(node));

	if (new == NULL)
	{
		fprintf(stderr, "createNode è coudn't create a new node");
		return (0);
	}
	new->data = data;
	new->next = NULL;
	return (new);
}

/**
 * pushNode - Add a new node with the given data to the end of
 * the linked list
 *
 * @head: Pointer to a pointer to the head of the linked list
 * @data: The data to be stored in the new node
 *
 * Return: 1 on success, 0 on failure
 */
int pushNode(node **head, int data)
{
	node *new = createNode(data);

	if (new == NULL)
	{
		fprintf(stderr, "pushNode - coudn't create a new node");
		return (0);
	}

	if (*head == NULL)
	{
		(*head) = new;
	}
	else
	{
		node *thead = *head;

		while (thead->next)
		{
			thead = thead->next;
		}

		new->next = NULL;
		thead->next = new;
	}

	return (1);
}

/**
 * removeNodeAt - Remove the node at the specified index
 * from the linked list
 *
 * @head: Pointer to a pointer to the head of the linked list
 * @index: The index of the node to be removed
 *
 * Return: 1 on success, 0 on failure
 */
int removeNodeAt(node **head, int index)
{
	if (*head == NULL || index < 0 || index >= linkedListLength(*head))
	{
		fprintf(stderr, "removeNodeAt - Index out of bound");
		return (0);
	}

	if (index == 0)
	{
		node *temp = (*head)->next;

		free(*head);
		(*head) = temp;
		return (1);
	}

	node *curr = (*head);
	int i;

	for (i = 0; curr != NULL; i++)
	{
		if (i == index - 1)
			break;
		curr = curr->next;
	}

	node *todelete = curr->next;

	/*
	 * This line sets the curr pointer to NULL
	 * in case the node to be deleted (todelete)
	 * is the last node in the linked list.
	 */
	if (!todelete)
		curr = NULL;

	curr->next = todelete->next;

	free(todelete);
	return (1);
}

/**
 * popNode - Remove the last node from the linked list
 *
 * @head: Pointer to a pointer to the head of the linked list
 *
 * Return: 1 on success, 0 on failure
 */
int popNode(node **head)
{
	if (*head == NULL)
	{
		fprintf(stderr, "popNode - the head is NULL");
		return (0);
	}

	int index = linkedListLength(*head) - 1;

	return (removeNodeAt(&(*head), index));
}

/**
 * sortedInsert - Insert a new node with the given data in sorted order
 *
 * @head: Pointer to a pointer to the head of the linked list
 * @data: The data to be stored in the new node
 *
 * Return: 1 on success, 0 on failure
 */
int sortedInsert(node **head, int data)
{
	node *new = createNode(data);

	if (new == NULL)
	{
		fprintf(stderr, "sortedInsert - couldn't create a new node");
		return (0);
	}

	if (*head == NULL)
	{
		(*head) = new;
	}
	else if (data <= (*head)->data)
	{
		new->data = data;
		new->next = *head;

		(*head) = new;
	}
	else
	{
		node *thead = *head;

		while (thead->next && data > thead->next->data)
		{
			thead = thead->next;
		}

		new->next = thead->next;
		thead->next = new;
	}

	return (1);
}

/**
 * sortLinkedList - Sort the linked list in ascending order
 *
 * @head: Pointer to a pointer to the head of the linked list
 *
 * Return: void
 */
void sortLinkedList(node **head)
{
	if (*head == NULL || (*head)->next == NULL)
		return;

	node *temp;
	node *sorted = NULL;
	int status = 1;

	/*
	 * This loop traverses the original linked list (*head)
	 * and calls sortedInsert to insert each node
	 * in sorted order into a new linked list sorted.
	 * The variable status is used to check if the
	 * sorted insertion process was successful.
	 */
	for (temp = *head; temp != NULL; temp = temp->next)
	{
		status = status ? sortedInsert(&sorted, temp->data) : 0;
	}

	if (!status)
	{
		fprintf(stderr, "sortLinkedList - Cound't sort the linked list");
		return;
	}
	freeLinkedList(*head);

	(*head) = sorted;
}

/**
 * freeLinkedList - Free the memory allocated for the linked list
 *
 * @head: Pointer to the head of the linked list
 *
 * Return: void
 */
void freeLinkedList(node *head)
{
	if (!head)
		return;

	node *temp;

	/*
	 * This loop iterates through the linked list,
	 * freeing the memory allocated for each node
	 * until the entire list is freed.
	 */
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * linkedListLength - Calculate the length of the linked list
 *
 * @head: Pointer to the head of the linked list
 *
 * Return: The length of the linked list
 */
int linkedListLength(node *head)
{
	int i = 0;

	for (i = 0; head != NULL; i++)
		head = head->next;
	return (i);
}

/**
 * printLinkedList - Print the elements of the linked list
 *
 * @head: Pointer to the head of the linked list
 *
 * Return: void
 */
void printLinkedList(node *head)
{
	if (head == NULL)
	{
		printf("List is empty :(");
	}

	node *temp;

	for (temp = head; temp != NULL; temp = temp->next)
	{
		printf("%d", temp->data);

		if (temp->next != NULL)
			printf(" -> ");
	}

	putchar('\n');
}
