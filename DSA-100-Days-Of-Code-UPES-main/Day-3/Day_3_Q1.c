#include <stdio.h>

int main()
{
    int n, k;
    int found = 0;
    int comparisons = 0;

    if (scanf("%d", &n) != 1)
    {
        return 1;
    }

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    for (int i = 0; i < n; i++)
    {
        comparisons++;

        if (arr[i] == k)
        {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Not Found\n");
    }

    printf("Comparisons = %d\n", comparisons);

    return 0;
}