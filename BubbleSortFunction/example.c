#include <stdio.h>
#include "BubbleSort.h"

/*
 * This is an example demonstrating how to use the BubbleSort function
 * to sort an array of integers. In this example, we create an array
 * containing 10 integers and use a custom comparison function to
 * sort the array. After sorting, the program will print the sorted
 * array.
 *
 * Predicted Output:
 * The sorted array should be:
 * 1 2 3 4 5 6 7 8 9 10
 */

 // Comparison function to compare two integers
int cmp(void* a, void* b) {
    int int_a = *(int*)a;
    int int_b = *(int*)b;
    return int_a - int_b; // Return the difference to determine sort order
}

int main() {
    // Sample array to be sorted
    int arr[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

    // Call the BubbleSort function to sort the array
    BubbleSort(arr, 10, sizeof(int), cmp);

    // Print the sorted array
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]); // Print each element of the sorted array
    }
    printf("\n"); // Print a newline at the end

    return 0; // Return success
}