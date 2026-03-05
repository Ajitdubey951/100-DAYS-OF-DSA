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

int countLeafNodes(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

typedef struct
{
    struct TreeNode **data;
    int front;
    int rear;
} Queue;

Queue *createQueue(int capacity)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (struct TreeNode **)malloc(capacity * sizeof(struct TreeNode *));
    q->front = 0;
    q->rear = 0;
    return q;
}

void enqueue(Queue *q, struct TreeNode *node)
{
    q->data[q->rear++] = node;
}

struct TreeNode *dequeue(Queue *q)
{
    return q->data[q->front++];
}

bool isQueueEmpty(Queue *q)
{
    return q->front == q->rear;
}

struct TreeNode *buildTree(int *arr, int size)
{
    if (size == 0 || arr[0] == -1)
        return NULL;

    struct TreeNode *root = createNode(arr[0]);
    Queue *q = createQueue(size);

    enqueue(q, root);
    int i = 1;

    while (!isQueueEmpty(q) && i < size)
    {
        struct TreeNode *current = dequeue(q);

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

int main()
{
    int n;

    if (scanf("%d", &n) != 1)
        return 1;

    if (n <= 0)
    {
        printf("0\n");
        return 0;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    struct TreeNode *root = buildTree(arr, n);
    int leafCount = countLeafNodes(root);

    printf("%d\n", leafCount);

    free(arr);
    return 0;
}