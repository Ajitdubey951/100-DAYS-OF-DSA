#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *stack;
    int *minStack;
    int top;
    int capacity;
} MinStack;

MinStack *minStackCreate(int capacity)
{
    MinStack *obj = (MinStack *)malloc(sizeof(MinStack));
    obj->capacity = capacity;
    obj->stack = (int *)malloc(sizeof(int) * capacity);
    obj->minStack = (int *)malloc(sizeof(int) * capacity);
    obj->top = -1;
    return obj;
}

void minStackPush(MinStack *obj, int val)
{
    obj->top++;
    obj->stack[obj->top] = val;

    if (obj->top == 0)
        obj->minStack[obj->top] = val;
    else
    {
        if (val < obj->minStack[obj->top - 1])
            obj->minStack[obj->top] = val;
        else
            obj->minStack[obj->top] = obj->minStack[obj->top - 1];
    }
}

void minStackPop(MinStack *obj)
{
    if (obj->top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    obj->top--;
}

int minStackTop(MinStack *obj)
{
    if (obj->top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return obj->stack[obj->top];
}

int minStackGetMin(MinStack *obj)
{
    if (obj->top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return obj->minStack[obj->top];
}

void minStackFree(MinStack *obj)
{
    free(obj->stack);
    free(obj->minStack);
    free(obj);
}

int main()
{
    int capacity;
    printf("Enter stack capacity: ");
    scanf("%d", &capacity);

    MinStack *stack = minStackCreate(capacity);

    int choice, value;

    do
    {
        printf("\n1. Push\n2. Pop\n3. Top\n4. Get Minimum\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            minStackPush(stack, value);
            break;

        case 2:
            minStackPop(stack);
            break;

        case 3:
            printf("Top element: %d\n", minStackTop(stack));
            break;

        case 4:
            printf("Minimum element: %d\n", minStackGetMin(stack));
            break;

        case 5:
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 5);

    minStackFree(stack);

    return 0;
}