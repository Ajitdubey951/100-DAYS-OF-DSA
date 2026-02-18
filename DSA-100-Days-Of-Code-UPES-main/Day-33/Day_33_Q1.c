#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct
{
    char arr[MAX];
    int top;
} Stack;

void initStack(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, char c)
{
    if (s->top < MAX - 1)
    {
        s->arr[++(s->top)] = c;
    }
}

char pop(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->arr[(s->top)--];
    }
    return '\0';
}

char peek(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->arr[s->top];
    }
    return '\0';
}

int isOperand(char c)
{
    return isalnum(c);
}

int precedence(char op)
{
    switch (op)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

void infixToPostfix(char *infix)
{
    Stack s;
    initStack(&s);

    int i = 0, k = 0;
    char postfix[MAX];

    while (infix[i] != '\0')
    {
        char current = infix[i];

        if (isOperand(current))
        {
            postfix[k++] = current;
        }

        else if (current == '(')
        {
            push(&s, current);
        }

        else if (current == ')')
        {
            while (!isEmpty(&s) && peek(&s) != '(')
            {
                postfix[k++] = pop(&s);
            }
            pop(&s);
        }

        else
        {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(current))
            {
                postfix[k++] = pop(&s);
            }
            push(&s, current);
        }
        i++;
    }

    while (!isEmpty(&s))
    {
        postfix[k++] = pop(&s);
    }

    postfix[k] = '\0';

    printf("Infix:   %s\n", infix);
    printf("Postfix: %s\n", postfix);
}

int main()
{
    char expression1[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(expression1);

    printf("\n");

    char expression2[] = "(A+B)*C-(D-E)*(F+G)";
    infixToPostfix(expression2);

    return 0;
}