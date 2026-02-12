#include <stdio.h>

int main() {
    int m, n;
    int matrix[100][100];
    int isSymmetric = 1; // Assume it is symmetric initially (1 = true, 0 = false)

    // 1. Read dimensions
    if (scanf("%d %d", &m, &n) != 2) return 1;

    // 2. Read the matrix elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 3. First Check: Is it a square matrix?
    if (m != n) {
        printf("Not a Symmetric Matrix\n");
        return 0;
    }

    // 4. Second Check: Compare matrix[i][j] with matrix[j][i]
    // We only need to check the upper triangle (j > i) to avoid double checking
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0; // Found a mismatch
                break;
            }
        }
        if (isSymmetric == 0) break; // Break outer loop if mismatch found
    }

    // 5. Print the result
    if (isSymmetric) {
        printf("Symmetric Matrix\n");
    } else {
        printf("Not a Symmetric Matrix\n");
    }

    return 0;
}