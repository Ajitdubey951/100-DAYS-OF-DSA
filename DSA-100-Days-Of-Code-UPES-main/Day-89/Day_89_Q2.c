#include <stdio.h>

int canShip(int *weights, int weightsSize, int days, int capacity)
{
    int daysNeeded = 1;
    int currentLoad = 0;

    for (int i = 0; i < weightsSize; i++)
    {
        if (currentLoad + weights[i] <= capacity)
        {
            currentLoad += weights[i];
        }
        else
        {
            daysNeeded++;
            currentLoad = weights[i];
            if (daysNeeded > days)
                return 0;
        }
    }
    return 1;
}

int shipWithinDays(int *weights, int weightsSize, int days)
{
    int low = 0, high = 0;

    for (int i = 0; i < weightsSize; i++)
    {
        if (weights[i] > low)
            low = weights[i];
        high += weights[i];
    }

    int result = high;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canShip(weights, weightsSize, days, mid))
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
    int weights[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    int d = 5;

    printf("Minimum ship capacity: %d\n", shipWithinDays(weights, n, d));
    return 0;
}