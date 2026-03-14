#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void flatten(struct TreeNode *root)
{
    struct TreeNode *current = root;

    while (current != NULL)
    {
        if (current->left != NULL)
        {

            struct TreeNode *runner = current->left;
            while (runner->right != NULL)
            {
                runner = runner->right;
            }

            runner->right = current->right;

            current->right = current->left;

            current->left = NULL;
        }

        current = current->right;
    }
}