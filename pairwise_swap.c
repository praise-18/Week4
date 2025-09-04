#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* push(Node* head, int data) {
    Node* newn = (Node*)malloc(sizeof(Node));
    newn->data = data;
    newn->next = head;
    return newn;
}

void pairwiseSwap(Node* head) {
    Node* cur = head;
    while (cur && cur->next) {
        int t = cur->data;
        cur->data = cur->next->data;
        cur->next->data = t;
        cur = cur->next->next;
    }
}

void printList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    for (int i = 5; i >= 1; --i) head = push(head, i); // 1..5
    printf("Original: ");
    printList(head);
    pairwiseSwap(head);
    printf("After pairwise swap: ");
    printList(head);
    return 0;
}
