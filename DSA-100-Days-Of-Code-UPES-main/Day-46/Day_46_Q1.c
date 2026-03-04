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

void levelOrder(struct TreeNode *root)
{
    if (root == NULL)
    {
        printf("Tree is empty.\n");
        return;
    }

    struct TreeNode *queue[1000];
    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    printf("Level Order Traversal:\n");

    while (front < rear)
    {
        int levelSize = rear - front;

        for (int i = 0; i < levelSize; i++)
        {
            struct TreeNode *current = queue[front++];

            printf("%d ", current->val);

            if (current->left != NULL)
            {
                queue[rear++] = current->left;
            }
            if (current->right != NULL)
            {
                queue[rear++] = current->right;
            }
        }

        printf("\n");
    }
}

int main()
{
    struct TreeNode *root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    levelOrder(root);

    return 0;
}