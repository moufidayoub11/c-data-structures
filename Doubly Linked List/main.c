#include "doubly_linked_list.h"

node *createNode(int data);
int pushNode(node **head, int data);
int removeNodeAt(node **head, int index);
int popNode(node **head);
int sortedInsert(node **head, int data);
void sortDoublyLinkedList(node **head);
int doublyLinkedListLength(node *head);
void freeLinkedList(node *head);
void printDoublyLinkedList(node *head);

/**
 * main - Entry point
 *
 * Return: (0), if successful
 */
int main(void)
{
        node *head;
        int n;

        printf("How many nodes you want: ");
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
        {
                int data;

                printf("Node %d: ", i);
                scanf("%d", &data);
                pushNode(&head, data);
        }


        printDoublyLinkedList(head);
        printf("-----------------\n");

        sortDoublyLinkedList(&head);

        printDoublyLinkedList(head);

        freeLinkedList(head);
        return (0);
}
