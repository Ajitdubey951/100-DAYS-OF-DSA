#include <stdio.h>
#include <stdlib.h>

void dfs(int u, int n, int **adj, int *adjSize, int *visited)
{
    visited[u] = 1;
    for (int i = 0; i < adjSize[u]; i++)
    {
        int v = adj[u][i];
        if (!visited[v])
        {
            dfs(v, n, adj, adjSize, visited);
        }
    }
}

int countComponents(int n, int **edges, int edgesSize, int *edgesColSize)
{
    int **adj = (int **)malloc(n * sizeof(int *));
    int *adjSize = (int *)calloc(n, sizeof(int));
    int *visited = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < edgesSize; i++)
    {
        adjSize[edges[i][0]]++;
        adjSize[edges[i][1]]++;
    }

    for (int i = 0; i < n; i++)
    {
        adj[i] = (int *)malloc(adjSize[i] * sizeof(int));
        adjSize[i] = 0;
    }

    for (int i = 0; i < edgesSize; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            count++;
            dfs(i, n, adj, adjSize, visited);
        }
    }

    for (int i = 0; i < n; i++)
        free(adj[i]);
    free(adj);
    free(adjSize);
    free(visited);

    return count;
}