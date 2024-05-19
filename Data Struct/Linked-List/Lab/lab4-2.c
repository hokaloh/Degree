#include <stdio.h>
#include <stdlib.h>

struct employee{
    struct employee *prev; 
    int employeeID;
    char firstName[100];
    char lastName[100];
    int age;
    float salary;
    struct employee *next;
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

void delete_Employee(){
    int ID;
    printf("Enter Employee ID: ");
    scanf("%d", &ID);
    temp = head;

    if(temp->employeeID == ID){
        head = temp->next; 
        return;
    }

    while(temp->employeeID != ID){
        prevtemp = temp;
        temp = temp->next;
    }

    prevtemp->next = temp->next;
}


void add_Employee(){

    struct employee *newRecord;
    newRecord = malloc(sizeof(struct employee));
    newRecord->prev = NULL;
    newRecord->next = NULL;

    printf("\nEnter First Name: ");
    scanf("%s", newRecord->firstName);
    printf("Enter Last Name: ");
    scanf("%s", newRecord->lastName);
    printf("Enter age: ");
    scanf("%d", &newRecord->age);
    printf("Enter Salary: ");
    scanf("%f", &newRecord->salary);

    if(head==NULL){
        newRecord->employeeID=1;
        head=newRecord;
        tail=newRecord;        
    } else {
        newRecord->employeeID=tail->employeeID+1;
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
        printf("\n***Exist Data OF Employee***");
        while(temp !=NULL){
            printf("\n\nEmployee ID: %d", temp->employeeID);
            printf("\nFirst Name: %s", temp->firstName);
            printf("\nLast Name: %s", temp->lastName);
            printf("\nAge: %d", temp->age);
            printf("\nSalary: %.2f", temp->salary);
            temp = temp -> next;
        }
        break;
    case 2: 
        printf("\n***Exist Data OF Employee***");
        while(prevtemp !=NULL){
            printf("\n\nEmployee ID: %d", prevtemp->employeeID);
            printf("\nFirst Name: %s", prevtemp->firstName);
            printf("\nLast Name: %s", prevtemp->lastName);
            printf("\nAge: %d", prevtemp->age);
            printf("\nSalary: %.2f", prevtemp->salary);
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
        printf("\n### Single Linked List ###");
        printf("\n[1] Create and insert record\n");
        printf("[2] Remove or delete existing record\n");
        printf("[3] Display records\n");
        printf("[4] Count Node\n");
        printf(": ");
        scanf("%d", &menu);
        switch (menu){
            case 1:
                add_Employee();
                break;
            case 2: 
                delete_Employee();
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