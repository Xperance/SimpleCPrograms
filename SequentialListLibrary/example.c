#include "SqList.h"
#include <stdio.h>

/*
 * This is an example demonstrating how to use the functions for sequential lists.
 * In this example, we create a sequential list and perform various operations,
 * such as inserting elements, deleting elements, locating elements, finding
 * predecessors and successors, and reordering the list to place odd numbers
 * before even numbers.
 *
 * Test Cases and Predicted Output:
 * 1. Insert elements 10, 15, 20, and insert 5 at a specific position.
 *    Expected list: 10 5 15 20
 *
 * 2. Delete the element at position 2.
 *    Expected list: 10 15 20
 *
 * 3. Locate the element 15.
 *    Expected output: The position of element 15 is: 2
 *
 * 4. Find the predecessor and successor of element 15.
 *    Expected output: The predecessor of element 15 is: 10
 *                    The successor of element 15 is: 20
 *
 * 5. Reorder the list with odd numbers before even numbers.
 *    Insert elements 7 and 8, then reorder.
 *    Expected list after reordering: 15 7 5 10 20 8
 */

int main() {
    SqList list;
    ElemType result;
    int status;

    // Initialize the list
    printf("Initializing the list...\n");
    InitList(&list);
    PrintList(&list);

    // Test inserting elements
    printf("\nTesting inserting elements...\n");
    status = ListInsert(&list, 1, 10);
    if (status == FALSE) {
        printf("Failed to insert element 10 at position 1\n");
    }
    status = ListInsert(&list, 2, 15);
    if (status == FALSE) {
        printf("Failed to insert element 15 at position 2\n");
    }
    status = ListInsert(&list, 3, 20);
    if (status == FALSE) {
        printf("Failed to insert element 20 at position 3\n");
    }
    status = ListInsert(&list, 2, 5);
    if (status == FALSE) {
        printf("Failed to insert element 5 at position 2\n");
    }
    PrintList(&list);

    // Test deleting elements
    printf("\nTesting deleting elements...\n");
    status = ListDelete(&list, 2);
    if (status == FALSE) {
        printf("Failed to delete element at position 2\n");
    }
    PrintList(&list);

    // Test locating an element
    printf("\nTesting locating an element...\n");
    int pos = LocateElem(&list, 15);
    if (pos != FALSE) {
        printf("The position of element 15 is: %d\n", pos);
    } else {
        printf("Element 15 not found\n");
    }

    // Test finding predecessor
    printf("\nTesting finding predecessor...\n");
    if (PriorElem(&list, 15, &result) == TRUE) {
        printf("The predecessor of element 15 is: %d\n", result);
    } else {
        printf("No predecessor found for element 15\n");
    }

    // Test finding successor
    printf("\nTesting finding successor...\n");
    if (NextElem(&list, 15, &result) == TRUE) {
        printf("The successor of element 15 is: %d\n", result);
    } else {
        printf("No successor found for element 15\n");
    }

    // Test expanding the list
    printf("\nTesting expanding the list...\n");
    status = ExpandList(&list);
    if (status == FALSE) {
        printf("Failed to expand the list\n");
    } else {
        printf("List expanded successfully\n");
    }
    PrintList(&list);

    // Test reordering list with odd numbers before even numbers
    printf("\nTesting reordering list with odd numbers before even numbers...\n");
    ListInsert(&list, 4, 7);
    ListInsert(&list, 5, 8);
    ChangeNums(&list);
    PrintList(&list);

    // Test clearing the list
    printf("\nTesting clearing the list...\n");
    ClearList(&list);
    PrintList(&list);

    // Test destroying the list
    printf("\nTesting destroying the list...\n");
    DestroyList(&list);

    return 0;
}
