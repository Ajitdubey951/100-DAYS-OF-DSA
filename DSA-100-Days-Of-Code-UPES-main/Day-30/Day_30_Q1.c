#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coeff;
    int pow;
    struct Node *next;
} Node;

Node *createNode(int coeff, int pow)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

void insert(Node **head, int coeff, int pow)
{
    Node *newNode = createNode(coeff, pow);
    if (*head == NULL || pow > (*head)->pow)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL && temp->next->pow > pow)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void printPolynomial(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%dx^%d ", temp->coeff, temp->pow);
        if (temp->next != NULL)
        {
            printf("+ ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *head3 = NULL;
    int n1, n2;
    int coeff, pow;
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        printf("Enter the coefficient and power of term %d: ", i + 1);
        scanf("%d %d", &coeff, &pow);
        insert(&head1, coeff, pow);
    }
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        printf("Enter the coefficient and power of term %d: ", i + 1);
        scanf("%d %d", &coeff, &pow);
        insert(&head1, coeff, pow);
    }
    printf("First polynomial: ");
    printPolynomial(head1);
    printf("Second polynomial: ");
    printPolynomial(head2);
    return 0;
}