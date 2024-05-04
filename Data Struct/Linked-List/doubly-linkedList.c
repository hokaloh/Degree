#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
}*head=NULL, *tail=NULL;

void addNode(int value){
    struct node *newNode; 
    newNode = malloc(sizeof(struct node));

    newNode -> prev = NULL;
    newNode -> data = value;
    newNode -> next = NULL; 
    
    if(head==NULL){
        head=newNode;
        tail=newNode;    
    } else {
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    }
}


void printNode(){

    printf("Output from Head\n");
    while(head!=NULL){
        printf("%d", head->data);
        head = head->next;
    }

    printf("\n\n");

    printf("Output from tail\n");
    while(tail!=NULL){
        printf("%d", tail->data);
        tail = tail->prev;
    }
}

int main(){
    addNode(10);
    addNode(20);
    addNode(30);
    printNode();

}

