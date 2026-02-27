#include <stdio.h>
#include <stdlib.h>

/* Define the structure for a linked list node */
struct Node {
    int data;
    struct Node* next;
};

int main() {
    /* Declare ALL variables at the absolute top to avoid C89 compiler errors */
    int n, i, val;
    struct Node *head = NULL;
    struct Node *tail = NULL;
    struct Node *current = NULL;
    struct Node *newNode = NULL;
    struct Node *temp = NULL;

    /* Read the number of elements */
    if (scanf("%d", &n) != 1) {
        return 1;
    }

    /* Step 1: Create the linked list */
    for (i = 0; i < n; i++) {
        scanf("%d", &val);

        /* Allocate memory for the new node */
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        
        newNode->data = val;
        newNode->next = NULL;

        /* Attach node to the list */
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    /* Step 2: Traverse and print the linked list */
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    /* Step 3: Free the allocated memory to prevent memory leaks */
    current = head;
    while (current != NULL) {
        temp = current;             /* Store current node securely */
        current = current->next;    /* Move to the next node before freeing */
        free(temp);                 /* Free the stored node */
    }

    return 0;
}