#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} MyCircularDeque;

bool myCircularDequeIsEmpty(MyCircularDeque *obj)
{
    return obj->size == 0;
}

bool myCircularDequeIsFull(MyCircularDeque *obj)
{
    return obj->size == obj->capacity;
}

MyCircularDeque *myCircularDequeCreate(int k)
{
    MyCircularDeque *obj = (MyCircularDeque *)malloc(sizeof(MyCircularDeque));
    obj->capacity = k;
    obj->size = 0;
    obj->arr = (int *)malloc(sizeof(int) * k);

    obj->front = 0;
    obj->rear = k - 1;

    return obj;
}

bool myCircularDequeInsertFront(MyCircularDeque *obj, int value)
{
    if (myCircularDequeIsFull(obj))
        return false;

    obj->front = (obj->front - 1 + obj->capacity) % obj->capacity;
    obj->arr[obj->front] = value;
    obj->size++;

    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque *obj, int value)
{
    if (myCircularDequeIsFull(obj))
        return false;

    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->arr[obj->rear] = value;
    obj->size++;

    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque *obj)
{
    if (myCircularDequeIsEmpty(obj))
        return false;

    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;

    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque *obj)
{
    if (myCircularDequeIsEmpty(obj))
        return false;

    obj->rear = (obj->rear - 1 + obj->capacity) % obj->capacity;
    obj->size--;

    return true;
}

int myCircularDequeGetFront(MyCircularDeque *obj)
{
    if (myCircularDequeIsEmpty(obj))
        return -1;
    return obj->arr[obj->front];
}

int myCircularDequeGetRear(MyCircularDeque *obj)
{
    if (myCircularDequeIsEmpty(obj))
        return -1;
    return obj->arr[obj->rear];
}

void myCircularDequeFree(MyCircularDeque *obj)
{
    free(obj->arr);
    free(obj);
}