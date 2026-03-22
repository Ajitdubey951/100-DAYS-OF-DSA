#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bfs(int adj[MAX][MAX], int n, int startNode)
{
    int queue[MAX];
    int visited[MAX] = {0};
    int front = 0, rear = 0;

    visited[startNode] = 1;
    queue[rear++] = startNode;

    printf("BFS: ");

    while (front < rear)
    {
        int curr = queue[front++];
        printf("%d ", curr);

        for (int i = 0; i < n; i++)
        {
            if (adj[curr][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

int main()
{
    int n = 6;
    int adj[MAX][MAX] = {{0, 1, 1, 0, 0, 0}, {1, 0, 0, 1, 1, 0}, {1, 0, 0, 0, 0, 1}, {0, 1, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0}};
    bfs(adj, n, 0);

    return 0;
}