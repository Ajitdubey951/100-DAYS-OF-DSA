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
void enqueue(Queue *q, struct TreeNode *node) { q->data[q->rear++] = node; }
struct TreeNode *dequeue(Queue *q) { return q->data[q->front++]; }
bool isQueueEmpty(Queue *q) { return q->front == q->rear; }

void printLevelOrder(struct TreeNode *root)
{
    if (root == NULL)
        return;
    Queue *q = createQueue(100);
    enqueue(q, root);
    while (!isQueueEmpty(q))
    {
        struct TreeNode *current = dequeue(q);
        if (current != NULL)
        {
            printf("%d ", current->val);
            enqueue(q, current->left);
            enqueue(q, current->right);
        }
        else
        {
            printf("null ");
        }
    }
    printf("\n");
}

int main()
{

    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};
    int size = 5;

    struct TreeNode *root = buildTree(inorder, size, postorder, size);

    printf("Tree Reconstructed! Level Order Output:\n");
    printLevelOrder(root);

    return 0;
}