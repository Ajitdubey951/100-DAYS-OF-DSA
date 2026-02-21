#include <stdlib.h>

typedef struct
{
    int *heap;
    int size;
    int k;
} KthLargest;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int *heap, int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;
        if (heap[index] < heap[parent])
        {
            swap(&heap[index], &heap[parent]);
            index = parent;
        }
        else
        {
            break;
        }
    }
}

void heapifyDown(int *heap, int size, int index)
{
    while (1)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && heap[left] < heap[smallest])
        {
            smallest = left;
        }
        if (right < size && heap[right] < heap[smallest])
        {
            smallest = right;
        }

        if (smallest != index)
        {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        }
        else
        {
            break;
        }
    }
}

int kthLargestAdd(KthLargest *obj, int val)
{
    if (obj->size < obj->k)
    {
        obj->heap[obj->size] = val;
        heapifyUp(obj->heap, obj->size);
        obj->size++;
    }
    else if (val > obj->heap[0])
    {
        obj->heap[0] = val;
        heapifyDown(obj->heap, obj->k, 0);
    }

    return obj->heap[0];
}

KthLargest *kthLargestCreate(int k, int *nums, int numsSize)
{
    KthLargest *obj = (KthLargest *)malloc(sizeof(KthLargest));
    obj->k = k;
    obj->size = 0;
    obj->heap = (int *)malloc(sizeof(int) * k);

    for (int i = 0; i < numsSize; i++)
    {
        kthLargestAdd(obj, nums[i]);
    }

    return obj;
}

void kthLargestFree(KthLargest *obj)
{
    if (obj)
    {
        free(obj->heap);
        free(obj);
    }
}