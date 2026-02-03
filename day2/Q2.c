#include <stdio.h>

int main() {
    int n, pos;
    int arr[100]; // Assuming a max size, or use dynamic allocation

    // 1. Read the size of the array
    if (scanf("%d", &n) != 1) return 1;

    // 2. Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Read the position to delete
    if (scanf("%d", &pos) != 1) return 1;

    // 4. Validate position
    if (pos < 1 || pos > n) {
        printf("Invalid position!\n");
        return 1;
    }

    // 5. Delete element and shift left
    // Start loop from the index to be deleted (pos - 1)
    // Shift elements: arr[i] takes the value of arr[i + 1]
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // 6. Decrease the size of the array
    n--;

    // 7. Print the updated array
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        // Print space only if it's not the last element
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}