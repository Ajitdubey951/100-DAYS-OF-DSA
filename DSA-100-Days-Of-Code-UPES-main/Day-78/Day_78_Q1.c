#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int minKey(int key[], bool inMST[], int V)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
    {
        if (!inMST[v] && key[v] < min)
        {
            min = key[v], min_index = v;
        }
    }
    return min_index;
}

int primMST(int V, int graph[V][V])
{
    int key[V];
    bool inMST[V];
    int totalWeight = 0;

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        inMST[i] = false;
    }

    key[0] = 0;

    for (int count = 0; count < V; count++)
    {
        int u = minKey(key, inMST, V);
        inMST[u] = true;
        totalWeight += key[u];

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
            }
        }
    }
    return totalWeight;
}