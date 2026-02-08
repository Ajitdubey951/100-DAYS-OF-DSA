#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *deleteFirstOccurrence(struct Node *head, int key)
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }

    if (head->data == key)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node *current = head;
    struct Node *prev = NULL;

    while (current != NULL && current->data != key)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Key %d not found in the list.\n", key);
        return head;
    }

    prev->next = current->next;
    free(current);
    return head;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main()
{
    struct Node *head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);

    printf("Original List:\n");
    printList(head);

    printf("\nDeleting 30...\n");
    head = deleteFirstOccurrence(head, 30);
    printList(head);

    printf("\nDeleting 10...\n");
    head = deleteFirstOccurrence(head, 10);
    printList(head);

    printf("\nDeleting 99...\n");
    head = deleteFirstOccurrence(head, 99);
    printList(head);

    return 0;
}