#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

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

        printLinkedList(head);

        printf("****************************\n");

        sortLinkedList(&head);
        printLinkedList(head);

        freeLinkedList(head);
        return (0);
}
