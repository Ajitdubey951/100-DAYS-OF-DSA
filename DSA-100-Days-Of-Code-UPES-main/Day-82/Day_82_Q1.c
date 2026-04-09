#include <stdio.h>
#include <stdlib.h>

int find_lower_bound(int *arr, int size, int target)
{
    int start = 0, end = size - 1;
    int answer = size;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] >= target)
        {
            answer = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return answer;
}

int find_upper_bound(int *arr, int size, int target)
{
    int start = 0, end = size - 1;
    int answer = size;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] > target)
        {
            answer = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return answer;
}

int main()
{
    int n, x;
    if (scanf("%d", &n) != 1)
        return 0;

    int *collection = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &collection[i]);
    }
    scanf("%d", &x);

    int lb = find_lower_bound(collection, n, x);
    int ub = find_upper_bound(collection, n, x);

    printf("%d %d\n", lb, ub);

    free(collection);
    return 0;
}