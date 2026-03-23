#include <stdio.h>
#include <stdbool.h>

#define MAX 100

bool dfs(int adj[MAX][MAX], bool visited[MAX], int n, int curr, int parent)
{
    visited[curr] = true;

    for (int i = 0; i < n; i++)
    {
        if (adj[curr][i])
        {
            if (!visited[i])
            {
                if (dfs(adj, visited, n, i, curr))
                    return true;
            }
            else if (i != parent)
            {
                return true;
            }
        }
    }
    return false;
}

bool hasCycle(int adj[MAX][MAX], int n)
{
    bool visited[MAX] = {false};

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(adj, visited, n, i, -1))
                return true;
        }
    }
    return false;
}

int main()
{
    int n = 4;
    int adj[MAX][MAX] = {{0, 1, 1, 0}, {1, 0, 1, 0}, {1, 1, 0, 1}, {0, 0, 1, 0}};

    if (hasCycle(adj, n))
    {
        printf("Cycle detected\n");
    }
    else
    {
        printf("No cycle\n");
    }

    return 0;
}