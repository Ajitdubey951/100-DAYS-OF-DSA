#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSymmetric(struct TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }

    struct TreeNode *queue[2000];
    int front = 0;
    int rear = 0;

    queue[rear++] = root->left;
    queue[rear++] = root->right;

    while (front < rear)
    {
        struct TreeNode *leftNode = queue[front++];
        struct TreeNode *rightNode = queue[front++];

        if (leftNode == NULL && rightNode == NULL)
        {
            continue;
        }

        if (leftNode == NULL || rightNode == NULL || leftNode->val != rightNode->val)
        {
            return false;
        }

        queue[rear++] = leftNode->left;
        queue[rear++] = rightNode->right;

        queue[rear++] = leftNode->right;
        queue[rear++] = rightNode->left;
    }

    return true;
}