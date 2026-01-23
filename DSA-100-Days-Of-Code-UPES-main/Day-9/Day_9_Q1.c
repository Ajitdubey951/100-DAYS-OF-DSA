#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        char s[100];
        scanf("%s", s);
        int n = strlen(s);
        for (int i = n - 1; i >= 0; i--)
        {
            printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}