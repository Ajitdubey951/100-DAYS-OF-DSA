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

typedef struct
{
    struct TreeNode *node;
    int hd;
} QueueItem;

typedef struct
{
    QueueItem *data;
    int front;
    int rear;
} Queue;

Queue *createQueue(int capacity)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (QueueItem *)malloc(capacity * sizeof(QueueItem));
    q->front = 0;
    q->rear = 0;
    return q;
}

void enqueue(Queue *q, struct TreeNode *node, int hd)
{
    q->data[q->rear].node = node;
    q->data[q->rear].hd = hd;
    q->rear++;
}

QueueItem dequeue(Queue *q)
{
    return q->data[q->front++];
}

int isQueueEmpty(Queue *q)
{
    return q->front == q->rear;
}

void verticalOrder(struct TreeNode *root)
{
    if (root == NULL)
        return;

    int offset = 500;
    int columns[1000][100];
    int colCounts[1000] = {0};

    int min_hd = offset;
    int max_hd = offset;

    Queue *q = createQueue(2000);
    enqueue(q, root, offset);

    while (!isQueueEmpty(q))
    {
        QueueItem current = dequeue(q);
        struct TreeNode *currNode = current.node;
        int currHD = current.hd;

        columns[currHD][colCounts[currHD]++] = currNode->val;

        if (currHD < min_hd)
            min_hd = currHD;
        if (currHD > max_hd)
            max_hd = currHD;

        if (currNode->left != NULL)
        {
            enqueue(q, currNode->left, currHD - 1);
        }
        if (currNode->right != NULL)
        {
            enqueue(q, currNode->right, currHD + 1);
        }
    }

    printf("Vertical Order Traversal:\n");
    for (int i = min_hd; i <= max_hd; i++)
    {
        if (colCounts[i] > 0)
        {
            for (int j = 0; j < colCounts[i]; j++)
            {
                printf("%d ", columns[i][j]);
            }
            printf("\n");
        }
    }

    free(q->data);
    free(q);
}

int main()
{
    struct TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    verticalOrder(root);

    return 0;
}