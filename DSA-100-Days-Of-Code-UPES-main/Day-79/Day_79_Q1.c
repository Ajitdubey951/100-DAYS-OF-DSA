#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void dijkstra(int n, int **adj, int **weight, int *adjSize, int source)
{
    int *dist = (int *)malloc((n + 1) * sizeof(int));
    int *visited = (int *)calloc((n + 1), sizeof(int));

    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;
    dist[source] = 0;

    for (int i = 0; i < n; i++)
    {
        int u = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
            {
                u = j;
            }
        }

        if (dist[u] == INT_MAX)
            break;
        visited[u] = 1;

        for (int j = 0; j < adjSize[u]; j++)
        {
            int v = adj[u][j];
            int w = weight[u][j];
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", dist[i]);
    }
    printf("\n");

    free(dist);
    free(visited);
}