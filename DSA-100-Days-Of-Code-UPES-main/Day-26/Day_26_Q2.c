#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    int size;
} MyLinkedList;

MyLinkedList *myLinkedListCreate()
{
    MyLinkedList *obj = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}
int myLinkedListGet(MyLinkedList *obj, int index)
{
    if (index < 0 || index >= obj->size)
    {
        return -1;
    }

    Node *current = obj->head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }

    return current->val;
}

void myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;

    newNode->next = obj->head;
    obj->head = newNode;

    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList *obj, int val)
{
    if (obj->size == 0)
    {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;

    Node *current = obj->head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val)
{
    if (index > obj->size)
        return;

    if (index == 0)
    {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;

    Node *current = obj->head;
    for (int i = 0; i < index - 1; i++)
    {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index)
{
    if (index < 0 || index >= obj->size)
        return;

    Node *temp;

    if (index == 0)
    {
        temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    }
    else
    {
        Node *current = obj->head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }

        temp = current->next;
        current->next = temp->next;
        free(temp);
    }

    obj->size--;
}

void myLinkedListFree(MyLinkedList *obj)
{
    Node *current = obj->head;
    Node *temp;

    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }

    free(obj);
}