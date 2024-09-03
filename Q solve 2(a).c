#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

void insertItem(struct Node** head, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = temp;
}

void insertAtBeginning(struct Node** head, int data) {
    printf("Inserting %d at the beginning\n", data);
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;

    if (*head != NULL) {
        temp->next = *head;
        *head = temp;
        return;
    }
    *head = temp;
}
void insertAtEnd(struct Node** head, int data) {
    printf("Inserting %d at the end\n", data);
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = temp;
}
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    int currentPosition = 1;
    struct Node* curr = *head;
    while (currentPosition < position && curr != NULL) {
        curr = curr->next;
        currentPosition++;
    }

    if (position == 0) {
        temp->next = *head;
        *head = temp;
    } else if (curr != NULL) {
        temp->next = curr->next;
        curr->next = temp;
    } else {
        printf("Invalid position\n");
        free(temp); // free memory allocated for temp node
    }
}
void printLinkedList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

int main() {
    struct Node* head = NULL;
    insertItem(&head, 20);
    insertItem(&head, 30);
    printf("Initial linked list: ");
    printLinkedList(head);

    insertAtBeginning(&head, 10);
    printf("Current elements: ");
    printLinkedList(head);

    insertAtEnd(&head, 50);
    printf("Current elements: ");
    printLinkedList(head);

    insertAtPosition(&head, 40, 3);
    printf("Current elements: ");
    printLinkedList(head);--
    return 0;
}

