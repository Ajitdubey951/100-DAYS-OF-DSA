#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

struct TreeNode *insert(struct TreeNode *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }
    if (value < root->val)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->val)
    {
        root->right = insert(root->right, value);
    }
    return root;
}

bool searchBST(struct TreeNode *root, int target)
{
    while (root != NULL)
    {
        if (root->val == target)
        {
            return true;
        }

        if (target < root->val)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    return false;
}

int main()
{
    int n;

    if (scanf("%d", &n) != 1 || n <= 0)
    {
        return 0;
    }

    struct TreeNode *root = NULL;

    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }

    int target;
    if (scanf("%d", &target) != 1)
    {
        return 0;
    }

    if (searchBST(root, target))
    {
        printf("Found\n");
    }
    else
    {
        printf("Not Found\n");
    }

    return 0;
}