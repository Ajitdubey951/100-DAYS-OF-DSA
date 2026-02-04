int maxSubarraySumCircular(int *nums, int numsSize)
{
    int total_sum = 0;

    int current_max = 0;
    int max_sum = nums[0];

    int current_min = 0;
    int min_sum = nums[0];

    for (int i = 0; i < numsSize; i++)
    {
        total_sum += nums[i];
        if (current_max < 0)
        {
            current_max = nums[i];
        }
        else
        {
            current_max += nums[i];
        }
        if (current_max > max_sum)
        {
            max_sum = current_max;
        }
        if (current_min > 0)
        {
            current_min = nums[i];
        }
        else
        {
            current_min += nums[i];
        }
        if (current_min < min_sum)
        {
            min_sum = current_min;
        }
    }
    if (max_sum < 0)
    {
        return max_sum;
    }
    int circular_sum = total_sum - min_sum;
    return (max_sum > circular_sum) ? max_sum : circular_sum;
}