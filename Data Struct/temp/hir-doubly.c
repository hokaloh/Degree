#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
}*head = NULL, *tail = NULL;

void atFirst(int dataa){

    struct node *newNode = NULL;
    newNode = malloc(sizeof(struct node));

    newNode->data = dataa;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(head == NULL){
        head = newNode;
    //     tail = newNode;
     } else {
        //newNode =head-> next;
        newNode -> next = head;
        head = newNode;
        
    //     tail -> next = newNode;
    //     newNode -> prev = tail;
    //     tail = newNode; 
    }


}

int main(){
    atFirst(10);
    atFirst(20);
    atFirst(40);
    while(head != NULL){
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n\n");
    while(tail!=NULL){
        printf("%d", tail->data);
        tail = tail->prev;
    }
}