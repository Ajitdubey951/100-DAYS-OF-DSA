#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *collection, int limit)
{
    int i, j, min_idx, temp;

    for (i = 0; i < limit - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < limit; j++)
        {
            if (collection[j] < collection[min_idx])
            {
                min_idx = j;
            }
        }

        if (min_idx != i)
        {
            temp = collection[min_idx];
            collection[min_idx] = collection[i];
            collection[i] = temp;
        }
    }
}

int main()
{
    int n;
    if (scanf("%d", &n) != 1)
        return 0;

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    selection_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}