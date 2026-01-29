#include <stdio.h>

int main()
{
    int r, c;
    printf("Enter number of row in matrix: ");
    scanf("%d", &r);
    printf("Enter number of columns in matrix: ");
    scanf("%d", &c);
    if (r != c)
    {
        printf("Not a square matrix\n");
        return 0;
    }
    int mat[r][c];
    printf("Enter elements of matrix:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Element[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    int sum = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == j)
            {
                sum += mat[i][j];
            }
        }
    }
    printf("Sum of primary diagonal elements: %d\n", sum);
    return 0;
}