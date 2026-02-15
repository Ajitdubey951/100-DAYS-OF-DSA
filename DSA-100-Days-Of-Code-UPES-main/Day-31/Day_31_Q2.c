#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char *s)
{
    int len = strlen(s);
    if (len % 2 != 0)
    {
        return false;
    }
    char *stack = (char *)malloc(len * sizeof(char));
    int top = -1;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            stack[++top] = s[i];
        }
        else
        {
            if (top == -1)
            {
                return false;
            }
            char topChar = stack[top--];
            if ((s[i] == ')' && topChar != '(') || (s[i] == '}' && topChar != '{') || (s[i] == ']' && topChar != '['))
            {
                return false;
            }
        }
    }
    return top == -1;
}