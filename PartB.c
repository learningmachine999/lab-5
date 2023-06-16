#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void printList(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


struct Node* reverseList(struct Node* current) {
    if (current == NULL || current->next == NULL)
        return current;

    struct Node* nextNode = current->next;
    current->next = NULL;

    struct Node* reversedHead = reverseList(nextNode);
    nextNode->next = current;

    return reversedHead;
}

int main() {
    struct Node* head = NULL;
    int size, data;

    printf("Input list size: ");
    scanf("%d", &size);

    printf("\nInput elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &data);
        insert(&head, data);
    }

    printf("\nThe list:\n");
    printList(head);

    struct Node* reversedHead = reverseList(head);

    printf("\nThe reversed list:\n");
    printList(reversedHead);

    return 0;
}