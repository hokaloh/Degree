#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void queue(struct node **head, int value){
    struct node *newnode;
    newnode= malloc(sizeof(struct node));

    newnode->data=value;
    newnode->next=NULL;

    if(*head==NULL){
        // sekirang head kosong, letak pointer newnode ke newnode 
        *head = newnode;
    } else {
        // buat satu pointer untuk pegang belakang sekali // kita loop untuk tahu 
        struct node *tail=*head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        // masukkan node baru ke head yang kat belakang 
        tail->next = newnode;
    }
}

void dequeue(struct node **head){
    struct node *temp=*head;
    // alihkan head first ke second node
    *head = (*head) -> next;
    free(temp);  
}

void printlist(struct node *head){
    // gantikan head ke temp // untuk print dalam nih  
    struct node *temp = head; 
    // just print head dan next ke pointer seterusnya sampai next itu NULL 
    while(temp!=NULL){
        printf("\n%d", temp->data);
        temp = temp->next;
    }
}

int main(){
    struct node *head=NULL;
    queue(&head, 1);
    queue(&head, 2);
    queue(&head, 3);
    dequeue(&head);
    printlist(head);

    
}