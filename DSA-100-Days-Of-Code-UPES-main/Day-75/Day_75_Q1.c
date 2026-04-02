#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int sum;
    int index;
} Entry;

int maxLen(int arr[], int n)
{
    int max_len = 0;
    int curr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum = 0;
        for (int j = i; j < n; j++)
        {
            curr_sum += arr[j];
            if (curr_sum == 0)
            {
                int current_len = j - i + 1;
                if (current_len > max_len)
                {
                    max_len = current_len;
                }
            }
        }
    }
    return max_len;
}

int main()
{
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", maxLen(arr, n));
    return 0;
}