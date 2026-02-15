#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct
{
    int arr[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s)
{
    s->top = -1;
}

void push(Stack *s, int value)
{
    if (s->top >= MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

void pop(Stack *s)
{
    if (s->top < 0)
    {
        printf("Stack Underflow\n");
        return;
    }
    s->top--;
}

void display(Stack *s)
{
    if (s->top < 0)
    {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main()
{
    Stack s;
    initStack(&s);

    int n, type, value;

    if (scanf("%d", &n) != 1)
    {
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &type);

        if (type == 1)
        {
            scanf("%d", &value);
            push(&s, value);
        }
        else if (type == 2)
        {
            pop(&s);
        }
        else if (type == 3)
        {
            display(&s);
        }
    }

    return 0;
}