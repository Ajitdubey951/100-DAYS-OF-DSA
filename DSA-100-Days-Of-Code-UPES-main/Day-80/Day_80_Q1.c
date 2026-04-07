#include <stdio.h>

#define INF 9999999

void floydWarshall(int n, int matrix[n][n])
{
    int dist[n][n];
    int i, j, k;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
            {
                dist[i][j] = INF;
            }
            else
            {
                dist[i][j] = matrix[i][j];
            }
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

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (dist[i][j] >= INF)
            {
                printf("-1 ");
            }
            else
            {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int n;
    if (scanf("%d", &n) != 1)
        return 0;

    int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    floydWarshall(n, matrix);

    return 0;
}