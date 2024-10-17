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
 * @brief Retrieves the element at the specified position in the list.
 *
 * Searches for the element at position `i` (1-based index) in the list `L`.
 * The result is returned through a pointer argument, and a status code is returned to indicate success or failure.
 *
 * @param L Pointer to the list.
 * @param i The position (1-based index) of the element to retrieve.
 * @param result Pointer to store the element if found.
 * @return TRUE if the element exists at the specified position, FALSE if the position is invalid.
 */
int OrderNum(SqList* L, int i, ElemType* result) {
    if (i < 1 || i > L->length) {
        printf("Invalid position\n");
        return FALSE;
    }
    *result = L->elem[i - 1];
    return TRUE;
}


/**
 * @brief Expands the size of the list by a defined increment.
 *
 * Allocates additional memory to the list to allow for more elements.
 *
 * @param L Pointer to the list.
 * @return TRUE if expansion is successful, otherwise FALSE.
 */
int ExpandList(SqList* L) {
    ElemType* newbase = (ElemType*)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
    if (!newbase) {
        printf("Expansion failed\n");
        return FALSE;
    }
    L->elem = newbase;
    L->listsize += LISTINCREMENT;
    printf("Expansion successful, new capacity: %d\n", L->listsize);
    return TRUE;
}

/**
 * @brief Shrinks the size of the list by a defined decrement if necessary.
 *
 * Releases excess memory if the list's capacity is much larger than its length.
 *
 * @param L Pointer to the list.
 * @return TRUE if shrinkage is successful, otherwise FALSE.
 */
int ShrinkList(SqList* L) {
    if (L->listsize - LISTDECREMENT >= L->length) {
        ElemType* newbase = (ElemType*)realloc(L->elem, (L->listsize - LISTDECREMENT) * sizeof(ElemType));
        if (!newbase) {
            printf("Shrinkage failed\n");
            return FALSE;
        }
        L->elem = newbase;
        L->listsize -= LISTDECREMENT;
        printf("Shrinkage successful, new capacity: %d\n", L->listsize);
        return TRUE;
    }
    return FALSE;
}

/**
 * @brief Inserts an element at the specified position in the list.
 *
 * Shifts subsequent elements to the right to make space for the new element.
 *
 * @param L Pointer to the list.
 * @param i The position (1-based index) at which to insert the element.
 * @param e The element to be inserted.
 * @return TRUE if the insertion is successful, otherwise FALSE.
 */
int ListInsert(SqList* L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1) {
        printf("Invalid insertion position\n");
        return FALSE;
    }
    // Check if expansion is needed
    if (L->length >= L->listsize) {
        if (ExpandList(L) == FALSE) {
            printf("Failed to expand the list during insertion\n");
            return FALSE;
        }
    }
    ElemType* q = &(L->elem[i - 1]);
    ElemType* p = &(L->elem[L->length - 1]);
    for (p = &(L->elem[L->length - 1]); p >= q; --p) {
        *(p + 1) = *p;
    }
    *q = e;
    L->length++;
    return TRUE;
}

/**
 * @brief Deletes the element at the specified position in the list.
 *
 * Shifts subsequent elements to the left to fill the gap left by the deleted element.
 *
 * @param L Pointer to the list.
 * @param i The position (1-based index) of the element to delete.
 * @return TRUE if the deletion is successful, otherwise FALSE.
 */
int ListDelete(SqList* L, int i) {
    if (i < 1 || i > L->length) {
        printf("Invalid deletion position\n");
        return FALSE;
    }
    ElemType* q = &(L->elem[i - 1]);
    ElemType* p = &(L->elem[L->length - 1]);
    for (++q; q <= p; ++q) {
        *(q - 1) = *q;
    }
    L->length--;
    // Check if shrinkage is needed
    if (L->listsize - LISTDECREMENT >= LIST_INIT_SIZE && L->length <= L->listsize - LISTINCREMENT) {
        if (ShrinkList(L) == FALSE) {
            printf("Failed to shrink the list during deletion\n");
            return FALSE;
        }
    }
    return TRUE;
}

/**
 * @brief Returns the predecessor of the specified element in the list.
 *
 * Searches for the element `e` in the list `L` and, if found, returns its predecessor.
 * The result is returned through a pointer argument, and a status code is returned to indicate success or failure.
 *
 * @param L Pointer to the list.
 * @param e The element whose predecessor is to be found.
 * @param result Pointer to store the predecessor element, if found.
 * @return TRUE if the predecessor exists, FALSE if the element is not found or has no predecessor.
 */
int PriorElem(SqList* L, ElemType e, ElemType* result) {
    for (int i = 0; i < L->length; i++) {
        if (L->elem[i] == e) {
            if (i == 0) {
                printf("No predecessor exists for this element\n");
                return FALSE;
            }
            *result = L->elem[i - 1];
            return TRUE;
        }
    }
    printf("Element not found\n");
    return FALSE;
}

/**
 * @brief Returns the successor of the specified element in the list.
 *
 * Searches for the element `e` in the list `L` and, if found, returns its successor.
 * The result is returned through a pointer argument, and a status code is returned to indicate success or failure.
 *
 * @param L Pointer to the list.
 * @param e The element whose successor is to be found.
 * @param result Pointer to store the successor element, if found.
 * @return TRUE if the successor exists, FALSE if the element is not found or has no successor.
 */
int NextElem(SqList* L, ElemType e, ElemType* result) {
    for (int i = 0; i < L->length; i++) {
        if (L->elem[i] == e) {
            if (i == L->length - 1) {
                printf("No successor exists for this element\n");
                return FALSE;
            }
            *result = L->elem[i + 1];
            return TRUE;
        }
    }
    printf("Element not found\n");
    return FALSE;
}

/**
 * @brief Locates an element in the list and returns its position.
 *
 * @param L Pointer to the list.
 * @param e The element to locate.
 * @return The position (1-based index) of the element, or FALSE if not found.
 */
int LocateElem(SqList* L, ElemType e) {
    for (int i = 0; i < L->length; i++) {
        if (L->elem[i] == e) {
            return i + 1;
        }
    }
    printf("Element not found\n");
    return FALSE;
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

/**
 * @brief Prints all elements in the list.
 *
 * Iterates through the list `L` and prints each element.
 *
 * @param L Pointer to the list.
 */
void PrintList(SqList* L) {
    if (L == NULL || L->length == 0) {
        printf("The list is empty or does not exist\n");
        return;
    }
    printf("Elements in the list: ");
    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}