#include <stdio.h>
#include <stdlib.h>

#define INF 1000000

int findTheCity(int n, int **edges, int edgesSize, int *edgesColSize, int distanceThreshold)
{
    int dist[n][n];
    int i, j, k;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    for (i = 0; i < edgesSize; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        if (u < n && v < n)
        {
            dist[u][v] = w;
            dist[v][u] = w;
        }
    }

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int minReachable = n;
    int resultCity = -1;

    for (i = 0; i < n; i++)
    {
        int reachableCount = 0;
        for (j = 0; j < n; j++)
        {
            if (i != j && dist[i][j] <= distanceThreshold)
            {
                reachableCount++;
            }
        }

        if (reachableCount <= minReachable)
        {
            minReachable = reachableCount;
            resultCity = i;
        }
    }

    return resultCity;
}