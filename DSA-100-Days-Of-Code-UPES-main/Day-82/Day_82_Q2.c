#include <stdio.h>

int searchInsert(int *nums, int numsSize, int target)
{
    int start = 0;
    int end = numsSize - 1;
    int position = numsSize;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (nums[mid] >= target)
        {
            position = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return position;
}

int main()
{
    int nums[] = {1, 3, 5, 6};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = 5;

    int result = searchInsert(nums, n, target);
    printf("Index: %d\n", result);

    target = 2;
    result = searchInsert(nums, n, target);
    printf("Index: %d\n", result);

    return 0;
}