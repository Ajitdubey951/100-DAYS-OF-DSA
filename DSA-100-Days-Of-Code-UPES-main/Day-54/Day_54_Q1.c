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

void zigzagTraversal(struct TreeNode *root)
{
    if (root == NULL)
        return;

    Queue *q = createQueue(2000);
    enqueue(q, root);

    bool leftToRight = true;

    printf("Zigzag Traversal:\n");

    while (!isQueueEmpty(q))
    {
        int levelSize = q->rear - q->front;

        int *levelArr = (int *)malloc(levelSize * sizeof(int));

        for (int i = 0; i < levelSize; i++)
        {
            struct TreeNode *current = dequeue(q);

            int index = leftToRight ? i : (levelSize - 1 - i);
            levelArr[index] = current->val;

            if (current->left != NULL)
                enqueue(q, current->left);
            if (current->right != NULL)
                enqueue(q, current->right);
        }

        for (int i = 0; i < levelSize; i++)
        {
            printf("%d ", levelArr[i]);
        }
        printf("\n");

        free(levelArr);

        leftToRight = !leftToRight;
    }

    free(q->data);
    free(q);
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
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct TreeNode *root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}