#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *createNode(int value)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

typedef struct
{
    TreeNode **data;
    int front;
    int rear;
} Queue;

Queue *createQueue(int capacity)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (TreeNode **)malloc(capacity * sizeof(TreeNode *));
    q->front = 0;
    q->rear = 0;
    return q;
}

void enqueue(Queue *q, TreeNode *node)
{
    q->data[q->rear++] = node;
}

TreeNode *dequeue(Queue *q)
{
    return q->data[q->front++];
}

bool isQueueEmpty(Queue *q)
{
    return q->front == q->rear;
}

TreeNode *buildTree(int *arr, int size)
{
    if (size == 0 || arr[0] == -1)
        return NULL;

    TreeNode *root = createNode(arr[0]);
    Queue *q = createQueue(size);

    enqueue(q, root);
    int i = 1;

    while (!isQueueEmpty(q) && i < size)
    {
        TreeNode *current = dequeue(q);

        if (i < size && arr[i] != -1)
        {
            current->left = createNode(arr[i]);
            enqueue(q, current->left);
        }
        i++;

        if (i < size && arr[i] != -1)
        {
            current->right = createNode(arr[i]);
            enqueue(q, current->right);
        }
        i++;
    }

    free(q->data);
    free(q);

    return root;
}

void printInorder(TreeNode *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, -1, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Building tree from array...\n");
    TreeNode *root = buildTree(arr, size);

    printf("Inorder Traversal of the constructed tree: ");
    printInorder(root);
    printf("\n");

    return 0;
}