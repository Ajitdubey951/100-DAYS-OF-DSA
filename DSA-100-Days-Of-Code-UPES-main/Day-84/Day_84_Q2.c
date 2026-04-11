#include <stdio.h>

int findPeakElement(int *nums, int numsSize)
{
    int low = 0;
    int high = numsSize - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] < nums[mid + 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return low;
}

int main()
{
    int nums1[] = {1, 2, 3, 1};
    printf("Peak Index: %d\n", findPeakElement(nums1, 4));

    int nums2[] = {1, 2, 1, 3, 5, 6, 4};
    printf("Peak Index: %d\n", findPeakElement(nums2, 7));

    return 0;
}