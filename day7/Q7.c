#include <stdio.h>

int fib(int n) {
    // Base Case 1: fib(0) = 0
    if (n == 0) {
        return 0;
    }
    // Base Case 2: fib(1) = 1
    else if (n == 1) { 
        return 1;
    }
    // Recursive Step
    else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    int n;
    
    // Read input
    if (scanf("%d", &n) != 1) {
        return 1; // Exit if input is invalid
    }

    // Print result
    printf("%d", fib(n));

    return 0;
}