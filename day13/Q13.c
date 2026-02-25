#include <stdio.h>

int main() {
    int r, c;
    
    // Read the dimensions
    if (scanf("%d %d", &r, &c) != 2) {
        return 1;
    }

    int matrix[r][c];
    
    // Read the matrix elements
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Initialize boundary pointers
    int top = 0;
    int bottom = r - 1;
    int left = 0;
    int right = c - 1;
    
    int is_first_element = 1; // To manage space separation properly

    while (top <= bottom && left <= right) {
        
        // 1. Traverse from left to right along the top row
        for (int i = left; i <= right; i++) {
            if (!is_first_element) printf(" ");
            printf("%d", matrix[top][i]);
            is_first_element = 0;
        }
        top++; // Shrink the top boundary

        // 2. Traverse from top to bottom along the right column
        for (int i = top; i <= bottom; i++) {
            if (!is_first_element) printf(" ");
            printf("%d", matrix[i][right]);
            is_first_element = 0;
        }
        right--; // Shrink the right boundary

        // 3. Traverse from right to left along the bottom row
        // Condition ensures we don't print the same row twice for a single row matrix
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                if (!is_first_element) printf(" ");
                printf("%d", matrix[bottom][i]);
                is_first_element = 0;
            }
            bottom--; // Shrink the bottom boundary
        }

        // 4. Traverse from bottom to top along the left column
        // Condition ensures we don't print the same column twice for a single column matrix
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                if (!is_first_element) printf(" ");
                printf("%d", matrix[i][left]);
                is_first_element = 0;
            }
            left++; // Shrink the left boundary
        }
    }
    
    printf("\n");
    return 0;
}