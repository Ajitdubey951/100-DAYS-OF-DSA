#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(int value)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void rightViewDFS(struct TreeNode *root, int currentDepth, int *maxDepth, int *result, int *returnSize)
{
    if (root == NULL)
    {
        return;
    }

    if (currentDepth > *maxDepth)
    {
        result[*returnSize] = root->val;
        (*returnSize)++;
        *maxDepth = currentDepth;
    }

    rightViewDFS(root->right, currentDepth + 1, maxDepth, result, returnSize);
    rightViewDFS(root->left, currentDepth + 1, maxDepth, result, returnSize);
}

int *rightSideView(struct TreeNode *root, int *returnSize)
{
    int *result = (int *)malloc(100 * sizeof(int));
    *returnSize = 0;

    int maxDepth = -1;

    rightViewDFS(root, 0, &maxDepth, result, returnSize);

    return result;
}

int main()
{
    struct TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->right = createNode(5);
    root->left->right->right = createNode(6);

    int returnSize;
    int *rightView = rightSideView(root, &returnSize);

    printf("Right Side View:\n");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", rightView[i]);
    }
    printf("\n");

    free(rightView);
    return 0;
}