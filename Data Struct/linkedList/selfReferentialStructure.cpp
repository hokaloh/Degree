#include <stdio.h>
#include <string.h>

typedef struct node {
    char data;
    int num; 
    struct node *next;
}Nodes;


int main(){
    
    // initialize node
    Nodes node1;
    Nodes node2;

    // insert data 
    node1.data = 'a';
    node2.data = 'b';

    // link 
    node1.next = &node2;
    node2.next = NULL;


    printf("%c", node1.next->data);


}