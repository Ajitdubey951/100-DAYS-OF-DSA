#include <stdio.h>

int main()
{
    int p, q;

    if (scanf("%d", &p) != 1)
    {
        return 1;
    }
    int log1[p];
    for (int i = 0; i < p; i++)
    {
        scanf("%d", &log1[i]);
    }

    if (scanf("%d", &q) != 1)
    {
        return 1;
    }
    int log2[q];
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &log2[i]);
    }

    int i = 0, j = 0;

    while (i < p && j < q)
    {
        if (log1[i] < log2[j])
        {
            printf("%d ", log1[i++]);
        }
        else
        {
            printf("%d ", log2[j++]);
        }
    }

    while (i < p)
    {
        printf("%d ", log1[i++]);
    }

    while (j < q)
    {
        printf("%d ", log2[j++]);
    }

    printf("\n");
    return 0;
}