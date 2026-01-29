void setZeroes(int **matrix, int matrixSize, int *matrixColSize)
{
    int m = matrixSize;
    int n = matrixColSize[0];
    int row[m], col[n];
    for (int i = 0; i < m; i++)
    {
        row[i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        col[i] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 0;
                col[j] = 0;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (row[i] == 0 || col[j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
}