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

    int isIdentity = 1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == j && mat[i][j] != 1)
            {
                isIdentity = 1;
            }
            if (i != j && mat[i][j] != 0)
            {
                isIdentity = 1;
            }
        }
    }
    if (isIdentity == 1)
    {
        printf("Identity matrix!\n");
    }
    else
    {
        printf("Not a identity matrix!\n");
    }
    return 0;
}