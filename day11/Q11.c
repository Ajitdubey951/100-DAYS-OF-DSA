#include <stdio.h>

int main() {
    int m, n;
    
    // 1. Declare matrices with a safe maximum size (e.g., 100x100)
    int first[100][100], second[100][100], sum[100][100];
    
    // 2. Read the dimensions (rows and columns)
    scanf("%d %d", &m, &n);
    
    // 3. Read the First Matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &first[i][j]);
        }
    }
    
    // 4. Read the Second Matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &second[i][j]);
        }
    }
    
    // 5. Perform Addition and Print result
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Add corresponding elements
            sum[i][j] = first[i][j] + second[i][j];
            
            // Print the sum followed by a space
            printf("%d ", sum[i][j]);
        }
        // Print a newline after finishing each row
        printf("\n");
    }
    
    return 0;
}