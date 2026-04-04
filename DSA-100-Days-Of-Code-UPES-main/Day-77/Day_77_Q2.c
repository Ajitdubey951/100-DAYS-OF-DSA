#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int timer;

void dfs(int u, int p, int *disc, int *low, int **adj, int *adjSize, int ***res, int *resSize)
{
    disc[u] = low[u] = ++timer;

    for (int i = 0; i < adjSize[u]; i++)
    {
        int v = adj[u][i];
        if (v == p)
            continue;

        if (disc[v] == 0)
        {
            dfs(v, u, disc, low, adj, adjSize, res, resSize);
            low[u] = MIN(low[u], low[v]);

            if (low[v] > disc[u])
            {
                (*res)[*resSize] = (int *)malloc(2 * sizeof(int));
                (*res)[*resSize][0] = u;
                (*res)[*resSize][1] = v;
                (*resSize)++;
            }
        }
        else
        {
            low[u] = MIN(low[u], disc[v]);
        }
    }
}

int **criticalConnections(int n, int **connections, int connectionsSize, int *connectionsColSize, int *returnSize, int **returnColumnSizes)
{
    int **adj = (int **)malloc(n * sizeof(int *));
    int *adjSize = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < connectionsSize; i++)
    {
        adjSize[connections[i][0]]++;
        adjSize[connections[i][1]]++;
    }

    for (int i = 0; i < n; i++)
    {
        adj[i] = (int *)malloc(adjSize[i] * sizeof(int));
        adjSize[i] = 0;
    }

    for (int i = 0; i < connectionsSize; i++)
    {
        int u = connections[i][0], v = connections[i][1];
        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    int *disc = (int *)calloc(n, sizeof(int));
    int *low = (int *)calloc(n, sizeof(int));
    int **res = (int **)malloc(connectionsSize * sizeof(int *));

    *returnSize = 0;
    timer = 0;

    dfs(0, -1, disc, low, adj, adjSize, &res, returnSize);

    *returnColumnSizes = (int *)malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++)
    {
        (*returnColumnSizes)[i] = 2;
    }

    free(disc);
    free(low);
    for (int i = 0; i < n; i++)
        free(adj[i]);
    free(adj);
    free(adjSize);

    return res;
}

int main()
{
    int n = 4;
    int connectionsSize = 4;
    int *connections[4];
    int c0[] = {0, 1};
    int c1[] = {1, 2};
    int c2[] = {2, 0};
    int c3[] = {1, 3};
    connections[0] = c0;
    connections[1] = c1;
    connections[2] = c2;
    connections[3] = c3;

    int returnSize;
    int *returnColumnSizes;
    int **result = criticalConnections(n, connections, connectionsSize, NULL, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++)
    {
        printf("[%d, %d]\n", result[i][0], result[i][1]);
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}