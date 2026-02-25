#include <stdio.h>

int main() {
    int m, n;
    
    // Read the dimensions of the matrix
    if (scanf("%d %d", &m, &n) != 2) {
        return 1;
    }

    int val;
    int sum = 0;

    // Read the matrix elements and calculate the sum on the fly
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &val);
            
            // Add to sum if it's on the primary diagonal
            if (i == j) {
                sum += val;
            }
        }
    }

    // Print the final sum
    printf("%d\n", sum);

    return 0;
}
