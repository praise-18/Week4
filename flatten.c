#include <stdio.h>
#include <stdlib.h>

// Node with 'next' and 'down'
typedef struct Node {
    int data;
    struct Node* next; // right
    struct Node* down; // below
} Node;

Node* newNode(int d) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = d;
    n->next = n->down = NULL;
    return n;
}

// merge two sorted lists using down pointer
Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;
    Node* result;
    if (a->data < b->data) {
        result = a;
        result->down = merge(a->down, b);
    } else {
        result = b;
        result->down = merge(a, b->down);
    }
    result->next = NULL; // ensure next cleared
    return result;
}

// flatten list of lists
Node* flatten(Node* root) {
    if (!root || !root->next) return root;
    root->next = flatten(root->next);
    root = merge(root, root->next);
    return root;
}

void printFlattened(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->down;
    }
    printf("\n");
}

int main() {
    // Example from GfG
    Node* head = newNode(5);
    head->down = newNode(7);
    head->down->down = newNode(8);
    head->down->down->down = newNode(30);

    head->next = newNode(10);
    head->next->down = newNode(20);

    head->next->next = newNode(19);
    head->next->next->down = newNode(22);
    head->next->next->down->down = newNode(50);

    head->next->next->next = newNode(28);
    head->next->next->next->down = newNode(35);
    head->next->next->next->down->down = newNode(40);
    head->next->next->next->down->down->down = newNode(45);

    Node* flat = flatten(head);
    printf("Flattened list: ");
    printFlattened(flat);
    return 0;
}
