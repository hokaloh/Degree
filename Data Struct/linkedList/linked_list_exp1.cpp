#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node { 
   int data; 
   struct Node *next; 
}; 
struct Node* head = NULL;  
 
void insert(int new_data) { 
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
   new_node->data = new_data; 
   new_node->next = head; 
   head = new_node; 
} 
void display() { 
   //struct Node* ptr;
   //ptr = head;
   while (head != NULL) { 
      printf ("%d ", head->data); 
      head = head->next; 
   } 
} 
int main() { 
   insert(3);
   insert(1);
   insert(7);
   insert(2);
   insert(9);
   printf ("The linked list is: ");
   display(); 

   return(0);
}