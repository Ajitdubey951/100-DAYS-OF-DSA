#include <stdio.h>
#include <string.h>

char firstRepeatedChar(char *s)
{
    int seen[26] = {0};

    for (int i = 0; s[i] != '\0'; i++)
    {
        int index = s[i] - 'a';

        if (seen[index] == 1)
        {
            return s[i];
        }

        seen[index] = 1;
    }

    return '\0';
}

int main()
{
    char s[] = "abccba";
    char result = firstRepeatedChar(s);

    if (result != '\0')
    {
        printf("%c\n", result);
    }

    return 0;
}