#include <stdlib.h>

int *maxSlidingWindow(int *nums, int numsSize, int k, int *returnSize)
{

    if (numsSize == 0 || k == 0)
    {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = numsSize - k + 1;
    int *result = (int *)malloc(sizeof(int) * (*returnSize));

    int *deque = (int *)malloc(sizeof(int) * numsSize);
    int front = 0;
    int rear = -1;

    for (int i = 0; i < numsSize; i++)
    {

        if (front <= rear && deque[front] < i - k + 1)
        {
            front++;
        }

        while (front <= rear && nums[deque[rear]] <= nums[i])
        {
            rear--;
        }

        deque[++rear] = i;

        if (i >= k - 1)
        {
            result[i - k + 1] = nums[deque[front]];
        }
    }

    free(deque);

    return result;
}