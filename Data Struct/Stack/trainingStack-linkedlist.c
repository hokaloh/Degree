#include <stdio.h>
#include <stdlib.h>

// create object and declare pointer globally
struct node{
    int data;
    struct node *next;
} *top = NULL;

void push(int input){
    // - Create a new node
    // - Put address of first node of above linked-list part of new node 
    // - Update top pointer and make it opint to new node of linked-list 

    struct node *new_node = NULL;
    new_node = malloc(sizeof(struct node));
    // identify stack if overflow - but it difficult issue
    if (new_node == NULL){
        printf("Stack Overflow!");
        exit(1) ;
    }

    new_node->data=input;
    //new_node->next=NULL;

    // make new node next link to exist top 
    new_node -> next = top; 
    top = new_node;
}

void pop(){
    if(top == NULL){
        printf("Stack underflow!");
    } else {
        top = top -> next;
    }
}

void show(){
    struct node *temp;
    temp = top;
    while( temp != NULL){
        printf("%d", temp->data);
        temp = temp->next;
    } 
    printf("\n");
}

int main(){
    int choice, input;

    while(1){
        printf("\nPerform operations on the stack:");
        printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.End");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            printf("Insert Number: ");
            scanf("%d",&input);
            push(input);
            break;
        case 2:
            pop();
            break;
        case 3: 
            show();
            break;
        default:
            printf("Invalid Choice!");
            exit(0);
        }
    }
}