int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    int freq[1001] = {0};
    for (int i = 0; i < nums1Size; i++)
    {
        freq[nums1[i]]++;
    }
    int maxSize = (nums1Size < nums2Size) ? nums1Size : nums2Size;
    int *result = (int *)malloc(maxSize * sizeof(int));

    int k = 0;
    for (int i = 0; i < nums2Size; i++)
    {
        if (freq[nums2[i]] > 0)
        {
            result[k] = nums2[i];
            k++;
            freq[nums2[i]]--;
        }
    }
    *returnSize = k;

    return result;
}