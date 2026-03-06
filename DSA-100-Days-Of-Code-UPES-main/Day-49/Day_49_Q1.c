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

void inorder(struct TreeNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
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

    inorder(root);
    printf("\n");

    return 0;
}