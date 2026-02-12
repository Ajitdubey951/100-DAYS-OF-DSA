#include <stdio.h>
#include <string.h>

int main() {
    // 1. Declare a variable to store the text. 
    // We use size 1000 to be safe for typical input sizes.
    char str[1000];

    // 2. Read the input string
    // %s reads a string until it hits a space or newline
    scanf("%s", str);

    // 3. Calculate the length of the string
    int length = strlen(str);

    // 4. Loop backwards from the last character to the first
    // length - 1 is the index of the last character
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    
    // Optional: Print a newline at the end for clean output
    printf("\n");

    return 0;
}