#include <stdio.h>
#include <stdlib.h>

void reverseArray(int* arr, int n) {
    int left = 0;
    int right = n - 1;
    int temp;

    // Loop until the pointers meet
    while (left < right) {
        // Swap elements using a temporary variable
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        // Move pointers inward
        left++;
        right--;
    }
}

int main() {
    int n;
    
    // Read n (size of the array)
    if (scanf("%d", &n) != 1) return 0;

    // Dynamic memory allocation for the array
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        return 1; // Memory allocation failed
    }

    // Read the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform the reversal
    reverseArray(arr, n);

    // Print the reversed array
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        // Add a space after the number if it's not the last element
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    // Free the allocated memory
    free(arr);

    return 0;
}