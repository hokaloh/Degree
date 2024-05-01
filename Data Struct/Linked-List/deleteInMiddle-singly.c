#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *next;
}Nodee;

Nodee *newNode (int data){
    Nodee *temp = malloc(sizeof(struct node));
    temp -> data = data;
    temp -> next = NULL;
    return temp;
}

// count the node that existing
int countNode(Nodee *head){

    int count = 0;
    while(head != NULL){
        head = head->next;
        count++;
    }
    return count;
}

Nodee deleteMiddle(Nodee *head){

    int count = countNode(head);
    int mid = count / 2;

    // delete the node in middle
    while(mid --> 1){
        head = head->next;
    }
    head->next= head->next->next;

}

void printLink (Nodee *head){

    while (head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }

}



int main(){

    //Input Already 
    Nodee *head = newNode(1);
    head -> next = newNode(2);
    head -> next -> next = newNode(3);
    head -> next -> next -> next = newNode(4);

    //printf("node count = %d", countLink(head));

    printf("Nodes Before Delete In The Middle\n");
    printLink(head);

    printf("\nDelete Nodes in the Middle \n"); 
    
    deleteMiddle(head);
    printLink(head);

}