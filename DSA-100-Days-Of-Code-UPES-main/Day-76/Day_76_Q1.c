#include <stdio.h>
#include <stdlib.h>

void dfs(int u, int n, int adj[n][n], int visited[])
{
    visited[u] = 1;

    for (int v = 0; v < n; v++)
    {
        if (adj[u][v] == 1 && !visited[v])
        {
            dfs(v, n, adj, visited);
        }
    }
}

int countConnectedComponents(int n, int adj[n][n])
{
    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            count++;
            dfs(i, n, adj, visited);
        }
    }
    return count;
}

int main()
{
    int n = 5;
    int adj[5][5] = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    printf("Total Connected Components: %d\n", countConnectedComponents(n, adj));

    return 0;
}