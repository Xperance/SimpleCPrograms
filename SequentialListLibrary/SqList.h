#ifndef Xperance_SQLIST
#define Xperance_SQLIST

#define LIST_INIT_SIZE 80 ///< The initial size allocated for the list
#define LISTINCREMENT 10 ///< The size increment used when expanding the list
#define LISTDECREMENT 10 ///< The size decrement used when shrinking the list
#define TRUE 1 ///< Boolean value for true
#define FALSE 0 ///< Boolean value for false

typedef int ElemType; ///< Type definition for elements stored in the sequential list

/**
 * @brief The structure representing a sequential list.
 *
 * @elem Pointer to the dynamic array holding the list elements.
 * @length Current number of elements in the list.
 * @listsize Current allocated size of the list.
 */
typedef struct {
    ElemType* elem; ///< Pointer to the element array
    int length; ///< Current number of elements in the list
    int listsize; ///< Current allocated capacity of the list
} SqList;

/**
 * @brief Initializes a new sequential list.
 *
 * Allocates memory for the list and sets initial values for its attributes.
 *
 * @param L Pointer to the list to be initialized.
 */
void InitList(SqList* L);

/**
 * @brief Checks if the sequential list is empty.
 *
 * @param L Pointer to the list.
 * @return TRUE if the list is empty, otherwise FALSE.
 */
int JudgmentList(SqList* L);

/**
 * @brief Returns the current length of the sequential list.
 *
 * @param L Pointer to the list.
 * @return The number of elements in the list.
 */
int LengthList(SqList* L);

/**
 * @brief Returns the element at the specified position in the list.
 *
 * @param L Pointer to the list.
 * @param i The position (1-based index) of the element to retrieve.
 * @return The element at the specified position.
 */
ElemType OrderNum(SqList* L, int i);

/**
 * @brief Expands the size of the list by a defined increment.
 *
 * Allocates additional memory to the list to allow for more elements.
 *
 * @param L Pointer to the list.
 */
void ExpandList(SqList* L);

/**
 * @brief Shrinks the size of the list by a defined decrement if necessary.
 *
 * Releases excess memory if the list's capacity is much larger than its length.
 *
 * @param L Pointer to the list.
 */
void ShrinkList(SqList* L);

/**
 * @brief Inserts an element at the specified position in the list.
 *
 * Shifts subsequent elements to the right to make space for the new element.
 *
 * @param L Pointer to the list.
 * @param i The position (1-based index) at which to insert the element.
 * @param e The element to be inserted.
 */
void ListInsert(SqList* L, int i, ElemType e);

/**
 * @brief Deletes the element at the specified position in the list.
 *
 * Shifts subsequent elements to the left to fill the gap left by the deleted element.
 *
 * @param L Pointer to the list.
 * @param i The position (1-based index) of the element to delete.
 */
void ListDelete(SqList* L, int i);

/**
 * @brief Returns the predecessor of the specified element in the list.
 *
 * @param L Pointer to the list.
 * @param e The element whose predecessor is to be found.
 * @return The predecessor element, or -1 if none exists.
 */
ElemType PriorElem(SqList* L, ElemType e);

/**
 * @brief Returns the successor of the specified element in the list.
 *
 * @param L Pointer to the list.
 * @param e The element whose successor is to be found.
 * @return The successor element, or -1 if none exists.
 */
ElemType GetNextElem(SqList* L, ElemType e);

/**
 * @brief Locates an element in the list and returns its position.
 *
 * @param L Pointer to the list.
 * @param e The element to locate.
 * @return The position (1-based index) of the element, or -1 if not found.
 */
int LocateElem(SqList* L, ElemType e);

/**
 * @brief Clears all elements from the list.
 *
 * Sets the length of the list to 0 without releasing allocated memory.
 *
 * @param L Pointer to the list.
 */
void ClearList(SqList* L);

/**
 * @brief Destroys the list and releases all allocated memory.
 *
 * Frees the memory allocated for the list and resets its attributes.
 *
 * @param L Pointer to the list to be destroyed.
 */
void DestroyList(SqList* L);

/**
 * @brief Swaps the values of two elements.
 *
 * @param a Pointer to the first element.
 * @param b Pointer to the second element.
 */
void Swap(ElemType* a, ElemType* b);

/**
 * @brief Reorders the list such that odd numbers precede even numbers.
 *
 * Partitions the list into two parts, with all odd elements appearing before all even elements.
 *
 * @param L Pointer to the list.
 */
void ChangeNums(SqList* L);

#endif