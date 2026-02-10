#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node *insertAtHead(Node *head, int data)
{
    Node *newNode = createNode(data);

    if (head == NULL)
    {
        return newNode;
    }

    newNode->next = head;
    head->prev = newNode;

    return newNode;
}

Node *insertAtTail(Node *head, int data)
{
    Node *newNode = createNode(data);

    if (head == NULL)
    {
        return newNode;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

void printForward(Node *head)
{
    Node *temp = head;
    printf("Forward:  ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void printBackward(Node *head)
{
    if (head == NULL)
        return;

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("Backward: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main()
{
    Node *head = NULL;

    head = insertAtHead(head, 20);
    head = insertAtHead(head, 10);
    head = insertAtTail(head, 30);
    head = insertAtTail(head, 40);

    printForward(head);
    printBackward(head);

    return 0;
}