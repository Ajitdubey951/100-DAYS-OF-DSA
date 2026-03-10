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

struct TreeNode *lowestCommonAncestor(struct TreeNode *root, int pVal, int qVal)
{
    if (root == NULL || root->val == pVal || root->val == qVal)
    {
        return root;
    }

    struct TreeNode *leftSearch = lowestCommonAncestor(root->left, pVal, qVal);
    struct TreeNode *rightSearch = lowestCommonAncestor(root->right, pVal, qVal);

    if (leftSearch != NULL && rightSearch != NULL)
    {
        return root;
    }

    return (leftSearch != NULL) ? leftSearch : rightSearch;
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

    if (scanf("%d", &n) != 1 || n <= 0)
        return 0;

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int p, q;
    if (scanf("%d %d", &p, &q) != 2)
    {
        free(arr);
        return 0;
    }

    struct TreeNode *root = buildTree(arr, n);
    struct TreeNode *lca = lowestCommonAncestor(root, p, q);

    if (lca != NULL)
    {
        printf("%d\n", lca->val);
    }
    else
    {
        printf("LCA not found.\n");
    }

    free(arr);
    return 0;
}