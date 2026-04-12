#include <stdio.h>

int findMin(int *nums, int numsSize)
{
    int left = 0;
    int right = numsSize - 1;

    if (nums[left] <= nums[right])
    {
        return nums[left];
    }

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    return nums[left];
}

int main()
{
    int nums1[] = {3, 4, 5, 1, 2};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Minimum: %d\n", findMin(nums1, size1));

    int nums2[] = {4, 5, 6, 7, 0, 1, 2};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Minimum: %d\n", findMin(nums2, size2));

    return 0;
}