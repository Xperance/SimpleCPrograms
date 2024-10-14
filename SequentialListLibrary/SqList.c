#include "SqList.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Initializes a new sequential list.
 *
 * Allocates memory for the list and sets initial values for its attributes.
 *
 * @param L Pointer to the list to be initialized.
 */
void InitList(SqList* L) {
    L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L->elem) {
        printf("Memory allocation failed\n");
        return;
    }
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
}

/**
 * @brief Checks if the sequential list is empty.
 *
 * @param L Pointer to the list.
 * @return TRUE if the list is empty, otherwise FALSE.
 */
int JudgmentList(SqList* L) {
    if (L->length == 0) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

/**
 * @brief Returns the current length of the sequential list.
 *
 * @param L Pointer to the list.
 * @return The number of elements in the list.
 */
int LengthList(SqList* L) {
    return L->length;
}

/**
 * @brief Returns the element at the specified position in the list.
 *
 * @param L Pointer to the list.
 * @param i The position (1-based index) of the element to retrieve.
 * @return The element at the specified position.
 */
ElemType OrderNum(SqList* L, int i) {
    if (i < 1 || i > L->length) {
        printf("Invalid position\n");
        return -1; // Return -1 to indicate an error
    }
    return L->elem[i - 1];
}

/**
 * @brief Expands the size of the list by a defined increment.
 *
 * Allocates additional memory to the list to allow for more elements.
 *
 * @param L Pointer to the list.
 */
void ExpandList(SqList* L) {
    ElemType* newbase = (ElemType*)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
    if (!newbase) {
        printf("Expansion failed\n");
        return;
    }
    L->elem = newbase;
    L->listsize += LISTINCREMENT;
    printf("Expansion successful, new capacity: %d\n", L->listsize);
}

/**
 * @brief Shrinks the size of the list by a defined decrement if necessary.
 *
 * Releases excess memory if the list's capacity is much larger than its length.
 *
 * @param L Pointer to the list.
 */
void ShrinkList(SqList* L) {
    if (L->listsize - LISTDECREMENT >= L->length) {
        ElemType* newbase = (ElemType*)realloc(L->elem, (L->listsize - LISTDECREMENT) * sizeof(ElemType));
        if (!newbase) {
            printf("Shrinkage failed\n");
            return;
        }
        L->elem = newbase;
        L->listsize -= LISTDECREMENT;
        printf("Shrinkage successful, new capacity: %d\n", L->listsize);
    }
}

/**
 * @brief Inserts an element at the specified position in the list.
 *
 * Shifts subsequent elements to the right to make space for the new element.
 *
 * @param L Pointer to the list.
 * @param i The position (1-based index) at which to insert the element.
 * @param e The element to be inserted.
 */
void ListInsert(SqList* L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1) {
        printf("Invalid insertion position\n");
        return;
    }
    // Check if expansion is needed
    if (L->length >= L->listsize) {
        ExpandList(L);
    }
    ElemType* q = &(L->elem[i - 1]);
    ElemType* p = &(L->elem[L->length - 1]);
    for (p = &(L->elem[L->length - 1]); p >= q; --p) {
        *(p + 1) = *p;
    }
    *q = e;
    L->length++;
}

/**
 * @brief Deletes the element at the specified position in the list.
 *
 * Shifts subsequent elements to the left to fill the gap left by the deleted element.
 *
 * @param L Pointer to the list.
 * @param i The position (1-based index) of the element to delete.
 */
void ListDelete(SqList* L, int i) {
    if (i < 1 || i > L->length) {
        printf("Invalid deletion position\n");
        return;
    }
    ElemType* p = &(L->elem[i - 1]);
    ElemType* q = &(L->elem[L->length - 1]);
    for (++p; p <= q; ++p) {
        *(p - 1) = *p;
    }
    L->length--;
    // Check if shrinkage is needed
    if (L->listsize - LISTDECREMENT >= LIST_INIT_SIZE && L->length <= L->listsize - LISTINCREMENT) {
        ShrinkList(L);
    }
}

/**
 * @brief Returns the predecessor of the specified element in the list.
 *
 * @param L Pointer to the list.
 * @param e The element whose predecessor is to be found.
 * @return The predecessor element, or -1 if none exists.
 */
ElemType PriorElem(SqList* L, ElemType e) {
    int found = 0;
    for (int i = 0; i < L->length; i++) {
        if (L->elem[i] == e) {
            found = 1;
            if (i == 0) {
                printf("No predecessor exists for this element\n");
                return -1;
            }
            return L->elem[i - 1];
        }
    }
    if (!found) {
        printf("Element not found\n");
        return -1;
    }
}

/**
 * @brief Returns the successor of the specified element in the list.
 *
 * @param L Pointer to the list.
 * @param e The element whose successor is to be found.
 * @return The successor element, or -1 if none exists.
 */
ElemType NextElem(SqList* L, ElemType e) {
    int found = 0;
    for (int i = 0; i < L->length; i++) {
        if (L->elem[i] == e) {
            found = 1;
            if (i == L->length - 1) {
                printf("No successor exists for this element\n");
                return -1;
            }
            return L->elem[i + 1];
        }
    }
    if (!found) {
        printf("Element not found\n");
        return -1;
    }
}

/**
 * @brief Locates an element in the list and returns its position.
 *
 * @param L Pointer to the list.
 * @param e The element to locate.
 * @return The position (1-based index) of the element, or -1 if not found.
 */
int LocateElem(SqList* L, ElemType e) {
    for (int i = 0; i < L->length; i++) {
        if (L->elem[i] == e) {
            return i + 1;
        }
    }
    printf("Element not found\n");
    return -1;
}

/**
 * @brief Clears all elements from the list.
 *
 * Sets the length of the list to 0 without releasing allocated memory.
 *
 * @param L Pointer to the list.
 */
void ClearList(SqList* L) {
    L->length = 0;
    printf("List cleared\n");
}

/**
 * @brief Destroys the list and releases all allocated memory.
 *
 * Frees the memory allocated for the list and resets its attributes.
 *
 * @param L Pointer to the list to be destroyed.
 */
void DestroyList(SqList* L) {
    if (L->elem != NULL) {
        free(L->elem);
        L->elem = NULL;
        L->length = 0;
        L->listsize = 0;
        printf("List destroyed\n");
    }
}

/**
 * @brief Swaps the values of two elements.
 *
 * @param a Pointer to the first element.
 * @param b Pointer to the second element.
 */
void Swap(ElemType* a, ElemType* b) {
    ElemType temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Reorders the list such that odd numbers precede even numbers.
 *
 * Partitions the list into two parts, with all odd elements appearing before all even elements.
 *
 * @param L Pointer to the list.
 */
void ChangeNums(SqList* L) {
    int left = 0;
    int right = L->length - 1;
    while (left < right) {
        // Move left pointer to the right until an even number is found
        while (left < right && L->elem[left] % 2 != 0) {
            left++;
        }
        // Move right pointer to the left until an odd number is found
        while (left < right && L->elem[right] % 2 == 0) {
            right--;
        }
        // Swap the odd and even numbers
        if (left < right) {
            Swap(&L->elem[left], &L->elem[right]);
        }
    }
}