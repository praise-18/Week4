#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* newNode(int d) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = d;
    n->next = NULL;
    return n;
}

int getCount(Node* head) {
    int c = 0;
    while (head) { c++; head = head->next; }
    return c;
}

Node* getIntersection(Node* head1, Node* head2) {
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d = abs(c1 - c2);
    Node *longer = (c1 > c2) ? head1 : head2;
    Node *shorter = (c1 > c2) ? head2 : head1;
    for (int i = 0; i < d; ++i) longer = longer->next;
    while (longer && shorter) {
        if (longer == shorter) return longer;
        longer = longer->next;
        shorter = shorter->next;
    }
    return NULL;
}

void printNode(Node* n) {
    if (n) printf("Intersection at node with data = %d\n", n->data);
    else printf("No intersection\n");
}

int main() {
    // Create two lists that intersect
    Node* head1 = newNode(3);
    head1->next = newNode(6);
    head1->next->next = newNode(9);
    head1->next->next->next = newNode(15);
    head1->next->next->next->next = newNode(30);

    Node* head2 = newNode(10);
    head2->next = head1->next->next->next; // points to node with 15

    Node* inter = getIntersection(head1, head2);
    printNode(inter);
    return 0;
}
