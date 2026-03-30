#include <stdlib.h>

int find(int *parent, int i)
{
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

int *findRedundantConnection(int **edges, int edgesSize, int *edgesColSize, int *returnSize)
{
    int *parent = (int *)malloc((edgesSize + 1) * sizeof(int));
    for (int i = 0; i <= edgesSize; i++)
        parent[i] = i;

    int *result = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < edgesSize; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        int rootU = find(parent, u);
        int rootV = find(parent, v);

        if (rootU == rootV)
        {
            result[0] = u;
            result[1] = v;
            free(parent);
            return result;
        }

        parent[rootU] = rootV;
    }

    free(parent);
    return NULL;
}