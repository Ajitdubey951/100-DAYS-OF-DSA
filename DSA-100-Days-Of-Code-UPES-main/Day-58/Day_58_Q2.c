#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *buildTreeHelper(int *inorder, int inStart, int inEnd,
                                 int *postorder, int *postIndex)
{
    if (inStart > inEnd)
    {
        return NULL;
    }

    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = rootVal;
    root->left = NULL;
    root->right = NULL;

    if (inStart == inEnd)
    {
        return root;
    }

    int inIndex;
    for (int i = inStart; i <= inEnd; i++)
    {
        if (inorder[i] == rootVal)
        {
            inIndex = i;
            break;
        }
    }

    root->right = buildTreeHelper(inorder, inIndex + 1, inEnd, postorder, postIndex);

    root->left = buildTreeHelper(inorder, inStart, inIndex - 1, postorder, postIndex);

    return root;
}

struct TreeNode *buildTree(int *inorder, int inorderSize, int *postorder, int postorderSize)
{
    int postIndex = postorderSize - 1;

    return buildTreeHelper(inorder, 0, inorderSize - 1, postorder, &postIndex);
}