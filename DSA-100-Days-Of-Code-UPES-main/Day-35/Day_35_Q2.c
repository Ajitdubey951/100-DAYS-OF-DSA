#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct
{
    int arr[MAX_SIZE];
    int top;
} Stack;

void stackInit(Stack *s)
{
    s->top = -1;
}

void stackPush(Stack *s, int x)
{
    s->arr[++(s->top)] = x;
}

int stackPop(Stack *s)
{
    if (s->top == -1)
        return -1;
    return s->arr[(s->top)--];
}

int stackPeek(Stack *s)
{
    if (s->top == -1)
        return -1;
    return s->arr[s->top];
}

bool stackEmpty(Stack *s)
{
    return s->top == -1;
}

typedef struct
{
    Stack *stackIn;
    Stack *stackOut;
} MyQueue;

MyQueue *myQueueCreate()
{
    MyQueue *obj = (MyQueue *)malloc(sizeof(MyQueue));

    obj->stackIn = (Stack *)malloc(sizeof(Stack));
    obj->stackOut = (Stack *)malloc(sizeof(Stack));

    stackInit(obj->stackIn);
    stackInit(obj->stackOut);

    return obj;
}

void myQueuePush(MyQueue *obj, int x)
{
    stackPush(obj->stackIn, x);
}

void shiftStacks(MyQueue *obj)
{
    if (stackEmpty(obj->stackOut))
    {
        while (!stackEmpty(obj->stackIn))
        {
            stackPush(obj->stackOut, stackPop(obj->stackIn));
        }
    }
}

int myQueuePop(MyQueue *obj)
{
    shiftStacks(obj);
    return stackPop(obj->stackOut);
}

int myQueuePeek(MyQueue *obj)
{
    shiftStacks(obj);
    return stackPeek(obj->stackOut);
}

bool myQueueEmpty(MyQueue *obj)
{
    return stackEmpty(obj->stackIn) && stackEmpty(obj->stackOut);
}

void myQueueFree(MyQueue *obj)
{
    free(obj->stackIn);
    free(obj->stackOut);
    free(obj);
}