#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int countOccurrences(struct Node *head, int key)
{
    int count = 0;
    struct Node *current = head;

    while (current != NULL)
    {
        if (current->data == key)
        {
            count++;
        }
        current = current->next;
    }

    return count;
}

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
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

int main()
{
    struct Node *head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(10);
    head->next->next->next = createNode(30);
    head->next->next->next->next = createNode(10);
    printf("Our Linked List:\n");
    printList(head);
    int keyToFind = 10;
    int occurrences = countOccurrences(head, keyToFind);
    printf("\nThe number %d appears %d time(s) in the list.\n", keyToFind, occurrences);
    keyToFind = 99;
    occurrences = countOccurrences(head, keyToFind);
    printf("The number %d appears %d time(s) in the list.\n", keyToFind, occurrences);

    return 0;
}