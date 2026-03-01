#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countNodes(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

void preorderHelper(struct TreeNode *root, int *arr, int *index)
{
    if (root == NULL)
    {
        return;
    }

    arr[*index] = root->val;
    (*index)++;

    preorderHelper(root->left, arr, index);

    preorderHelper(root->right, arr, index);
}

int *preorderTraversal(struct TreeNode *root, int *returnSize)
{
    *returnSize = countNodes(root);

    if (*returnSize == 0)
    {
        return NULL;
    }

    int *result = (int *)malloc((*returnSize) * sizeof(int));

    int currentIndex = 0;
    preorderHelper(root, result, &currentIndex);

    return result;
}