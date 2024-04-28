#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int value;
	struct node *next;
}Node;

void output(Node *p){

	while(p != NULL){
		printf("%d", p->value);
		p = p->next;
	}
}

int main(){

	Node *head = NULL; 
	Node *node1 = NULL;
	Node *node2 = NULL; 
	Node *node3 = NULL;

	head = (Node *)malloc(sizeof head);
	node1 = (Node *)malloc(sizeof node1);
	node2 = (Node *)malloc(sizeof node1);
	node3 = (Node *)malloc(sizeof node1);
	//head = malloc(sizeof(Node));

	node1->value = 1;
	node2->value = 2;
	node3->value = 3;

	head = node1;
	
	node1->next = node2;
	node2->next = node3; 
	node3 -> next = NULL;

	//Node *p = head;
	printf("%d", p);
	//output(head);
	


	
};
