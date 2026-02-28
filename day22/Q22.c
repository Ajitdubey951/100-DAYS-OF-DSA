#include <stdio.h>
#include <stdlib.h>

// 1. Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// 2. Function to create a new node in memory
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 3. Function to append a node to the very end of the list
void appendNode(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
    struct Node* last = *head_ref;

    // If the list is empty, make the new node the head
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    // Otherwise, traverse to the last node
    while (last->next != NULL) {
        last = last->next;
    }
    
    // Attach the new node at the end
    last->next = newNode;
}

int main() {
    int n, data;
    struct Node* head = NULL;

    // Read the total number of nodes
    if (scanf("%d", &n) != 1) return 1;

    // Read the integers and append them to the linked list
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &data) != 1) return 1;
        appendNode(&head, data);
    }

    // Traverse the list to print the output and count the nodes
    struct Node* current = head;
    int count = 0;
    
    while (current != NULL) {
        printf("%d ", current->data);
        count++;
        current = current->next;
    }
    printf("\n");
    
    // Optional: Print the count since the problem title asks for it
    // printf("Total nodes: %d\n", count);

    // Free the allocated memory to prevent memory leaks
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}