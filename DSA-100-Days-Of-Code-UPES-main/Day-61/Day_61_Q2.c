#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void dfs(int **isConnected, int n, bool *visited, int i)
{
    for (int j = 0; j < n; j++)
    {
        if (isConnected[i][j] == 1 && !visited[j])
        {
            visited[j] = true;
            dfs(isConnected, n, visited, j);
        }
    }
}

int findCircleNum(int **isConnected, int isConnectedSize, int *isConnectedColSize)
{
    int n = isConnectedSize;
    bool *visited = (bool *)calloc(n, sizeof(bool));
    int provinceCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            provinceCount++;
            visited[i] = true;
            dfs(isConnected, n, visited, i);
        }
    }

    free(visited);
    return provinceCount;
}

int main()
{
    int n = 3;
    int *isConnected[] = {
        (int[]){1, 1, 0},
        (int[]){1, 1, 0},
        (int[]){0, 0, 1}};
    int colSize[] = {3, 3, 3};

    printf("Total Provinces: %d\n", findCircleNum(isConnected, n, colSize));

    return 0;
}