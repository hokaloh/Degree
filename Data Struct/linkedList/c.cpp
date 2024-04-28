#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
} Node;

void buildNodesLink(int countNodes){
    Node *head = NULL;
    Node *tail = NULL;

    // Create the first node
    head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    head->next = NULL;
    head->prev = NULL;
    tail = head;

    // Create additional nodes if countNodes > 1
    for(int x = 1; x < countNodes; x++){
        Node *nNode = (Node*)malloc(sizeof(Node));
        nNode->data = x + 1;
        nNode->next = NULL;
        nNode->prev = tail;
        tail->next = nNode;
        tail = nNode;
    }

    // Print the linked list
    printf("Doubly Linked List:\n");
    Node *current = head;
    Node *lak = tail;
    while (lak != NULL) {
        printf("%d ", lak->data);
        lak = lak->prev;
    }
    printf("\n");
}

int main(){
    int countNodes;
    printf("How many Nodes: ");
    scanf("%d", &countNodes);

    buildNodesLink(countNodes);

    return 0;
}