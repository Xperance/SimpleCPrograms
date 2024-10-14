#include "SqList.h"
#include <stdio.h>

/*
 * This is an example demonstrating how to use the functions for sequential lists.
 * In this example, we create a sequential list and perform various operations
 * such as inserting elements, deleting elements, locating elements, finding
 * predecessors and successors, and reordering the list to place odd numbers
 * before even numbers.
 *
 * Test Cases and Predicted Output:
 * 1. Insert elements 10, 15, 20, and 5 at specified positions.
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
    InitList(&list);

    // Test inserting elements
    printf("Test inserting elements:\n");
    ListInsert(&list, 1, 10);
    ListInsert(&list, 2, 15);
    ListInsert(&list, 3, 20);
    ListInsert(&list, 2, 5);
    for (int i = 0; i < list.length; i++) {
        printf("%d ", list.elem[i]);
    }
    printf("\n");

    // Test deleting elements
    printf("Test deleting elements:\n");
    ListDelete(&list, 2);
    for (int i = 0; i < list.length; i++) {
        printf("%d ", list.elem[i]);
    }
    printf("\n");

    // Test locating an element
    printf("Test locating an element:\n");
    int pos = LocateElem(&list, 15);
    if (pos != -1) {
        printf("The position of element 15 is: %d\n", pos);
    }

    // Test finding predecessor and successor
    printf("Test finding predecessor and successor:\n");
    ElemType prior = PriorElem(&list, 15);
    if (prior != -1) {
        printf("The predecessor of element 15 is: %d\n", prior);
    }
    ElemType next = NextElem(&list, 15);
    if (next != -1) {
        printf("The successor of element 15 is: %d\n", next);
    }

    // Test reordering list with odd numbers before even numbers
    printf("Test reordering list with odd numbers before even numbers:\n");
    ListInsert(&list, 4, 7);
    ListInsert(&list, 5, 8);
    ChangeNums(&list);
    for (int i = 0; i < list.length; i++) {
        printf("%d ", list.elem[i]);
    }
    printf("\n");

    DestroyList(&list);
    return 0;
}