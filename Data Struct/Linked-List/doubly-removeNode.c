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

void deleteNode(int loca){
    // delete node
    struct node *temp=head; 
    struct node *prevtemp=head;

    if(loca == 1 ){
        head = prevtemp -> next;
    } else {
        while(loca != 1){
            prevtemp=temp;
            temp = temp->next;
            loca = loca - 1;
        }
        prevtemp -> next = temp -> next;
    }


}



void printNode(){

    printf("Output from Head\n ");
    while(head!=NULL){
        printf("%d", head->data);
        head = head->next;
    }

    printf("\n\n");

    printf("Output from tail\n ");
    while(tail!=NULL){
        printf("%d", tail->data);
        tail = tail->prev;
    }
}

int main(){

    int numNode;
    printf("Enter Num Node: ");
    scanf("%d", &numNode);


    int nodeData;
    for(int x=0; x < numNode; x++){
        printf("Enter Number Node [%d] = ", x+1);
        scanf("%d", &nodeData);

        addNode(nodeData);
    }

    deleteNode(1);
     
    printNode();

}