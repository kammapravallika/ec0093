#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    newNode->next = *head;
    *head = newNode;
}

// Insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Delete a node by value
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key not found\n");
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next; // Key is in the first node
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

// Traverse the list forward
void traverseForward(struct Node* head) {
    printf("List (Forward): ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Traverse the list backward
void traverseBackward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    // Move to the last node
    while (head->next != NULL) {
        head = head->next;
    }

    // Traverse backward
    printf("List (Backward): ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->prev;
    }
    printf("NULL\n");
}

// Reverse the doubly linked list
void reverseList(struct Node** head) {
    struct Node* temp = NULL;
    struct Node* current = *head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        *head = temp->prev;
    }
}

// Main function demonstrating applications of a doubly linked list
int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    // Insert nodes at the end
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    printf("After insertions:\n");
    traverseForward(head);
    traverseBackward(head);

    // Delete a node by value
    deleteNode(&head, 20);
    printf("\nAfter deletion of 20:\n");
    traverseForward(head);

    // Reverse the list
    reverseList(&head);
    printf("\nAfter reversing the list:\n");
    traverseForward(head);

    return 0;
}
