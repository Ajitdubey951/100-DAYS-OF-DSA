#include <stdio.h>

int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    int freq[n];
    for (int i = 0; i < n; i++)
    {
        freq[i] = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                freq[i]++;
                for (int k = j; k < n - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                n--;
                j--;
            }
        }
    }
    printf("Frequency of each distinct element:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d: %d\n", arr[i], freq[i]);
    }
    return 0;
}