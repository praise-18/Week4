#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertIntoCLL(Node* head, int data) {
    Node* newn = (Node*)malloc(sizeof(Node));
    newn->data = data;
    if (!head) {
        newn->next = newn;
        return newn;
    }
    Node* cur = head;
    while (cur->next != head) cur = cur->next;
    cur->next = newn;
    newn->next = head;
    return head;
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
    head = insertIntoCLL(head, 1);
    head = insertIntoCLL(head, 2);
    head = insertIntoCLL(head, 3);
    printf("Circular Linked List: ");
    printCLL(head);
    return 0;
}
