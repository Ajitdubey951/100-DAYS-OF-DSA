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

void inorderHelper(struct TreeNode *root, int *arr, int *index)
{
    if (root == NULL)
    {
        return;
    }

    inorderHelper(root->left, arr, index);

    arr[*index] = root->val;
    (*index)++;

    inorderHelper(root->right, arr, index);
}

int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
    *returnSize = countNodes(root);

    if (*returnSize == 0)
    {
        return NULL;
    }

    int *result = (int *)malloc((*returnSize) * sizeof(int));

    int currentIndex = 0;
    inorderHelper(root, result, &currentIndex);

    return result;
}