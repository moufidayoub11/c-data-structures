#include "doubly_linked_list.h"

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
		fprintf(stderr, "createNode - coudn't create a new node");
		return (NULL);
	}

	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

/**
 * pushNode - Add a new node with the given data to the end of
 * the doubly linked list
 *
 * @head: Pointer to a pointer to the head of the doubly linked list
 * @data: The data to be stored in the new node
 *
 * Return: 1 on success, 0 on failure
 */
int pushNode(node **head, int data)
{
	node *new = createNode(data);

	if (new == NULL)
	{
		fprintf(stderr, "pushNode - Coudn't create a new node");
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
			thead = thead->next;

		new->prev = thead;
		new->next = NULL;
		thead->next = new;
	}
	return (1);
}

/**
 * removeNodeAt - Remove the node at the specified index
 * from the doubly linked list
 *
 * @head: Pointer to a pointer to the head of the doubly linked list
 * @index: The index of the node to be removed
 *
 * Return: 1 on success, 0 on failure
 */
int removeNodeAt(node **head, int index)
{
	if (*head == NULL || index < 0 || index >= doublyLinkedListLength(*head))
	{
		fprintf(stderr, "removeNodeAt - Index out of bound");
		return (-1);
	}

	if (index == 0)
	{
		node *temp = (*head)->next;

		if (temp)
			temp->prev = NULL;

		free(*head);
		(*head) = temp;

		return (1);
	}

	node *curr = (*head);

	for (int i = 0; curr != NULL; i++)
	{
		if (i == index - 1)
			break;
		curr = curr->next;
	}

	node *todelete = curr->next;

	if (todelete->next)
		todelete->next->prev = curr;

	todelete->prev->next = todelete->next;

	free(todelete);

	return (1);
}

/**
 * sortedInsert - Insert a new node with the given data in sorted order
 *
 * @head: Pointer to a pointer to the head of the doubly linked list
 * @data: The data to be stored in the new node
 *
 * Return: 1 on success, 0 on failure
 */
int sortedInsert(node **head, int data)
{
	node *new = createNode(data);

	if (new == NULL)
	{
		fprintf(stderr, "sortedInsert - coudn't create a new node");
		return (0);
	}

	if (*head == NULL)
	{
		(*head) = new;
	}

	else if (data <= (*head)->data)
	{
		new->next = *head;
		new->prev = NULL;
		new->next->prev = new;

		(*head) = new;
	}
	else
	{
		node *curr = *head;

		while (curr->next && data > curr->next->data)
			curr = curr->next;

		new->next = curr->next;

		if (curr->next)
			new->next->prev = new;

		curr->next = new;
		new->prev = curr;
	}

	return (1);
}

/**
 * sortDoublyLinkedList - Sort the doubly linked list in ascending order
 *
 * @head: Pointer to a pointer to the head of the doubly linked list
 *
 * Return: void
 */
void sortDoublyLinkedList(node **head)
{
	if (*head == NULL || (*head)->next == NULL)
		return;

	node *temp;
	node *sorted = NULL;
	int status = 1;

	for (temp = *head; temp != NULL; temp = temp->next)
	{
		status = status ? sortedInsert(&sorted, temp->data) : 0;
	}

	if (!status)
	{
		fprintf(stderr, "sortLinkedList - coudn't sort the linked list");
		return;
	}

	freeLinkedList(*head);

	(*head) = sorted;
}

/**
 * doublyLinkedListLength - Calculate the length of the doubly linked list
 *
 * @head: Pointer to the head of the doubly linked list
 *
 * Return: The length of the doubly linked list
 */
int doublyLinkedListLength(node *head)
{
	int i = 1;

	for (i = 1; head != NULL; i++)
		head = head->next;

	return (i);
}

/**
 * freeLinkedList - Free the memory allocated for the doubly linked list
 *
 * @head: Pointer to the head of the doubly linked list
 *
 * Return: void
 */
void freeLinkedList(node *head)
{
	if (!head)
		return;

	node *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * printDoublyLinkedList - Print the elements of the doubly linked list
 *
 * @head: Pointer to the head of the doubly linked list
 *
 * Return: void
 */
void printDoublyLinkedList(node *head)
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
			printf(" <=> ");
	}
	putchar('\n');
}
