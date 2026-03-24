#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

void dfs(int u, int V, int adj[V][V], bool visited[], int stack[], int *top)
{
    visited[u] = true;

    for (int v = 0; v < V; v++)
    {
        if (adj[u][v] && !visited[v])
        {
            dfs(v, V, adj, visited, stack, top);
        }
    }

    stack[(*top)++] = u;
}

void topologicalSort(int V, int adj[V][V])
{
    bool visited[MAX] = {false};
    int stack[MAX];
    int top = 0;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, V, adj, visited, stack, &top);
        }
    }

    printf("Topological Order: ");
    while (top > 0)
    {
        printf("%d ", stack[--top]);
    }
    printf("\n");
}

int main()
{
    int V = 6;
    int adj[6][6] = {0};

    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    topologicalSort(V, adj);

    return 0;
}