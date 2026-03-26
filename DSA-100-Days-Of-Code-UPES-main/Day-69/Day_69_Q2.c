#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node
{
    int target;
    int weight;
    struct Node *next;
} Node;

typedef struct
{
    int node;
    int dist;
} HeapNode;

typedef struct
{
    HeapNode *data;
    int size;
} MinHeap;

void swap(HeapNode *a, HeapNode *b)
{
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap *h, int node, int dist)
{
    int i = h->size++;
    h->data[i] = (HeapNode){node, dist};
    while (i != 0 && h->data[i].dist < h->data[(i - 1) / 2].dist)
    {
        swap(&h->data[i], &h->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

HeapNode pop(MinHeap *h)
{
    HeapNode root = h->data[0];
    h->data[0] = h->data[--h->size];
    int i = 0;
    while (2 * i + 1 < h->size)
    {
        int smallest = 2 * i + 1;
        if (smallest + 1 < h->size && h->data[smallest + 1].dist < h->data[smallest].dist)
            smallest++;
        if (h->data[i].dist <= h->data[smallest].dist)
            break;
        swap(&h->data[i], &h->data[smallest]);
        i = smallest;
    }
    return root;
}

int networkDelayTime(int **times, int timesSize, int *timesColSize, int n, int k)
{
    Node **adj = (Node **)calloc(n + 1, sizeof(Node *));
    for (int i = 0; i < timesSize; i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->target = times[i][1];
        newNode->weight = times[i][2];
        newNode->next = adj[times[i][0]];
        adj[times[i][0]] = newNode;
    }

    int *dist = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;
    dist[k] = 0;

    MinHeap *pq = (MinHeap *)malloc(sizeof(MinHeap));
    pq->data = (HeapNode *)malloc(timesSize * 10 * sizeof(HeapNode));
    pq->size = 0;

    push(pq, k, 0);

    while (pq->size > 0)
    {
        HeapNode curr = pop(pq);
        int u = curr.node;

        if (curr.dist > dist[u])
            continue;

        Node *temp = adj[u];
        while (temp)
        {
            int v = temp->target;
            int w = temp->weight;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                push(pq, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    int maxTime = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INT_MAX)
        {
            maxTime = -1;
            break;
        }
        if (dist[i] > maxTime)
            maxTime = dist[i];
    }

    for (int i = 1; i <= n; i++)
    {
        Node *curr = adj[i];
        while (curr)
        {
            Node *toFree = curr;
            curr = curr->next;
            free(toFree);
        }
    }
    free(adj);
    free(dist);
    free(pq->data);
    free(pq);

    return maxTime;
}