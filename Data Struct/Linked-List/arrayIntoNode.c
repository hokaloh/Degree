#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Nodee;

void printNode(Nodee *head){
    
    // print from head
    printf("Node from Head : ");
    while(head != NULL){
        printf("%d", head->data);
        head = head -> next;
    }

    // print from tail
}

int main(){

    int arraySize;
    
    printf("How Many Array ? : ");
    scanf("%d",&arraySize);

    int array[arraySize];

    for(int x = 0; x<arraySize; x++){
        printf("element value [%d]: ",x+1);
        scanf("%d", &array[x]);
    }    

    /////////////////////////////////////////////////////

    Nodee *head = NULL, *tail=NULL;

    for(int i=0;i<arraySize; i++){
        Nodee *newNode = NULL;
        newNode = malloc(sizeof(struct node));
        newNode->next = NULL;

        newNode -> data = array[i];
        
        if(head == NULL){
            newNode -> data = array[i];
            head 
        }

    }

    printNode(head);

    
}