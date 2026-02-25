#include <stdio.h>

int main() {
    int n, val;
    
    // Read the dimension of the square matrix
    if (scanf("%d", &n) != 1) {
        return 1;
    }

    int is_identity = 1; // Flag, assume it is an identity matrix initially

    // Read and validate matrix elements on the fly
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &val);
            
            // Check main diagonal elements
            if (i == j && val != 1) {
                is_identity = 0;
            }
            // Check non-diagonal elements
            if (i != j && val != 0) {
                is_identity = 0;
            }
        }
    }

    // Print the result based on the flag
    if (is_identity) {
        printf("Identity Matrix\n");
    } else {
        printf("Not an Identity Matrix\n");
    }

    return 0;
}