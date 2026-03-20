#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

typedef struct Graph
{
    int numVertices;
    Node **adjLists;
} Graph;

Node *createNode(int v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph *createGraph(int vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = (Node **)malloc(vertices * sizeof(Node *));
    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(Graph *graph, int u, int v)
{
    Node *newNode = createNode(v);
    newNode->next = graph->adjLists[u];
    graph->adjLists[u] = newNode;

    newNode = createNode(u);
    newNode->next = graph->adjLists[v];
    graph->adjLists[v] = newNode;
}

void printGraph(Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        Node *temp = graph->adjLists[i];
        printf("%d: ", i);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int n, m;
    if (scanf("%d %d", &n, &m) != 2)
        return 0;

    Graph *graph = createGraph(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        if (scanf("%d %d", &u, &v) == 2)
        {
            addEdge(graph, u, v);
        }
    }

    printGraph(graph);

    return 0;
}