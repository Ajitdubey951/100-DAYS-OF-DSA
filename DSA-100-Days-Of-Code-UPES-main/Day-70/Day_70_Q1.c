#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge
{
    int src, dest, weight;
};

void bellmanFord(int V, int E, struct Edge edges[], int src)
{
    int *dist = (int *)malloc(V * sizeof(int));

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }

    int hasCycle = 0;
    for (int i = 0; i < E; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            hasCycle = 1;
            break;
        }
    }

    if (hasCycle)
    {
        printf("Graph contains a negative weight cycle\n");
    }
    else
    {
        printf("Vertex   Distance from Source\n");
        for (int i = 0; i < V; i++)
        {
            printf("%d \t\t %d\n", i, dist[i]);
        }
    }

    free(dist);
}

int main()
{
    int V = 5;
    int E = 8;
    struct Edge edges[] = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};

    bellmanFord(V, E, edges, 0);

    return 0;
}