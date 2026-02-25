#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *arr;
    int size;
    int capacity;
} MinHeap;

MinHeap *createMinHeap(int capacity)
{
    MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->arr = (int *)malloc(capacity * sizeof(int));
    return heap;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(MinHeap *heap, int val)
{
    if (heap->size == heap->capacity)
    {
        printf("Heap is full!\n");
        return;
    }

    int i = heap->size;
    heap->arr[i] = val;
    heap->size++;

    while (i != 0 && heap->arr[i] < heap->arr[(i - 1) / 2])
    {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMin(MinHeap *heap)
{
    if (heap->size <= 0)
    {
        printf("Heap Underflow!\n");
        return -1;
    }
    if (heap->size == 1)
    {
        heap->size--;
        return heap->arr[0];
    }

    int root = heap->arr[0];

    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    int i = 0;
    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < heap->size && heap->arr[left] < heap->arr[smallest])
        {
            smallest = left;
        }

        if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        {
            smallest = right;
        }

        if (smallest == i)
        {
            break;
        }

        swap(&heap->arr[i], &heap->arr[smallest]);
        i = smallest;
    }

    return root;
}

void printHeap(MinHeap *heap)
{
    printf("Heap Array: ");
    for (int i = 0; i < heap->size; i++)
    {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

int main()
{
    MinHeap *heap = createMinHeap(10);

    insert(heap, 30);
    insert(heap, 20);
    insert(heap, 15);
    insert(heap, 5);
    insert(heap, 10);

    printHeap(heap);

    printf("\nExtracted Min: %d\n", extractMin(heap));
    printHeap(heap);

    free(heap->arr);
    free(heap);

    return 0;
}