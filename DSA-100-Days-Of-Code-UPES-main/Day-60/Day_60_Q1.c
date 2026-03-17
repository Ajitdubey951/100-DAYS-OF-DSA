#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int k)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = k;
    node->right = node->left = NULL;
    return node;
}

int countNodes(struct Node *root)
{
    if (root == NULL)
        return 0;
    return (1 + countNodes(root->left) + countNodes(root->right));
}

bool isComplete(struct Node *root, int index, int number_nodes)
{
    if (root == NULL)
        return true;
    if (index >= number_nodes)
        return false;
    return (isComplete(root->left, 2 * index + 1, number_nodes) &&
            isComplete(root->right, 2 * index + 2, number_nodes));
}

bool isHeapProperty(struct Node *root)
{
    if (root->left == NULL && root->right == NULL)
        return true;

    if (root->right == NULL)
    {
        return root->data <= root->left->data;
    }
    else
    {
        if (root->data <= root->left->data && root->data <= root->right->data)
        {
            return (isHeapProperty(root->left) && isHeapProperty(root->right));
        }
        else
        {
            return false;
        }
    }
}

bool isMinHeap(struct Node *root)
{
    int node_count = countNodes(root);
    int index = 0;

    if (isComplete(root, index, node_count) && isHeapProperty(root))
    {
        return true;
    }
    return false;
}

int main()
{
    struct Node *root = newNode(10);
    root->left = newNode(15);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);
    root->right->left = newNode(100);

    if (isMinHeap(root))
        printf("The tree is a Min-Heap\n");
    else
        printf("The tree is NOT a Min-Heap\n");

    return 0;
}