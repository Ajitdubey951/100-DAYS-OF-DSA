#include <stdio.h>
#include <stdlib.h>

void combine(int *collection, int left, int middle, int right)
{
    int i, j, k;
    int size_left = middle - left + 1;
    int size_right = right - middle;

    int *L = (int *)malloc(size_left * sizeof(int));
    int *R = (int *)malloc(size_right * sizeof(int));

    for (i = 0; i < size_left; i++)
        L[i] = collection[left + i];
    for (j = 0; j < size_right; j++)
        R[j] = collection[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < size_left && j < size_right)
    {
        if (L[i] <= R[j])
        {
            collection[k] = L[i];
            i++;
        }
        else
        {
            collection[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < size_left)
    {
        collection[k] = L[i];
        i++;
        k++;
    }

    while (j < size_right)
    {
        collection[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void merge_sort(int *collection, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        merge_sort(collection, left, middle);
        merge_sort(collection, middle + 1, right);

        combine(collection, left, middle, right);
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

    merge_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}