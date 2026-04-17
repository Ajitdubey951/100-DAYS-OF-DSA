#include <stdio.h>

int canSplit(int *nums, int n, int k, int maxSum)
{
    int parts = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (currentSum + nums[i] > maxSum)
        {
            parts++;
            currentSum = nums[i];

            if (parts > k)
                return 0;
        }
        else
        {
            currentSum += nums[i];
        }
    }

    return 1;
}

int splitArray(int *nums, int numsSize, int k)
{
    int low = 0, high = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > low)
            low = nums[i];
        high += nums[i];
    }

    int ans = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canSplit(nums, numsSize, k, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int nums[] = {7, 2, 5, 10, 8};
    int n = sizeof(nums) / sizeof(nums[0]);
    int k = 2;

    int result = splitArray(nums, n, k);

    printf("Array: [7, 2, 5, 10, 8], k: %d\n", k);
    printf("The minimized largest sum is: %d\n", result);

    return 0;
}