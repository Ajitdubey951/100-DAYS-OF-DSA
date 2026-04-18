#include <stdio.h>

void sortColors(int *nums, int numsSize)
{
    int i = 0, j = 0;

    while (i < numsSize)
    {
        if (nums[i] == 0)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j++;
        }
        i++;
    }

    i = j;
    while (i < numsSize)
    {
        if (nums[i] == 1)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j++;
        }
        i++;
    }
}

int main()
{
    int arr[] = {2, 0, 2, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortColors(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}