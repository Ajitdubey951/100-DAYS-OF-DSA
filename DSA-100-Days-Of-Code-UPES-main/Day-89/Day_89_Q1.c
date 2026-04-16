#include <stdio.h>
#include <stdlib.h>

int canAllocate(int *pages, int n, int m, int maxPages)
{
    int studentsCount = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (currentSum + pages[i] <= maxPages)
        {
            currentSum += pages[i];
        }
        else
        {
            studentsCount++;
            currentSum = pages[i];
            if (studentsCount > m)
                return 0;
        }
    }
    return 1;
}

int findPages(int *pages, int n, int m)
{
    if (m > n)
    {
        return -1;
    }

    int low = 0, high = 0;
    for (int i = 0; i < n; i++)
    {
        if (pages[i] > low)
            low = pages[i];
        high += pages[i];
    }

    int result = high;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canAllocate(pages, n, m, mid))
        {
            result = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return result;
}

int main()
{
    int pages[] = {12, 34, 67, 90};
    int n = 4;
    int m = 2;

    int result = findPages(pages, n, m);
    printf("Minimum possible maximum pages: %d\n", result);

    return 0;
}