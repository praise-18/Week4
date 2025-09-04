#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* insertAtBeginning(Node* head, int data) {
    Node* newn = (Node*)malloc(sizeof(Node));
    newn->data = data;
    newn->prev = NULL;
    newn->next = head;
    if (head) head->prev = newn;
    return newn;
}

void printList(Node* head) {
    Node* cur = head;
    while (cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 10);
    printf("Doubly linked list after inserts at beginning: ");
    printList(head);
    return 0;
}
