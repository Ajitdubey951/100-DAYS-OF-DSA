int missingNum(int *arr, int size)
{
    int n = size + 1;
    long expectedSum = (long)n * (n + 1) / 2;

    long actualSum = 0;
    for (int i = 0; i < size; i++)
    {
        actualSum += arr[i];
    }

    return (int)(expectedSum - actualSum);
}