#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void topologicalSort(int V, int adj[MAX][MAX])
{
    int in_degree[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;
    int result[MAX];
    int count = 0;

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (adj[i][j] == 1)
            {
                in_degree[j]++;
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (in_degree[i] == 0)
        {
            queue[rear++] = i;
        }
    }

    while (front < rear)
    {
        int u = queue[front++];
        result[count++] = u;

        for (int v = 0; v < V; v++)
        {
            if (adj[u][v] == 1)
            {
                in_degree[v]--;
                if (in_degree[v] == 0)
                {
                    queue[rear++] = v;
                }
            }
        }
    }

    if (count != V)
    {
        printf("Cycle detected! Topological sort not possible.\n");
    }
    else
    {
        printf("Topological Sort: ");
        for (int i = 0; i < count; i++)
        {
            printf("%d ", result[i]);
        }
        printf("\n");
    }
}

int main()
{
    int V = 6;
    int adj[MAX][MAX] = {0};

    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    topologicalSort(V, adj);

    return 0;
}