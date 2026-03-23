#include <stdbool.h>
#include <stdlib.h>

bool isCycle(int edges[][2], int E, int V)
{
    int *head = (int *)malloc(V * sizeof(int));
    int *next = (int *)malloc(2 * E * sizeof(int));
    int *to = (int *)malloc(2 * E * sizeof(int));

    for (int i = 0; i < V; i++)
        head[i] = -1;

    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        to[2 * i] = v;
        next[2 * i] = head[u];
        head[u] = 2 * i;

        to[2 * i + 1] = u;
        next[2 * i + 1] = head[v];
        head[v] = 2 * i + 1;
    }

    bool *visited = (bool *)calloc(V, sizeof(bool));
    int *queue = (int *)malloc(V * sizeof(int));
    int *parent = (int *)malloc(V * sizeof(int));

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            int qHead = 0, qTail = 0;
            queue[qTail++] = i;
            visited[i] = true;
            parent[i] = -1;

            while (qHead < qTail)
            {
                int u = queue[qHead++];

                for (int e = head[u]; e != -1; e = next[e])
                {
                    int v = to[e];
                    if (!visited[v])
                    {
                        visited[v] = true;
                        parent[v] = u;
                        queue[qTail++] = v;
                    }
                    else if (v != parent[u])
                    {
                        free(head);
                        free(next);
                        free(to);
                        free(visited);
                        free(queue);
                        free(parent);
                        return true;
                    }
                }
            }
        }
    }

    free(head);
    free(next);
    free(to);
    free(visited);
    free(queue);
    free(parent);
    return false;
}