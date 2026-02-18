#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int calculate(char *s)
{
    int len = strlen(s);

    int *stack = (int *)malloc(len * sizeof(int));
    int top = -1;

    long currentNumber = 0;
    char sign = '+';

    for (int i = 0; i <= len; i++)
    {
        char c = s[i];

        if (isdigit(c))
        {
            currentNumber = (currentNumber * 10) + (c - '0');
        }

        if ((!isdigit(c) && c != ' ') || c == '\0')
        {

            if (sign == '+')
            {
                stack[++top] = currentNumber;
            }
            else if (sign == '-')
            {
                stack[++top] = -currentNumber;
            }
            else if (sign == '*')
            {
                stack[top] = stack[top] * currentNumber;
            }
            else if (sign == '/')
            {
                stack[top] = stack[top] / currentNumber;
            }

            sign = c;
            currentNumber = 0;
        }
    }

    int result = 0;
    for (int i = 0; i <= top; i++)
    {
        result += stack[i];
    }
    free(stack);

    return result;
}