#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    int node;
    int dist;
} HeapNode;

typedef struct
{
    HeapNode *data;
    int size;
    int capacity;
} MinHeap;

MinHeap *createHeap(int capacity)
{
    MinHeap *h = (MinHeap *)malloc(sizeof(MinHeap));
    h->data = (HeapNode *)malloc(capacity * sizeof(HeapNode));
    h->size = 0;
    h->capacity = capacity;
    return h;
}

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

void dijkstra(int V, int adj[V][V], int src)
{
    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    MinHeap *pq = createHeap(V * V);
    dist[src] = 0;
    push(pq, src, 0);

    while (pq->size > 0)
    {
        HeapNode current = pop(pq);
        int u = current.node;

        if (current.dist > dist[u])
            continue;

        for (int v = 0; v < V; v++)
        {
            if (adj[u][v] != 0)
            {
                if (dist[u] + adj[u][v] < dist[v])
                {
                    dist[v] = dist[u] + adj[u][v];
                    push(pq, v, dist[v]);
                }
            }
        }
    }

    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);

    free(pq->data);
    free(pq);
}

int main()
{
    int V = 5;
    int adj[5][5] = {
        {0, 4, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 2, 0, 5, 0},
        {0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0}};

    dijkstra(V, adj, 0);
    return 0;
}