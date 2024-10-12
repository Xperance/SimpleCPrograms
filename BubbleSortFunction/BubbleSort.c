#include "BubbleSort.h"

/**
 * @brief Swaps two elements in memory, each of size 'wide' bytes.
 *
 * This function takes two pointers, 'a' and 'b', and swaps the content of
 * the memory they point to, assuming that each element occupies 'wide' bytes.
 *
 * @param a Pointer to the first element to be swapped.
 * @param b Pointer to the second element to be swapped.
 * @param wide Size (in bytes) of each element.
 */
void swap(char* a, char* b, int wide) {
    char temp;
    for (int i = 0; i < wide; i++) {
        temp = *a;
        *a = *b;
        *b = temp;
        a++;
        b++;
    }
}

/**
 * @brief Performs a bubble sort on the input array.
 *
 * This function sorts an array of elements using the bubble sort algorithm.
 * It accepts a comparison function 'cmp' to compare two elements, and the
 * size of each element is specified by 'wide'. The array is sorted in place.
 *
 * @param input Pointer to the array to be sorted.
 * @param sz Number of elements in the array.
 * @param wide Size (in bytes) of each element in the array.
 * @param cmp Comparison function that compares two elements:
 *            - If the first element is greater than the second, returns positive.
 *            - If equal, returns 0.
 *            - If the second is greater, returns negative.
 */
void BubbleSort(void* input, int sz, int wide, int (*cmp)(void* a, void* b)) {
    for (int i = 0; i < sz - 1; i++) {
        for (int j = 0; j < sz - 1 - i; j++) {
            int result = cmp((char*)input + j * wide, (char*)input + (j + 1) * wide);
            if (result > 0) {
                swap((char*)input + j * wide, (char*)input + (j + 1) * wide, wide);
            }
        }
    }
}