#include <stdio.h>
#include <stdlib.h> // Needed for malloc and free

int main() {
    int n;
    
    // Read the size of the array
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }
    
    // Dynamically allocate memory to prevent Variable Length Array (VLA) compiler errors
    int *arr = (int *)malloc(n * sizeof(int));
    int *visited = (int *)malloc(n * sizeof(int));
    
    // Check if memory allocation failed
    if (arr == NULL || visited == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Read the array elements and initialize the visited array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0; 
    }
    
    // Count frequencies (preserves original order of appearance)
    for (int i = 0; i < n; i++) {
        if (visited[i] == 1) {
            continue;
        }
        
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1; 
            }
        }
        
        printf("%d:%d ", arr[i], count);
    }
    
    // Free the allocated memory to prevent memory leaks
    free(arr);
    free(visited);
    
    printf("\n");
    return 0;
}