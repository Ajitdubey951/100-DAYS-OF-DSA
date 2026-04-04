#include <stdio.h>
#include <stdbool.h>

void dfs(int u, int n, int adj[n][n], bool visited[], int *count)
{
    visited[u] = true;
    (*count)++;

    for (int v = 0; v < n; v++)
    {
        if (adj[u][v] == 1 && !visited[v])
        {
            dfs(v, n, adj, visited, count);
        }
    }
}

bool isConnected(int n, int adj[n][n])
{
    if (n == 0)
        return true;

    bool visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    int count = 0;
    dfs(0, n, adj, visited, &count);

    return (count == n);
}

int main()
{
    int n = 4;
    int adj[4][4] = {
        {0, 1, 1, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 1},
        {0, 0, 1, 0}};

    if (isConnected(n, adj))
    {
        printf("The graph is connected.\n");
    }
    else
    {
        printf("The graph is not connected.\n");
    }

    return 0;
}