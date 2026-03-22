#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int r, c, time;
} Orange;

int orangesRotting(int **grid, int gridS, int *gridCS)
{
    int rows = gridS;
    int cols = gridCS[0];
    int freshCount = 0;

    Orange *queue = (Orange *)malloc(rows * cols * sizeof(Orange));
    int head = 0, tail = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 2)
            {
                queue[tail++] = (Orange){i, j, 0};
            }
            else if (grid[i][j] == 1)
            {
                freshCount++;
            }
        }
    }

    if (freshCount == 0)
        return 0;

    int maxTime = 0;
    int dR[] = {0, 0, 1, -1};
    int dC[] = {1, -1, 0, 0};

    while (head < tail)
    {
        Orange curr = queue[head++];
        maxTime = curr.time;

        for (int i = 0; i < 4; i++)
        {
            int nR = curr.r + dR[i];
            int nC = curr.c + dC[i];

            if (nR >= 0 && nR < rows && nC >= 0 && nC < cols && grid[nR][nC] == 1)
            {
                grid[nR][nC] = 2;
                freshCount--;
                queue[tail++] = (Orange){nR, nC, curr.time + 1};
            }
        }
    }

    free(queue);

    return (freshCount == 0) ? maxTime : -1;
}

int main()
{
    int r = 3, c = 3;
    int row1[] = {2, 1, 1};
    int row2[] = {1, 1, 0};
    int row3[] = {0, 1, 1};

    int *grid[] = {row1, row2, row3};
    int gridColSize[] = {3, 3, 3};

    int result = orangesRotting(grid, r, gridColSize);
    printf("Minimum minutes: %d\n", result);

    return 0;
}