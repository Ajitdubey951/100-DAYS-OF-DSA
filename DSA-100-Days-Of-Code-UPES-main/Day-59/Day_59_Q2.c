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

struct TreeNode *buildTreeHelper(int *inorder, int inStart, int inEnd, int *postorder, int *postIndex)
{
    if (inStart > inEnd)
    {
        return NULL;
    }

    int rootVal = postorder[*postIndex];
    struct TreeNode *root = createNode(rootVal);
    (*postIndex)--;

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

void printInorder(struct TreeNode *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->val);
    printInorder(node->right);
}

int main()
{
    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    struct TreeNode *root = buildTree(inorder, n, postorder, n);

    printf("Inorder traversal of constructed tree: ");
    printInorder(root);
    printf("\n");

    return 0;
}