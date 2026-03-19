#include <stdio.h>
#include <stdlib.h>

void printMatrix(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n, m, isDirected;

    if (scanf("%d %d %d", &n, &m, &isDirected) != 3)
        return 0;

    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)calloc(n, sizeof(int));
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        if (scanf("%d %d", &u, &v) == 2)
        {
            if (u >= 0 && u < n && v >= 0 && v < n)
            {
                matrix[u][v] = 1;
                if (!isDirected)
                {
                    matrix[v][u] = 1;
                }
            }
        }
    }

    printMatrix(matrix, n);

    for (int i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}