#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void insert(int newdata){
    struct node *newnode = (struct node* ) malloc (sizeof(struct node));
    if (newnode == NULL){
        printf("Memory Allocation Error");
    } else {
        newnode->data = newdata;
        newnode->next = NULL;
        if (head == NULL) {
            // If the list is empty, set both head and tail to the new node
            head = newnode;
            tail = newnode;
        } else {
            // Otherwise, link the new node to the end of the list and update tail
            tail->next = newnode;
            tail = newnode;
        }
    }
}

int main(){
    insert(23);
    insert(44);

    struct node *printpointer = (struct node*) malloc (sizeof(struct node));
    printpointer = head;
    while (printpointer != NULL){
        printf("%d", printpointer -> data);
        printpointer = printpointer -> next;
    }
return 0;
}