#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct
{
    Node *front;
    Node *rear;
} Deque;

void initDeque(Deque *dq)
{
    dq->front = NULL;
    dq->rear = NULL;
}

bool isEmpty(Deque *dq)
{
    return dq->front == NULL;
}

void insertFront(Deque *dq, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = dq->front;

    if (isEmpty(dq))
    {
        dq->rear = newNode;
    }
    else
    {
        dq->front->prev = newNode;
    }
    dq->front = newNode;
    printf("Inserted %d at front.\n", value);
}

void insertRear(Deque *dq, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if (isEmpty(dq))
    {
        dq->front = newNode;
    }
    else
    {
        dq->rear->next = newNode;
    }
    dq->rear = newNode;
    printf("Inserted %d at rear.\n", value);
}

void deleteFront(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque Underflow! Nothing to delete at front.\n");
        return;
    }

    Node *temp = dq->front;
    int deletedValue = temp->data;

    dq->front = dq->front->next;

    if (dq->front == NULL)
    {
        dq->rear = NULL;
    }
    else
    {
        dq->front->prev = NULL;
    }

    free(temp);
    printf("Deleted %d from front.\n", deletedValue);
}

void deleteRear(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque Underflow! Nothing to delete at rear.\n");
        return;
    }

    Node *temp = dq->rear;
    int deletedValue = temp->data;

    dq->rear = dq->rear->prev;

    if (dq->rear == NULL)
    {
        dq->front = NULL;
    }
    else
    {
        dq->rear->next = NULL;
    }

    free(temp);
    printf("Deleted %d from rear.\n", deletedValue);
}

void display(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty.\n");
        return;
    }

    Node *temp = dq->front;
    printf("Deque (Front -> Rear): ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Deque dq;
    initDeque(&dq);

    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 5);
    display(&dq);

    deleteRear(&dq);
    display(&dq);

    deleteFront(&dq);
    display(&dq);

    return 0;
}