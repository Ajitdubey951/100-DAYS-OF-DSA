#include <stdbool.h>
#include <string.h>

bool dfs(int u, int c, int *color, int **graph, int *graphColSize)
{
    color[u] = c;
    for (int i = 0; i < graphColSize[u]; i++)
    {
        int v = graph[u][i];
        if (color[v] == c)
            return false;
        if (color[v] == -1)
        {
            if (!dfs(v, 1 - c, color, graph, graphColSize))
                return false;
        }
    }
    return true;
}

bool isBipartite(int **graph, int graphSize, int *graphColSize)
{
    int *color = (int *)malloc(graphSize * sizeof(int));
    for (int i = 0; i < graphSize; i++)
        color[i] = -1;

    for (int i = 0; i < graphSize; i++)
    {
        if (color[i] == -1)
        {
            if (!dfs(i, 0, color, graph, graphColSize))
            {
                free(color);
                return false;
            }
        }
    }

    free(color);
    return true;
}