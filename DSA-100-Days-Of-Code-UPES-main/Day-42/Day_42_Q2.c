#include <stdio.h>
#include <stdlib.h>

#define MAX_CALLS 50000

typedef struct
{
    int *maxHeap;
    int maxHeapSize;
    int *minHeap;
    int minHeapSize;
} MedianFinder;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void pushMaxHeap(MedianFinder *obj, int val)
{
    int i = obj->maxHeapSize++;
    obj->maxHeap[i] = val;
    while (i != 0 && obj->maxHeap[i] > obj->maxHeap[(i - 1) / 2])
    {
        swap(&obj->maxHeap[i], &obj->maxHeap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int popMaxHeap(MedianFinder *obj)
{
    int root = obj->maxHeap[0];
    obj->maxHeap[0] = obj->maxHeap[--(obj->maxHeapSize)];
    int i = 0;
    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < obj->maxHeapSize && obj->maxHeap[left] > obj->maxHeap[largest])
            largest = left;
        if (right < obj->maxHeapSize && obj->maxHeap[right] > obj->maxHeap[largest])
            largest = right;

        if (largest == i)
            break;
        swap(&obj->maxHeap[i], &obj->maxHeap[largest]);
        i = largest;
    }
    return root;
}

void pushMinHeap(MedianFinder *obj, int val)
{
    int i = obj->minHeapSize++;
    obj->minHeap[i] = val;
    while (i != 0 && obj->minHeap[i] < obj->minHeap[(i - 1) / 2])
    {
        swap(&obj->minHeap[i], &obj->minHeap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int popMinHeap(MedianFinder *obj)
{
    int root = obj->minHeap[0];
    obj->minHeap[0] = obj->minHeap[--(obj->minHeapSize)];
    int i = 0;
    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < obj->minHeapSize && obj->minHeap[left] < obj->minHeap[smallest])
            smallest = left;
        if (right < obj->minHeapSize && obj->minHeap[right] < obj->minHeap[smallest])
            smallest = right;

        if (smallest == i)
            break;
        swap(&obj->minHeap[i], &obj->minHeap[smallest]);
        i = smallest;
    }
    return root;
}

MedianFinder *medianFinderCreate()
{
    MedianFinder *obj = (MedianFinder *)malloc(sizeof(MedianFinder));
    obj->maxHeap = (int *)malloc(sizeof(int) * MAX_CALLS);
    obj->minHeap = (int *)malloc(sizeof(int) * MAX_CALLS);
    obj->maxHeapSize = 0;
    obj->minHeapSize = 0;
    return obj;
}

void medianFinderAddNum(MedianFinder *obj, int num)
{
    pushMaxHeap(obj, num);

    pushMinHeap(obj, popMaxHeap(obj));

    if (obj->minHeapSize > obj->maxHeapSize)
    {
        pushMaxHeap(obj, popMinHeap(obj));
    }
}

double medianFinderFindMedian(MedianFinder *obj)
{
    if (obj->maxHeapSize > obj->minHeapSize)
    {
        return (double)obj->maxHeap[0];
    }
    else
    {
        return ((double)obj->maxHeap[0] + (double)obj->minHeap[0]) / 2.0;
    }
}

void medianFinderFree(MedianFinder *obj)
{
    free(obj->maxHeap);
    free(obj->minHeap);
    free(obj);
}