#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *front;
    Node *rear;
} Queue;

void initQueue(Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

bool isEmpty(Queue *q)
{
    return q->front == NULL;
}

void enqueue(Queue *q, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q))
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued: %d\n", value);
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow! The queue is empty.\n");
        return -1;
    }

    Node *temp = q->front;
    int dequeuedValue = temp->data;

    q->front = q->front->next;

    if (q->front == NULL)
    {
        q->rear = NULL;
    }

    free(temp);
    printf("Dequeued: %d\n", dequeuedValue);

    return dequeuedValue;
}

int peek(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->front->data;
}

void displayQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }

    Node *temp = q->front;
    printf("Queue (Front -> Rear): ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}