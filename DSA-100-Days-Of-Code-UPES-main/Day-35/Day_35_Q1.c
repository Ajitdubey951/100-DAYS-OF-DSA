#include <stdio.h>
#include <stdlib.h>

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

    if (q->rear == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
        printf("Enqueued: %d\n", value);
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
    printf("Enqueued: %d\n", value);
}

int dequeue(Queue *q)
{
    if (q->front == NULL)
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

void display(Queue *q)
{
    if (q->front == NULL)
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

int main()
{
    Queue q;
    initQueue(&q);

    printf("Testing Queue Operations\n");

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);

    dequeue(&q);
    display(&q);

    enqueue(&q, 40);
    display(&q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    dequeue(&q);

    return 0;
}