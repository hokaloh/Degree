#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}Node;
//initialize Node
Node *head=NULL, *tail=NULL;

void OperationDoublyLL(int data){
    Node *Nodes;
    if (head==NULL){
        Nodes = (struct node*)malloc(sizeof(Node));
        Nodes->data = data;
        Nodes->next = NULL;
        Nodes->prev = NULL;
        head = Nodes;
        tail = Nodes;
    }else{
        Nodes = (struct node*)malloc(sizeof(Node));
        Nodes -> data = data;
        head -> next = Nodes;
        Nodes -> prev = head;
        head = Nodes; 
    }
    
}
void OuputFromHead(){
    Node *curr;
    curr = head;
    while(head != NULL){
        printf("%d", head->data);
        head = head->next;
    }
}

int main(){
    
    //initialize node
    // Node *head = NULL, *Node1, *Node2, *Node3;

    // head = (struct node*)malloc(sizeof(Node));
    // Node1 = (struct node*)malloc(sizeof(Node));
    // Node2 = (struct node*)malloc(sizeof(Node));
    // Node3 = (struct node*)malloc(sizeof(Node));

    printf("Doubly Linked List\n");
    OperationDoublyLL(5);
    OperationDoublyLL(4);
    OperationDoublyLL(3);
    OperationDoublyLL(2);
    OperationDoublyLL(1);
    OuputFromHead();

    

    

    return 0;
}