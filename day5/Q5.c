#include <stdio.h>
#include <stdlib.h>

int main() {
    int p, q;

    // 1. Input for Server Log 1
    if (scanf("%d", &p) != 1) return 1;
    int *log1 = (int*)malloc(p * sizeof(int));
    for (int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }

    // 2. Input for Server Log 2
    if (scanf("%d", &q) != 1) return 1;
    int *log2 = (int*)malloc(q * sizeof(int));
    for (int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }

    // 3. Two-Pointer Merge Logic
    int i = 0, j = 0;
    
    // Compare and print the smaller value until one list is exhausted
    while (i < p && j < q) {
        if (log1[i] < log2[j]) {
            printf("%d ", log1[i]);
            i++;
        } else {
            printf("%d ", log2[j]);
            j++;
        }
    }

    // 4. Print remaining elements (if any)
    while (i < p) {
        printf("%d ", log1[i]);
        i++;
    }
    while (j < q) {
        printf("%d ", log2[j]);
        j++;
    }

    // Cleanup
    free(log1);
    free(log2);

    return 0;
}