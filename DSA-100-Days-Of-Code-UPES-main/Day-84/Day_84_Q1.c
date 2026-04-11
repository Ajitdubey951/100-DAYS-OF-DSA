#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *storage, int limit)
{
    int i, idx, current_item;

    for (i = 1; i < limit; i++)
    {
        current_item = storage[i];
        idx = i - 1;

        while (idx >= 0 && storage[idx] > current_item)
        {
            storage[idx + 1] = storage[idx];
            idx = idx - 1;
        }
        storage[idx + 1] = current_item;
    }
}

void print_collection(int *storage, int limit)
{
    for (int i = 0; i < limit; i++)
    {
        printf("%d ", storage[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1)
        return 0;

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    insertion_sort(arr, n);

    printf("Sorted array: ");
    print_collection(arr, n);

    free(arr);
    return 0;
}