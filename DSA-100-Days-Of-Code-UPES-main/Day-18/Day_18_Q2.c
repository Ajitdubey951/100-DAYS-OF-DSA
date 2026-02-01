int *productExceptSelf(int *nums, int numsSize, int *returnSize)
{
    int *ans = (int *)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++)
    {
        int product = 1;
        for (int j = 0; j < numsSize; j++)
        {
            if (i != j)
            {
                product *= nums[j];
            }
        }
        ans[i] = product;
    }
    return ans;
}