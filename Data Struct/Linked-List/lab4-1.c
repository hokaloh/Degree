#include <stdio.h>
#include <stdlib.h>

#define maxsize 500

struct employee{
    int employeeID;
    char firstName[100];
    char lastName[100];
    int age;
    float salary;
    struct employee *next; 
}*head=NULL, *tempHead=NULL;

int count(){
    struct employee *loop=NULL;
    loop = head;
    int count=0;
    while(loop!=NULL){
        count++;
    }
    return count;

}

void create_insertRecord(){
    struct employee *newRecord;
    newRecord = malloc(sizeof(struct employee));
    // printf("\nEnter First Name: ");
    // scanf("%s", newRecord->firstName);
    // printf("Enter Last Name: ");
    // scanf("%s", newRecord->lastName);
    printf("Enter age: ");
    scanf("%d", &newRecord->age);
    // printf("Enter Salary: ");
    // scanf("%f", &newRecord->salary);
    newRecord->next=NULL;

    if(head==NULL){
        newRecord->employeeID=1;
        head=newRecord;
    }else{
        newRecord->employeeID=head->employeeID+1;
        head->next = newRecord;
    }
}


void remove_deleteRecord(){
    struct employee *trackRecord=NULL;
    trackRecord = malloc(sizeof(struct employee));

    int deleteID;
    printf("\nDelete Record by ID : ", &deleteID);

    

    tempHead=head;
    trackRecord=head->next;
    // while(tempHead!=NULL){
    //     if(head->employeeID = deleteID){
    //         tempHead = temp
    //     } else{
    //         tempHead = tempHead->next;
    //     }
    // }
}  

void display_record(){
    // while(head!=NULL){
    //     printf("\n%d", head->employeeID);
    //     head =head-> next;
    // };
    struct employee *temp=NULL;
    temp=head;
    for(int x; x<count();x++){
        printf("\n%d", temp->employeeID);
        temp=temp-> next;  
    }
}

int main(){
    int menu;
    while(1){
        printf("\nSingle Linked List\n");
        printf("[1] Create and insert record\n");
        printf("[2] Remove or delete existing record\n");
        printf("[3] Display records\n");
        printf(": ");
        scanf("%d", &menu);
        switch (menu){
            case 1:
                create_insertRecord();
                break;
            case 2: 
                remove_deleteRecord();
                break;
            case 3: 
                display_record();
                break;
            default:
                break;
            }
    }   

}






