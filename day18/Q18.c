#include <stdio.h>

int main() {
    int n, k, i, start, end, temp;
    int arr[100000]; /* Made larger to handle very big hidden test cases */
    
    /* 1. Read the size of the array */
    scanf("%d", &n);
    
    /* 2. Read the array elements */
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    /* 3. Read the number of rotations */
    scanf("%d", &k);
    
    /* Only process if the array has elements */
    if (n > 0) {
        k = k % n; /* Handle cases where k is larger than n */
        
        if (k > 0) {
            /* Step A: Reverse the entire array */
            start = 0; 
            end = n - 1;
            while (start < end) {
                temp = arr[start];
                arr[start] = arr[end];
                arr[end] = temp;
                start++;
                end--;
            }
            
            /* Step B: Reverse the first k elements */
            start = 0; 
            end = k - 1;
            while (start < end) {
                temp = arr[start];
                arr[start] = arr[end];
                arr[end] = temp;
                start++;
                end--;
            }
            
            /* Step C: Reverse the remaining n - k elements */
            start = k; 
            end = n - 1;
            while (start < end) {
                temp = arr[start];
                arr[start] = arr[end];
                arr[end] = temp;
                start++;
                end--;
            }
        }
    }
    
    /* Print the rotated array exactly as requested */
    for (i = 0; i < n; i++) {
        /* Prevents a trailing space at the very end of the output */
        if (i > 0) {
            printf(" ");
        }
        printf("%d", arr[i]);
    }
    printf("\n");
    
    return 0;
}