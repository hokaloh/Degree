#include <stdio.h>
#include <stdlib.h>

// create object 
// initialize object 
// allocate memory 
// assign data value
// connect node
// decision head 

// 

// create object
struct Node {
    int Data;
    struct Node *next;
};

void printLinkedList(struct Node *head){
    while (head != NULL){
        printf("%d\n", head->Data);
        head = head->next;
    } 
}

int main(){
    
    // initialize object 
    struct Node *head = NULL;
    struct Node *first = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    // allocate memory 
    first = malloc(sizeof(struct Node));
    second = malloc(sizeof(struct Node));
    third = malloc(sizeof(struct Node));

    //assign data value
    first->Data = 10; 
    second->Data = 20;
    third->Data = 30;

    //connect node
    first->next = second;
    second->next = third;
    third->next = NULL;

    // decision head
    head = first;

    printLinkedList(head);







}
