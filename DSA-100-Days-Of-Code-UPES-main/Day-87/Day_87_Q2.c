#include <stdio.h>

long long get_hours_needed(int *piles, int pilesSize, int k)
{
    long long total_hours = 0;
    for (int i = 0; i < pilesSize; i++)
    {
        total_hours += (piles[i] + k - 1) / k;
    }
    return total_hours;
}

int minEatingSpeed(int *piles, int pilesSize, int h)
{
    int left = 1;
    int right = 0;

    for (int i = 0; i < pilesSize; i++)
    {
        if (piles[i] > right)
        {
            right = piles[i];
        }
    }

    int result = right;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (mid == 0)
        {
            left = 1;
            continue;
        }

        if (get_hours_needed(piles, pilesSize, mid) <= h)
        {
            result = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return result;
}

int main()
{
    int piles1[] = {3, 6, 7, 11};
    int h1 = 8;
    printf("Min speed: %d\n", minEatingSpeed(piles1, 4, h1));

    int piles2[] = {30, 11, 23, 4, 20};
    int h2 = 5;
    printf("Min speed: %d\n", minEatingSpeed(piles2, 5, h2));

    return 0;
}