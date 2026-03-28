#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int minCostConnectPoints(int **points, int pointsSize, int *pointsColSize)
{
    int n = pointsSize;
    if (n == 0)
        return 0;

    int totalCost = 0;
    int connectedNodes = 0;

    int *minDist = (int *)malloc(n * sizeof(int));
    int *inMST = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        minDist[i] = INT_MAX;
    }

    minDist[0] = 0;

    for (int i = 0; i < n; i++)
    {
        int u = -1;

        for (int j = 0; j < n; j++)
        {
            if (!inMST[j] && (u == -1 || minDist[j] < minDist[u]))
            {
                u = j;
            }
        }

        inMST[u] = 1;
        totalCost += minDist[u];
        connectedNodes++;

        for (int v = 0; v < n; v++)
        {
            if (!inMST[v])
            {
                int dist = abs(points[u][0] - points[v][0]) +
                           abs(points[u][1] - points[v][1]);

                if (dist < minDist[v])
                {
                    minDist[v] = dist;
                }
            }
        }
    }

    free(minDist);
    free(inMST);

    return totalCost;
}