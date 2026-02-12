#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    
    // 1. Read the input
    scanf("%s", str);
    
    // 2. Initialize two pointers
    int left = 0;                  // Points to the start
    int right = strlen(str) - 1;   // Points to the end
    
    // 3. Loop until the pointers meet in the middle
    while (left < right) {
        
        // Compare characters at both pointers
        if (str[left] != str[right]) {
            // If they don't match, it's not a palindrome
            printf("NO\n");
            return 0; // Exit the program immediately
        }
        
        // Move pointers inward
        left++;
        right--;
    }
    
    // 4. If the loop finishes without returning, it IS a palindrome
    printf("YES\n");
    
    return 0;
}