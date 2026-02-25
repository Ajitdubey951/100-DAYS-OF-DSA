#include <stdlib.h>

int *dailyTemperatures(int *temperatures, int temperaturesSize, int *returnSize)
{

    *returnSize = temperaturesSize;
    int *answer = (int *)calloc(temperaturesSize, sizeof(int));

    int *stack = (int *)malloc(temperaturesSize * sizeof(int));
    int top = -1;

    for (int i = 0; i < temperaturesSize; i++)
    {

        while (top >= 0 && temperatures[i] > temperatures[stack[top]])
        {

            int prevDayIndex = stack[top];
            top--;

            answer[prevDayIndex] = i - prevDayIndex;
        }

        stack[++top] = i;
    }

    free(stack);
    return answer;
}