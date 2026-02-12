#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

bool isPalindrome(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;
    Node *temp;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;

        temp = slow;
        slow = slow->next;
        temp->next = prev;
        prev = temp;
    }

    if (fast != NULL)
    {
        slow = slow->next;
    }

    while (prev != NULL && slow != NULL)
    {
        if (prev->data != slow->data)
        {
            return false;
        }
        prev = prev->next;
        slow = slow->next;
    }

    return true;
}

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main()
{
    Node *head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(2);
    head1->next->next->next = createNode(1);

    printf("Test 1 (1->2->2->1): %s\n", isPalindrome(head1) ? "Palindrome" : "Not Palindrome");

    Node *head2 = createNode(1);
    head2->next = createNode(2);
    head2->next->next = createNode(3);
    head2->next->next->next = createNode(2);
    head2->next->next->next->next = createNode(1);

    printf("Test 2 (1->2->3->2->1): %s\n", isPalindrome(head2) ? "Palindrome" : "Not Palindrome");

    Node *head3 = createNode(1);
    head3->next = createNode(2);
    head3->next->next = createNode(3);

    printf("Test 3 (1->2->3): %s\n", isPalindrome(head3) ? "Palindrome" : "Not Palindrome");

    return 0;
}