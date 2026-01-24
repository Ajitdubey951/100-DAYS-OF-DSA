#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    scanf("%s", s);
    int n = strlen(s);
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (s[i] != s[j])
        {
            printf("No\n");
            return 0;
        }
        i++;
        j--;
    }
    printf("Yes\n");
    return 0;
}