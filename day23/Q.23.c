#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new dynamically allocated node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1); 
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the end of the list efficiently
struct Node* appendNode(struct Node* tail, int data, struct Node** head) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return newNode;
    }
    tail->next = newNode;
    return newNode;
}

// Function to merge two sorted linked lists
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    // A dummy node makes handling the head of the merged list much easier
    struct Node dummy; 
    dummy.next = NULL;
    struct Node* tail = &dummy;

    // Traverse both lists while neither is empty
    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next; // Move the tail pointer forward
    }

    // If one of the lists still has elements, append the rest of it
    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    // The actual merged list starts at dummy.next
    return dummy.next;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, m, val;

    // 1. Read and build the first linked list
    if (scanf("%d", &n) != 1) return 0;
    struct Node* head1 = NULL;
    struct Node* tail1 = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        tail1 = appendNode(tail1, val, &head1);
    }

    // 2. Read and build the second linked list
    if (scanf("%d", &m) != 1) return 0;
    struct Node* head2 = NULL;
    struct Node* tail2 = NULL;
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        tail2 = appendNode(tail2, val, &head2);
    }

    // 3. Merge the two lists
    struct Node* mergedHead = mergeSortedLists(head1, head2);

    // 4. Print the result
    printList(mergedHead);

    return 0;
}