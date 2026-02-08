#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *removeElements(struct ListNode *head, int val)
{
    while (head != NULL && head->val == val)
        head = head->next;
    struct ListNode *curr = head;
    struct ListNode *prev = NULL;
    while (curr != NULL)
    {
        if (curr->val == val)
        {
            prev->next = curr->next;
            curr = curr->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}