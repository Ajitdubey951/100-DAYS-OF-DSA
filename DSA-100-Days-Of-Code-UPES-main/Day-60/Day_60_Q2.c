#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int cameraCount;

int solve(struct TreeNode *node)
{
    if (node == NULL)
    {
        return 2;
    }

    int left = solve(node->left);
    int right = solve(node->right);

    if (left == 0 || right == 0)
    {
        cameraCount++;
        return 1;
    }

    if (left == 1 || right == 1)
    {
        return 2;
    }

    return 0;
}

int minCameraCover(struct TreeNode *root)
{
    cameraCount = 0;

    if (solve(root) == 0)
    {
        cameraCount++;
    }

    return cameraCount;
}

struct TreeNode *newNode(int val)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main()
{
    struct TreeNode *root = newNode(0);
    root->left = newNode(0);
    root->left->left = newNode(0);
    root->left->right = newNode(0);

    printf("Minimum cameras needed: %d\n", minCameraCover(root));

    return 0;
}