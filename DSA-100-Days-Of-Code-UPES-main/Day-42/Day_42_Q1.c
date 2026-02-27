#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct
{
    int arr[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s) { s->top = -1; }
bool isStackEmpty(Stack *s) { return s->top == -1; }
void push(Stack *s, int val) { s->arr[++(s->top)] = val; }
int pop(Stack *s) { return s->arr[(s->top)--]; }

typedef struct
{
    int arr[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
}
bool isQueueEmpty(Queue *q) { return q->front > q->rear; }
void enqueue(Queue *q, int val) { q->arr[++(q->rear)] = val; }
int dequeue(Queue *q) { return q->arr[(q->front)++]; }

void reverseQueue(Queue *q)
{
    Stack s;
    initStack(&s);

    while (!isQueueEmpty(q))
    {
        push(&s, dequeue(q));
    }

    initQueue(q);

    while (!isStackEmpty(&s))
    {
        enqueue(q, pop(&s));
    }
}

void displayQueue(Queue *q)
{
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main()
{
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("Original Queue: ");
    displayQueue(&q);

    reverseQueue(&q);

    printf("Reversed Queue: ");
    displayQueue(&q);

    return 0;
}