#include <stdio.h>

// Function to calculate power recursively
// Using long long to prevent overflow for larger results
long long power(int a, int b) {
    // Base Case: Any number to the power of 0 is 1
    if (b == 0) {
        return 1;
    }
    
    // Recursive Step: a * (a raised to b-1)
    return a * power(a, b - 1);
}

int main() {
    int a, b;
    
    // Reading two space-separated integers
    // printf("Enter a and b: "); // Uncomment prompt if needed for interactive use
    if (scanf("%d %d", &a, &b) == 2) {
        // Calculating and printing result
        printf("%lld\n", power(a, b));
    }
    
    return 0;
}