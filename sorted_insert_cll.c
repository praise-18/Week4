#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* sortedInsertCLL(Node* head, int data) {
    Node* newn = (Node*)malloc(sizeof(Node));
    newn->data = data;
    if (!head) {
        newn->next = newn;
        return newn;
    }
    Node *cur = head;
    // If new node goes before head (new smallest)
    if (data <= head->data) {
        // find last node
        while (cur->next != head) cur = cur->next;
        cur->next = newn;
        newn->next = head;
        return newn; // new node becomes new head
    } else {
        // find position to insert
        while (cur->next != head && cur->next->data < data) cur = cur->next;
        newn->next = cur->next;
        cur->next = newn;
        return head;
    }
}

void printCLL(Node* head) {
    if (!head) { printf("Empty\n"); return; }
    Node* cur = head;
    do {
        printf("%d ", cur->data);
        cur = cur->next;
    } while (cur != head);
    printf("\n");
}

int main() {
    Node* head = NULL;
    head = sortedInsertCLL(head, 10);
    head = sortedInsertCLL(head, 5);
    head = sortedInsertCLL(head, 20);
    head = sortedInsertCLL(head, 15);
    printf("Sorted circular list: ");
    printCLL(head);
    return 0;
}
