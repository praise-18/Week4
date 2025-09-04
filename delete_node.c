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

Node* deleteNode(Node* head, Node* del) {
    if (!head || !del) return head;
    if (head == del) head = del->next;
    if (del->next) del->next->prev = del->prev;
    if (del->prev) del->prev->next = del->next;
    free(del);
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
    head = push(head, 1); // list: 1 2 3 4 5

    printf("Original: ");
    printList(head);

    // delete the node containing 3 (find it)
    Node* cur = head;
    while (cur && cur->data != 3) cur = cur->next;
    head = deleteNode(head, cur);

    printf("After deleting 3: ");
    printList(head);

    // delete head
    head = deleteNode(head, head);
    printf("After deleting head: ");
    printList(head);

    return 0;
}
