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
} CircularQueue;

void initQueue(CircularQueue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(CircularQueue *q, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
        return;

    newNode->data = value;

    if (q->front == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
        newNode->next = q->front;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
        q->rear->next = q->front;
    }
}

void rotateQueue(CircularQueue *q)
{
    if (q->front != NULL)
    {
        q->front = q->front->next;
        q->rear = q->rear->next;
    }
}

void display(CircularQueue *q)
{
    if (q->front == NULL)
        return;

    Node *temp = q->front;

    do
    {
        printf("%d", temp->data);
        temp = temp->next;

        if (temp != q->front)
        {
            printf(" ");
        }
    } while (temp != q->front);

    printf("\n");
}

int main()
{
    CircularQueue q;
    initQueue(&q);

    int n, m, value;

    if (scanf("%d", &n) != 1)
        return 1;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        enqueue(&q, value);
    }

    if (scanf("%d", &m) != 1)
    {
        return 1;
    }

    for (int i = 0; i < m; i++)
    {
        rotateQueue(&q);
    }

    display(&q);

    if (q.front != NULL)
    {
        q.rear->next = NULL;
        Node *current = q.front;
        Node *nextNode;
        while (current != NULL)
        {
            nextNode = current->next;
            free(current);
            current = nextNode;
        }
    }

    return 0;
}