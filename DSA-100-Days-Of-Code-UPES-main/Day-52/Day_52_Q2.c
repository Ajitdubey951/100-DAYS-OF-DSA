#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q)
{
    if (root == NULL || root == p || root == q)
    {
        return root;
    }

    struct TreeNode *leftSearch = lowestCommonAncestor(root->left, p, q);
    struct TreeNode *rightSearch = lowestCommonAncestor(root->right, p, q);

    if (leftSearch != NULL && rightSearch != NULL)
    {
        return root;
    }

    return (leftSearch != NULL) ? leftSearch : rightSearch;
}