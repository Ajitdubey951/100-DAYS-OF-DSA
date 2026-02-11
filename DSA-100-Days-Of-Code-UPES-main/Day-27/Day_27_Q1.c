#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node *findIntersectionPoint(Node *head1, Node *head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;

    while (temp1 != temp2)
    {
        if (temp1 == NULL)
        {
            temp1 = head2;
        }
        else
        {
            temp1 = temp1->next;
        }
        if (temp2 == NULL)
        {
            temp2 = head1;
        }
        else
        {
            temp2 = temp2->next;
        }
    }
    return temp1;
}