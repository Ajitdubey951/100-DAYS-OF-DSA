#include <stdio.h>

int main()
{
    int n, pos;
    if (scanf("%d", &n) != 1)
    {
        return 1;
    }
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &pos);

    int idx = pos - 1;
    for (int i = idx; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (i == n - 2)
        {
        }
        else
        {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}