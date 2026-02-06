#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    
    // 1. Read the size of the array
    if (scanf("%d", &n) != 1) return 0;
    
    // Edge case: Empty array
    if (n == 0) return 0;

    // 2. Allocate memory for the array
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) return 1; // Check for allocation failure

    // 3. Read the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 4. Two Pointer Logic (In-place removal)
    // i tracks the position of the last unique element found
    int i = 0;
    
    for (int j = 1; j < n; j++) {
        // If current element (j) is different from the last unique one (i)
        if (arr[j] != arr[i]) {
            i++;            // Move unique pointer forward
            arr[i] = arr[j]; // Overwrite with the new unique value
        }
    }

    // 5. Print unique elements
    // The unique elements are stored from index 0 to i
    for (int k = 0; k <= i; k++) {
        printf("%d%s", arr[k], (k == i) ? "" : " ");
    }
    printf("\n");

    // 6. Clean up
    free(arr);

    return 0;
}