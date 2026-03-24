#include <stdlib.h>
#include <stdbool.h>

int *findOrder(int numCourses, int **prerequisites, int prerequisitesSize, int *prerequisitesColSize, int *returnSize)
{
    int *inDegree = (int *)calloc(numCourses, sizeof(int));
    int *head = (int *)malloc(numCourses * sizeof(int));
    int *next = (int *)malloc(prerequisitesSize * sizeof(int));
    int *to = (int *)malloc(prerequisitesSize * sizeof(int));

    for (int i = 0; i < numCourses; i++)
        head[i] = -1;

    for (int i = 0; i < prerequisitesSize; i++)
    {
        int course = prerequisites[i][0];
        int prereq = prerequisites[i][1];
        to[i] = course;
        next[i] = head[prereq];
        head[prereq] = i;
        inDegree[course]++;
    }

    int *queue = (int *)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < numCourses; i++)
    {
        if (inDegree[i] == 0)
        {
            queue[rear++] = i;
        }
    }

    int *result = (int *)malloc(numCourses * sizeof(int));
    int count = 0;

    while (front < rear)
    {
        int u = queue[front++];
        result[count++] = u;

        for (int e = head[u]; e != -1; e = next[e])
        {
            int v = to[e];
            inDegree[v]--;
            if (inDegree[v] == 0)
            {
                queue[rear++] = v;
            }
        }
    }
    free(inDegree);
    free(head);
    free(next);
    free(to);
    free(queue);
    if (count == numCourses)
    {
        *returnSize = numCourses;
        return result;
    }
    else
    {
        free(result);
        *returnSize = 0;
        return NULL;
    }
}