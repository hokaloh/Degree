#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *prev;
} *top = NULL;

void push(int value){
	
	struct node *newnode;
	newnode = malloc(sizeof(struct node));
	newnode -> data = value;
	newnode -> prev = top;
	top = top -> prev;
}

void pop(){
	top = top -> prev;
}

void printod(){
    printf("hi");
    struct node *temp;
    temp = top ;
	while(temp){
		printf("%d", temp->data);
		temp = temp -> prev;
	}
}

int main(){
	
	push(3);
	push(4);
	push(5);
	pop();
	printod();
}