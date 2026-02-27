#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Comparison function used by qsort to sort the array in ascending order
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void findMinSumPair(int arr[], int n) {
    // Edge case: If the array has less than 2 elements
    if (n < 2) {
        printf("Invalid input. Array must have at least 2 elements.\n");
        return;
    }

    // Step 1: Sort the array
    qsort(arr, n, sizeof(int), compare);

    // Step 2: Initialize two pointers
    int left = 0;
    int right = n - 1;

    // Variables to keep track of the closest sum and the corresponding pair
    int min_sum = INT_MAX;
    int min_left = left;
    int min_right = right;

    // Step 3: Traverse the array from both ends
    while (left < right) {
        int current_sum = arr[left] + arr[right];

        // If we found a sum closer to zero, update the minimums
        if (abs(current_sum) < abs(min_sum)) {
            min_sum = current_sum;
            min_left = left;
            min_right = right;
        }

        // If the sum is exactly zero, it's the absolute closest we can get
        if (min_sum == 0) {
            break; 
        }

        // Step 4: Move the pointers based on the current sum
        if (current_sum < 0) {
            // We need a larger sum to get closer to zero, so move the left pointer right
            left++;
        } else {
            // We need a smaller sum to get closer to zero, so move the right pointer left
            right--;
        }
    }

    // Print the result matching the example format
    printf("%d %d\n", arr[min_left], arr[min_right]);
}

int main() {
    int n;
    
    // Read the number of elements
    if (scanf("%d", &n) != 1) {
        return 1;
    }

    // Allocate memory for the array
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find and print the pair
    findMinSumPair(arr, n);

    // Free the allocated memory
    free(arr);

    return 0;
}