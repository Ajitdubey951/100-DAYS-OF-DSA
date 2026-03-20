#include <stdbool.h>
#include <stdlib.h>

bool canVisitAllRooms(int **rooms, int roomsSize, int *roomsColSize)
{
    bool *visited = (bool *)calloc(roomsSize, sizeof(bool));
    int visitedCount = 0;

    int *stack = (int *)malloc(roomsSize * sizeof(int));
    int top = -1;

    stack[++top] = 0;
    visited[0] = true;
    visitedCount++;

    while (top >= 0)
    {
        int currentRoom = stack[top--];

        for (int i = 0; i < roomsColSize[currentRoom]; i++)
        {
            int key = rooms[currentRoom][i];

            if (!visited[key])
            {
                visited[key] = true;
                visitedCount++;
                stack[++top] = key;

                if (visitedCount == roomsSize)
                {
                    free(visited);
                    free(stack);
                    return true;
                }
            }
        }
    }

    bool result = (visitedCount == roomsSize);
    free(visited);
    free(stack);
    return result;
}