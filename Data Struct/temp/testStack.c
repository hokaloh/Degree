#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev; 
}*top=NULL;

void push(int value){
     struct node *newNode = NULL;
     newNode = malloc(sizeof(struct node));

     newNode->data = value;

     newNode -> prev = top;
     top = newNode;
}

void pop(){
    if(top == NULL){
        printf("Stack is UnderFlow");
    }
    top = top -> prev;
}

void printStack(){
    struct node *temp = NULL;
    temp = top;
    
    while(temp!=NULL){
        printf("%d",temp->data);
        temp = temp->prev;
    }
}

int main(){
    push(3);
    push(4);
    push(5);
    pop();
    printStack();

}