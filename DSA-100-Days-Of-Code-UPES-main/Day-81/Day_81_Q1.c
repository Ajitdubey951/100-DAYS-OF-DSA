#include <stdio.h>

void bubble_sort(int *data, int size)
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (data[j] > data[j + 1])
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void print_array(int *data, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main()
{
    int collection[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(collection) / sizeof(collection[0]);

    printf("Original array: ");
    print_array(collection, n);

    bubble_sort(collection, n);

    printf("Sorted array: ");
    print_array(collection, n);

    return 0;
}