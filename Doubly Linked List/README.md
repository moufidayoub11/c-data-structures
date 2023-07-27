# Doubly Linked List

This sub-folder contains the implementation of a doubly linked list data structure in C.

## Introduction

A doubly linked list is a linear data structure consisting of a sequence of nodes, where each node contains data, a reference to the next node, and a reference to the previous node. Unlike singly linked lists, doubly linked lists allow traversal in both directions, making it easier to navigate the list.

### Advantages of Doubly Linked Lists:
- Bi-directional Traversal: Unlike singly linked lists, doubly linked lists allow easy traversal in both forward and backward directions.
- Insertion and Deletion Efficiency: Insertion and deletion operations can be performed at any point in the list with constant time complexity, provided the position of the node is known.
- Memory Utilization: Although doubly linked lists require more memory due to the additional previous pointers, they provide added flexibility and ease of navigation.

### Disadvantages of Doubly Linked Lists:
- Memory Overhead: Each node in the doubly linked list contains additional pointers, resulting in higher memory overhead compared to singly linked lists.
- Complexity: The implementation and management of doubly linked lists require more complexity due to the presence of two pointers in each node.

## Functions

The doubly linked list implementation includes the following functions:

1. `node *createNode(int data)`: Create a new node with the given data.

2. `int pushNode(node **head, int data)`: Add a new node with the given data to the end of the list.

3. `int removeNodeAt(node **head, int index)`: Remove the node at the specified index from the list.

4. `int popNode(node **head)`: Remove the last node from the list.

5. `int sortedInsert(node **head, int data)`: Insert a new node with the given data in sorted order.

6. `void sortDoublyLinkedList(node **head)`: Sort the doubly linked list in ascending order.

7. `void freeDoublyLinkedList(node *head)`: Free the memory allocated for the doubly linked list.

8. `int doublyLinkedListLength(node *head)`: Calculate the length of the doubly linked list.

9. `void printDoublyLinkedList(node *head)`: Print the elements of the doubly linked list.

### Function Descriptions:

- `createNode`: This function allocates memory for a new node and initializes it with the provided data. It returns a pointer to the newly created node.

- `pushNode`: This function adds a new node with the given data to the end of the doubly linked list. If the list is empty, it sets the new node as the head.

- `removeNodeAt`: This function removes the node at the specified index from the doubly linked list. It handles edge cases such as removing the head node or a node in the middle.

- `popNode`: This function removes the last node from the doubly linked list. It is a convenience function that uses `removeNodeAt` to remove the node at the last index.

- `sortedInsert`: This function inserts a new node with the given data in sorted order. It assumes the doubly linked list is already sorted in ascending order.

- `sortDoublyLinkedList`: This function sorts the doubly linked list in ascending order using the `sortedInsert` function.

- `freeDoublyLinkedList`: This function frees the memory allocated for the entire doubly linked list by iteratively freeing each node.

- `doublyLinkedListLength`: This function calculates and returns the length of the doubly linked list.

- `printDoublyLinkedList`: This function prints the elements of the doubly linked list in both forward and backward directions.

## Usage

To use the Doubly Linked List implementation in your C projects:

1. Include the `doubly_linked_list.h` header in your C source files.

2. Copy the `doubly_linked_list.c` and `doubly_linked_list.h` files into your project directory.

3. Utilize the provided functions to create, manipulate, and print doubly linked lists.

### Examples:

To use the Doubly Linked List implementation in your C projects:

Include the doubly_linked_list.h header in your C source files.

Copy the doubly_linked_list.c and doubly_linked_list.h files into your project directory.

Utilize the provided functions to create, manipulate, and print doubly linked lists.

Examples:
1. Creating and Printing a Doubly Linked List:
```c
#include <stdio.h>
#include "doubly_linked_list.h"

int main() {
    node *head = NULL;

    // Add nodes to the doubly linked list
    pushNode(&head, 10);
    pushNode(&head, 20);
    pushNode(&head, 30);

    // Print the doubly linked list in forward direction
    printDoublyLinkedList(head);

    // Output: 10 -> 20 -> 30

    // Print the doubly linked list in backward direction
    printDoublyLinkedListReverse(head);

    // Output: 30 -> 20 -> 10

    return 0;
}
```

2. Removing Nodes from the Doubly Linked List:
```c
#include <stdio.h>
#include "doubly_linked_list.h"

int main() {
    node *head = NULL;

    // Add nodes to the doubly linked list
    pushNode(&head, 10);
    pushNode(&head, 20);
    pushNode(&head, 30);

    // Remove the node at index 1
    removeNodeAt(&head, 1);

    // Print the updated doubly linked list
    printDoublyLinkedList(head);

    // Output: 10 -> 30
    return 0;
}
```
3. Sorting a Doubly Linked List:
```c
#include <stdio.h>
#include "doubly_linked_list.h"

int main() {
    node *head = NULL;

    // Add nodes to the doubly linked list in unsorted order
    pushNode(&head, 30);
    pushNode(&head, 10);
    pushNode(&head, 20);

    // Sort the doubly linked list in ascending order
    sortDoublyLinkedList(&head);

    // Print the sorted doubly linked list
    printDoublyLinkedList(head);

    // Output: 10 -> 20 -> 30
    return 0;
}
```

## Contribution

Contributions to this repository are welcome! If you want to contribute, follow the guidelines mentioned in the main README file.

Please ensure that your code adheres to the existing coding style and passes all existing automated tests.

## Additional Resources

To learn more about doubly linked lists, consider exploring the following resources:

- [Doubly Linked List by GeeksforGeeks](https://www.geeksforgeeks.org/doubly-linked-list/)

- [Doubly Linked List Wikipedia page](https://en.wikipedia.org/wiki/Doubly_linked_list)

- [Doubly Linked List Data Structure in C - Tutorialspoint](https://www.tutorialspoint.com/data_structures_algorithms/doubly_linked_list_program_in_c.htm)

- [C Programming - Doubly Linked List - TutorialsTeacher](https://www.tutorialsteacher.com/c/c-doubly-linked-list)
