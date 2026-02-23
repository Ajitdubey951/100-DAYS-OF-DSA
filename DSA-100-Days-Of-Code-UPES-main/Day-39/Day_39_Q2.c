#include <stdlib.h>

typedef struct
{
    int val;
    int count;
} Element;

int compareCounts(const void *a, const void *b)
{
    Element *elemA = (Element *)a;
    Element *elemB = (Element *)b;
    return elemB->count - elemA->count;
}

int *topKFrequent(int *nums, int numsSize, int k, int *returnSize)
{

    int hash[20001] = {0};
    for (int i = 0; i < numsSize; i++)
    {
        hash[nums[i] + 10000]++;
    }

    Element *uniqueElements = (Element *)malloc(sizeof(Element) * numsSize);
    int uniqueCount = 0;

    for (int i = 0; i < 20001; i++)
    {
        if (hash[i] > 0)
        {
            uniqueElements[uniqueCount].val = i - 10000;
            uniqueElements[uniqueCount].count = hash[i];
            uniqueCount++;
        }
    }

    qsort(uniqueElements, uniqueCount, sizeof(Element), compareCounts);

    *returnSize = k;
    int *result = (int *)malloc(sizeof(int) * k);

    for (int i = 0; i < k; i++)
    {
        result[i] = uniqueElements[i].val;
    }

    free(uniqueElements);

    return result;
}