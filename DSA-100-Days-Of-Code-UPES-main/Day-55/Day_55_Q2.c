#include <stdio.h>
#include <stdlib.h>


struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


void rightViewDFS(struct TreeNode *node, int depth, int *maxDepth, int *result, int *returnSize)
{
    if (node == NULL)
    {
        return;
    }
    if (depth > *maxDepth)
    {
        result[*returnSize] = node->val;
        (*returnSize)++;
        *maxDepth = depth;
    }
    rightViewDFS(node->right, depth + 1, maxDepth, result, returnSize);
    rightViewDFS(node->left, depth + 1, maxDepth, result, returnSize);
}

int *rightSideView(struct TreeNode *root, int *returnSize)
{
    *returnSize = 0;

    if (root == NULL)
    {
        return NULL;
    }

    int *result = (int *)malloc(100 * sizeof(int));
    int maxDepth = -1;
    rightViewDFS(root, 0, &maxDepth, result, returnSize);

    return result;
}