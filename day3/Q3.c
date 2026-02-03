#include <stdio.h>

int main() {
    int n, k;
    int arr[100]; // Fixed size array (can use dynamic allocation for larger n)
    int comparisons = 0;
    int found = 0; // Flag to track if k is found

    // 1. Read array size
    if (scanf("%d", &n) != 1) return 1;

    // 2. Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Read the key to search
    if (scanf("%d", &k) != 1) return 1;

    // 4. Linear Search
    for (int i = 0; i < n; i++) {
        comparisons++; // Increment comparison count
        
        if (arr[i] == k) {
            printf("Found at index %d\n", i);
            found = 1; // Mark as found
            break;     // Stop searching once found
        }
    }

    // 5. Handle "Not Found" case
    if (!found) {
        printf("Not Found\n");
    }

    // 6. Print total comparisons
    printf("Comparisons = %d\n", comparisons);

    return 0;
}