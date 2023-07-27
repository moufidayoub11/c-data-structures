# Linked List in C

This sub-folder contains the implementation of a singly linked list data structure in C.

## Introduction

A linked list is a linear data structure consisting of a sequence of nodes, where each node contains data and a reference to the next node. Unlike arrays, linked lists do not store elements in contiguous memory locations. Instead, each node points to the next node, forming a chain-like structure.

### Advantages of Linked Lists:
- Dynamic Memory Allocation: Linked lists allow for efficient memory allocation as nodes can be dynamically created and connected during runtime.
- Easy Insertion and Deletion: Insertion and deletion operations can be performed at any point in the linked list with constant time complexity, provided the position of the node is known.
- Flexibility: Linked lists can easily grow or shrink based on the number of elements they hold, as memory is allocated on-demand.

### Disadvantages of Linked Lists:
- Sequential Access: Unlike arrays, linked lists do not offer constant-time random access to elements. Traversing the list to access an element requires linear time.
- Extra Memory Overhead: Each node in the linked list contains both data and a pointer to the next node, resulting in more memory overhead compared to arrays.

## Functions

The linked list implementation includes the following functions:

1. `node *createNode(int data)`: Create a new node with the given data.

2. `int pushNode(node **head, int data)`: Add a new node with the given data to the end of the list.

3. `int removeNodeAt(node **head, int index)`: Remove the node at the specified index from the list.

4. `int popNode(node **head)`: Remove the last node from the list.

5. `int sortedInsert(node **head, int data)`: Insert a new node with the given data in sorted order.

6. `void sortLinkedList(node **head)`: Sort the linked list in ascending order.

7. `void freeLinkedList(node *head)`: Free the memory allocated for the linked list.

8. `int linkedListLength(node *head)`: Calculate the length of the linked list.

9. `void printLinkedList(node *head)`: Print the elements of the linked list.

### Function Descriptions:

- `createNode`: This function allocates memory for a new node and initializes it with the provided data. It returns a pointer to the newly created node.

- `pushNode`: This function adds a new node with the given data to the end of the linked list. If the list is empty, it sets the new node as the head. 

- `removeNodeAt`: This function removes the node at the specified index from the linked list. It handles edge cases such as removing the head node or a node in the middle.

- `popNode`: This function removes the last node from the linked list. It is a convenience function that uses `removeNodeAt` to remove the node at the last index.

- `sortedInsert`: This function inserts a new node with the given data in sorted order. It assumes the linked list is already sorted in ascending order.

- `sortLinkedList`: This function sorts the linked list in ascending order using the `sortedInsert` function.

- `freeLinkedList`: This function frees the memory allocated for the entire linked list by iteratively freeing each node.

- `linkedListLength`: This function calculates and returns the length of the linked list.

- `printLinkedList`: This function prints the elements of the linked list in a readable format.

## Usage

To use the Linked List implementation in your C projects:

1. Include the `linked_list.h` header in your C source files.

2. Copy the `linked_list.c` and `linked_list.h` files into your project directory.

3. Utilize the provided functions to create, manipulate, and print linked lists.

### Examples:

To use the Linked List implementation in your C projects:

Include the linked_list.h header in your C source files.

Copy the linked_list.c and linked_list.h files into your project directory.

Utilize the provided functions to create, manipulate, and print linked lists.

Examples:
1. Creating and Printing a Linked List:
```c
#include <stdio.h>
#include "linked_list.h"

int main() {
    node *head = NULL;

    // Add nodes to the linked list
    pushNode(&head, 10);
    pushNode(&head, 20);
    pushNode(&head, 30);

    // Print the linked list
    printLinkedList(head);

    // Output: 10 -> 20 -> 30
    return 0;
}
```
2. Removing Nodes from the Linked List:
```c
#include <stdio.h>
#include "linked_list.h"

int main() {
    node *head = NULL;

    // Add nodes to the linked list
    pushNode(&head, 10);
    pushNode(&head, 20);
    pushNode(&head, 30);

    // Remove the node at index 1
    removeNodeAt(&head, 1);

    // Print the updated linked list
    printLinkedList(head);

    // Output: 10 -> 30
    return 0;
}
```
3. Sorting a Linked List:
```c
#include <stdio.h>
#include "linked_list.h"

int main() {
    node *head = NULL;

    // Add nodes to the linked list in unsorted order
    pushNode(&head, 30);
    pushNode(&head, 10);
    pushNode(&head, 20);

    // Sort the linked list in ascending order
    sortLinkedList(&head);

    // Print the sorted linked list
    printLinkedList(head);

    // Output: 10 -> 20 -> 30
    return 0;
}
```
## Contribution

Contributions to this repository are welcome! If you want to contribute, follow the guidelines mentioned in the main README file.

Please ensure that your code adheres to the existing coding style and passes all existing automated tests.

## Additional Resources

To learn more about linked lists, consider exploring the following resources:

- [Data Structures: Linked Lists by GeeksforGeeks](https://www.geeksforgeeks.org/data-structures-linked-list/)

- [Linked List Wikipedia page](https://en.wikipedia.org/wiki/Linked_list)

- [Linked List Data Structure in C - Tutorialspoint](https://www.tutorialspoint.com/data_structures_algorithms/linked_list_program_in_c.htm)

- [C Programming - Linked List - TutorialsTeacher](https://www.tutorialsteacher.com/c/c-linked-list)
