#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CAPACITY 100

typedef struct
{
    int arr[MAX_CAPACITY];
    int size;
} PriorityQueue;

void initPQ(PriorityQueue *pq)
{
    pq->size = 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(PriorityQueue *pq, int value)
{
    if (pq->size == MAX_CAPACITY)
    {
        printf("Priority Queue is full!\n");
        return;
    }

    int currentIndex = pq->size;
    pq->arr[currentIndex] = value;
    pq->size++;

    int parentIndex = (currentIndex - 1) / 2;

    while (currentIndex > 0 && pq->arr[currentIndex] < pq->arr[parentIndex])
    {
        swap(&pq->arr[currentIndex], &pq->arr[parentIndex]);

        currentIndex = parentIndex;
        parentIndex = (currentIndex - 1) / 2;
    }
}

int extractMin(PriorityQueue *pq)
{
    if (pq->size <= 0)
    {
        printf("Priority Queue is empty!\n");
        return -1;
    }

    int minValue = pq->arr[0];

    pq->arr[0] = pq->arr[pq->size - 1];
    pq->size--;

    int currentIndex = 0;

    while (true)
    {
        int leftChild = 2 * currentIndex + 1;
        int rightChild = 2 * currentIndex + 2;
        int smallest = currentIndex;

        if (leftChild < pq->size && pq->arr[leftChild] < pq->arr[smallest])
        {
            smallest = leftChild;
        }
        if (rightChild < pq->size && pq->arr[rightChild] < pq->arr[smallest])
        {
            smallest = rightChild;
        }

        if (smallest == currentIndex)
        {
            break;
        }

        swap(&pq->arr[currentIndex], &pq->arr[smallest]);
        currentIndex = smallest;
    }

    return minValue;
}

int peekMin(PriorityQueue *pq)
{
    if (pq->size <= 0)
        return -1;
    return pq->arr[0];
}

int main()
{
    PriorityQueue pq;
    initPQ(&pq);

    printf("Inserting: 45, 20, 14, 12, 31\n");
    insert(&pq, 45);
    insert(&pq, 20);
    insert(&pq, 14);
    insert(&pq, 12);
    insert(&pq, 31);

    printf("Highest priority (smallest value) is currently: %d\n\n", peekMin(&pq));

    printf("Extracting elements by priority:\n");
    while (pq.size > 0)
    {
        printf("%d ", extractMin(&pq));
    }
    printf("\n");

    return 0;
}