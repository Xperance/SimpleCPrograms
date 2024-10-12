#ifndef XPERANCE_BUBBLESORT
#define XPERANCE_BUBBLESORT

/**
 * @brief Swaps two elements in memory, each with a width of 'wide' bytes.
 *
 * @param a Pointer to the first element to be swapped.
 * @param b Pointer to the second element to be swapped.
 * @param wide The number of bytes each element occupies.
 */
void swap(char* a, char* b, int wide);

/**
 * @brief Sorts an array using the Bubble Sort algorithm.
 *
 * @param input Pointer to the array to be sorted.
 * @param sz The number of elements in the array.
 * @param wide The size of each element in the array (in bytes).
 * @param cmp A function pointer used to compare two elements.            
 */
void BubbleSort(void* input, int sz, int wide, int (*cmp)(void* a, void* b));

#endif