#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void push(Node **top, int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

int pop(Node **top)
{
    if (*top == NULL)
    {
        printf("Stack Underflow!\n");
        return 0;
    }

    Node *temp = *top;
    int poppedValue = temp->data;
    *top = (*top)->next;

    free(temp);
    return poppedValue;
}
int evaluatePostfix(char *expression)
{
    Node *stack = NULL;

    char *token = strtok(expression, " \n");

    while (token != NULL)
    {
        if (strlen(token) == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
        {

            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (token[0])
            {
            case '+':
                push(&stack, operand1 + operand2);
                break;
            case '-':
                push(&stack, operand1 - operand2);
                break;
            case '*':
                push(&stack, operand1 * operand2);
                break;
            case '/':
                push(&stack, operand1 / operand2);
                break;
            }
        }
        else
        {
            push(&stack, atoi(token));
        }

        token = strtok(NULL, " \n");
    }

    return pop(&stack);
}

int main()
{
    char expression[] = "2 3 1 * + 9 -";

    printf("Postfix Expression: %s\n", expression);

    int result = evaluatePostfix(expression);

    printf("Result: %d\n", result);

    return 0;
}