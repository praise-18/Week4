#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* push(Node* head, int data) {
    Node* newn = (Node*)malloc(sizeof(Node));
    newn->data = data;
    newn->next = head;
    return newn;
}

// Detect cycle using Floyd
int hasCycle(Node* head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return 1;
    }
    return 0;
}

// Check structural circular where traversal returns to head
int isCircularList(Node* head) {
    if (!head) return 1; // empty considered circular here
    Node* cur = head->next;
    while (cur && cur != head) cur = cur->next;
    return (cur == head);
}

int main() {
    Node* head = NULL;
    head = push(head, 3);
    head = push(head, 2);
    head = push(head, 1); // simple list 1->2->3->NULL

    printf("Has cycle? %s\n", hasCycle(head) ? "Yes" : "No");
    printf("Is structurally circular? %s\n", isCircularList(head) ? "Yes" : "No");

    // Make it circular: 3->head
    Node* tail = head;
    while (tail->next) tail = tail->next;
    tail->next = head;

    printf("After making circular:\n");
    printf("Has cycle? %s\n", hasCycle(head) ? "Yes" : "No");
    printf("Is structurally circular? %s\n", isCircularList(head) ? "Yes" : "No");

    return 0;
}
