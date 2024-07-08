#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Example of Book details
// Author : Weiss Michelle 
// Publish Date: 2014 
// Title : Data Structures and Algorithm in C++ 
// Edition : 4th ed
// Publication by : Boston: Pearson
// Call Number: QA76.73.C153. W44 2014 
// Manipulation of Books are Insert New Book by Alphabetical Order.


struct book{
    struct book *prev; 
    int bookID;
    char Author[100];
    char Date[100];
    char Title[100];
    char Edition[100];
    char Publication[100];
    char callNumber[100];
    struct book *next;
}*head=NULL,*tail=NULL,*temp=NULL, *prevtemp=NULL;

int countNode(){
    temp=head;
    int count=0;
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }    
    return count;
}

void delete_book(){
    int ID;
    printf("Enter book ID: ");
    scanf("%d", &ID);
    temp = head;

    if(temp->bookID == ID){
        head = temp->next; 
        return;
    }

    while(temp->bookID != ID){
        prevtemp = temp;
        temp = temp->next;
    }

    prevtemp->next = temp->next;
}

struct book* swap(struct book *p1, struct book *p2) {
    //struct animals* temp = p2->next;
    p1->next = p2->next;
    p2->next = p1;
    return p2;
}

void ascendingBook(struct book **book) {
    bool swapped;
    do {
        swapped = false;
        struct animals *current = *book;
        struct animals *prev = NULL;

        while (current != NULL && current->next != NULL) {
            struct animals *p1 = current;
            struct animals *p2 = current->next;

            if (strcmp(p1->name, p2->name) > 0) {
                if (prev == NULL) {
                    *book = swap(p1, p2);
                    prev = *book;
                } else {
                    prev->next = swap(p1, p2);
                    prev = prev->next;
                }
                swapped = true;
            } else {
                prev = current;
                current = current->next;
            }
        }
    } while (swapped);
}


void add_book(){

    struct book *newRecord;
    newRecord = malloc(sizeof(struct book));
    newRecord->prev = NULL;
    newRecord->next = NULL;

    printf("\nEnter Name Author: ");
    scanf("%s", newRecord->Author);
    while (getchar() != '\n');  
    printf("Enter Date: ");
    scanf("%s", newRecord->Date);
    while (getchar() != '\n');  
    printf("Enter Title: ");
    scanf("%s", newRecord->Title);
    while (getchar() != '\n');  
    printf("Enter Edition: ");
    scanf("%s", newRecord->Edition);
    while (getchar() != '\n');  
    printf("Enter Publication: ");
    scanf("%s", newRecord->Publication);
    while (getchar() != '\n');  
    printf("Enter callNumber: ");
    scanf("%s", newRecord->callNumber);
    while (getchar() != '\n');  

    if(head==NULL){
        newRecord->bookID=1;
        head=newRecord;
        tail=newRecord;        
    } else {
        newRecord->bookID=tail->bookID+1;
        tail -> next = newRecord;
        newRecord -> prev = tail;
        tail=newRecord;
    } 
}


void display_record(){
    temp = head;
    prevtemp = tail;
    int choose;
    printf("Choose display from [1]head [2]tail?\n");
    scanf("%d", &choose);

    switch (choose){
    case 1:
        printf("\n***Exist Data OF book***");
        while(temp !=NULL){
            printf("\nFirst Name: %s", temp->Author);
            printf("\nFirst Name: %s", temp->Date);
            printf("\nFirst Name: %s", temp->Title);
            printf("\nFirst Name: %s", temp->Edition);
            printf("\nFirst Name: %s", temp->Publication);
            printf("\nLast Name: %s", temp->callNumber);
            temp = temp -> next;
        }
        break;
    case 2: 
        printf("\n***Exist Data OF book***");
        while(prevtemp !=NULL){
            printf("\nFirst Name: %s", temp->Author);
            printf("\nFirst Name: %s", temp->Date);
            printf("\nFirst Name: %s", temp->Title);
            printf("\nFirst Name: %s", temp->Edition);
            printf("\nFirst Name: %s", temp->Publication);
            printf("\nLast Name: %s", temp->callNumber);
            prevtemp = prevtemp -> prev;
        }
        break;
    default:
        break;
    }
    printf("\n");

}

int main(){
    int menu;
    while(1){
        printf("\n### Doubly Linked List ###");
        printf("\n[1] Create and insert record\n");
        printf("[2] Remove or delete existing record\n");
        printf("[3] Display records\n");
        printf("[4] Count Node\n");
        printf(": ");
        scanf("%d", &menu);
        switch (menu){
            case 1:
                add_book();
                ascendingBook(&head);  
                break;
            case 2: 
                delete_book();
                break;
            case 3: 
                display_record();
                break;
            case 4: 
                printf("%d", countNode());
                break;
            default:
                break;
            }
    } 
}