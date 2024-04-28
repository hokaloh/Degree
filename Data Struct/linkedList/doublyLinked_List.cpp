#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}Node;


void buildNodesLink(int countNodes){

    Node *head = NULL;
    Node *tail = NULL;

    for(int x=0; x < countNodes; x++){
        if(head == NULL){
            Node *nNode;
            nNode = (struct node*)malloc(sizeof(Node));
            nNode->data=1;
            nNode->next=nNode;
            nNode->prev=head;
            head=nNode;
            tail=head;
        }
    }

}

int main(){
    int countNodes;
    printf("how many Nodes: ");
    scanf("%d", &countNodes);

    buildNodesLink(countNodes);




    return 0;
}