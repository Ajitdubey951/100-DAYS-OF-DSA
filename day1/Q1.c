#include <stdio.h>

int main() {
    int n;

    // 1. Read the size of the array
    if (scanf("%d", &n) != 1) return 1;

    // Declare array with size n + 1 to accommodate the new element
    // (Using Variable Length Array for flexibility)
    int arr[n + 1];

    // 2. Read the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int pos, x;
    // 3. Read position and the new element
    scanf("%d", &pos);
    scanf("%d", &x);

    // Validate position (Optional but recommended)
    // Valid positions are 1 to n+1 (inserting after the last element)
    if (pos < 1 || pos > n + 1) {
        printf("Invalid position\n");
        return 1;
    }

    // 4. Shift elements to the right
    // We start from the new last index (n) and move backwards
    // down to the insertion index.
    // Note: 'pos' is 1-based, so the C index is 'pos - 1'
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // 5. Insert the new element
    arr[pos - 1] = x;

    // 6. Print the updated array (size is now n + 1)
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
