#include <stdio.h>

int main()
{
    int n;

    if (scanf("%d", &n) != 1)
    {
        return 1;
    }
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i == n - 1)
        {
            printf("");
        }
        else
        {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}