#include <stdio.h>

int main() {
    int n, i;
    int max, min;
    int arr[10000]; /* Using a large fixed-size array to avoid memory errors */
    
    /* Read the size of the array */
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }
    
    /* Read the array elements */
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    /* Initialize max and min with the first element */
    max = arr[0];
    min = arr[0];
    
    /* Loop through the rest to find max and min */
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    
    /* Print the results exactly as requested */
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
    
    return 0;
}