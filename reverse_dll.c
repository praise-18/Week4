#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* push(Node* head, int data) {
    Node* newn = (Node*)malloc(sizeof(Node));
    newn->data = data;
    newn->prev = NULL;
    newn->next = head;
    if (head) head->prev = newn;
    return newn;
}

Node* reverseDLL(Node* head) {
    Node *cur = head, *temp = NULL;
    while (cur) {
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        head = cur;
        cur = cur->prev; // because prev and next swapped
    }
    return head;
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
    head = push(head, 5);
    head = push(head, 4);
    head = push(head, 3);
    head = push(head, 2);
    head = push(head, 1);
    printf("Original: ");
    printList(head);
    head = reverseDLL(head);
    printf("Reversed: ");
    printList(head);
    return 0;
}
