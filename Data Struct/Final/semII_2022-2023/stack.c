# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void push(struct node **head, int value){
    struct node *newnode;
    newnode=malloc(sizeof(struct node));

    if (newnode == NULL){
        printf("Stack Overflow!");
        exit(1) ;
    }

    newnode->data=value;
    // node baru ke pointer head pegang (pointer yg dia pegang sebelum nih)(mula" memang null)
    newnode->next=*head;
    // kita declare node baru ialah head 
    *head=newnode;
}

void pop(struct node **head){
    if(top == NULL){
        printf("Stack Underflow");
    }
    // kita alihkan node yang first head pegang ke second node head pegang 
    
    *head = (*head)->next;
}

void printlist(struct node *head){
    struct node *temp = head; 
    while(temp!=NULL){
        printf("\n%d", temp->data);
        temp = temp->next;
    }
}

int main(){
    struct node *head=NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    pop(&head);
    printlist(head);
}