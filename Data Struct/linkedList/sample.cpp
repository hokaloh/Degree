#include <stdio.h>
#include <stdlib.h>

// create Node
struct Node {
    int data;
    struct Node *next;
};

// print the linked list value
void printLinkedlist(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main() {
    //initialize node
    struct Node *head;
    struct Node *one = NULL;
    struct Node *two = NULL;
    struct Node *three = NULL;
    struct Node *four = NULL;

    /* Allocate memory */
    one = malloc(sizeof(struct Node));
    two = malloc(sizeof(struct Node));
    three = malloc(sizeof(struct Node));
    four = malloc(sizeof(struct Node));

    // Assign data values
    one->data = 1;
    two->data = 2;
    three->data = 3;
    four->data = 4;

    // Connect Nodes
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = NULL;

    // Printing node-value
    head = one;
    printLinkedlist(head);

    return 0; // Add return statement
};