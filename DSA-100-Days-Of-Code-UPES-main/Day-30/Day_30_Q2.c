#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *createNode(int value)
{
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

struct ListNode *insertEnd(struct ListNode *head, int value)
{
    struct ListNode *newNode = createNode(value);

    if (head == NULL)
        return newNode;

    struct ListNode *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *dummy = createNode(0);
    struct ListNode *current = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int sum = carry;

        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        current->next = createNode(sum % 10);
        current = current->next;
    }

    return dummy->next;
}

void printList(struct ListNode *head)
{
    printf("Result Linked List: ");
    while (head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    int n1, n2, value;
    struct ListNode *l1 = NULL;
    struct ListNode *l2 = NULL;
    struct ListNode *result = NULL;

    printf("Enter number of elements in first list: ");
    scanf("%d", &n1);
    printf("Enter elements of first list: ");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &value);
        l1 = insertEnd(l1, value);
    }
    printf("Enter number of elements in second list: ");
    scanf("%d", &n2);
    printf("Enter elements of second list: ");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &value);
        l2 = insertEnd(l2, value);
    }

    result = addTwoNumbers(l1, l2);

    printList(result);

    return 0;
}

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *prev = NULL;
    struct ListNode *current = head;
    struct ListNode *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    l1 = reverseList(l1);
    l2 = reverseList(l2);

    struct ListNode *resultHead = NULL;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int sum = carry;

        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = resultHead;
        resultHead = newNode;
    }

    return resultHead;
}