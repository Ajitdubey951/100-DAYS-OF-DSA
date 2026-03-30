#include <stdio.h>
#include <string.h>

char nonRepeatingCharacter(char *s)
{
    int freq[26] = {0};
    int n = strlen(s);

    for (int i = 0; i < n; i++)
    {
        freq[s[i] - 'a']++;
    }

    for (int i = 0; i < n; i++)
    {
        if (freq[s[i] - 'a'] == 1)
        {
            return s[i];
        }
    }

    return '$';
}

int main()
{
    char s[100001];
    if (scanf("%s", s) == 1)
    {
        printf("%c\n", nonRepeatingCharacter(s));
    }
    return 0;
}