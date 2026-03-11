#include <stdlib.h>
#include <stdbool.h>


struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int **zigzagLevelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
    if (root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    int **result = (int **)malloc(2000 * sizeof(int *));
    *returnColumnSizes = (int *)malloc(2000 * sizeof(int));
    *returnSize = 0;

    struct TreeNode *queue[2000];
    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    bool leftToRight = true;

    while (front < rear)
    {
        int levelSize = rear - front;

        (*returnColumnSizes)[*returnSize] = levelSize;

        result[*returnSize] = (int *)malloc(levelSize * sizeof(int));

        for (int i = 0; i < levelSize; i++)
        {
            struct TreeNode *current = queue[front++];

            int index = leftToRight ? i : (levelSize - 1 - i);
            result[*returnSize][index] = current->val;

            if (current->left != NULL)
                queue[rear++] = current->left;
            if (current->right != NULL)
                queue[rear++] = current->right;
        }

        (*returnSize)++;
        leftToRight = !leftToRight;
    }

    return result;
}