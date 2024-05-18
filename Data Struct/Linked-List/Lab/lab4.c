#include <stdio.h>
#include <stdlib.h>

struct employee{
    int employeeID;
    char firstName[100];
    char lastName[100];
    int age;
    float salary;
    struct employee *next; 
}*head=NULL,*tail=NULL,*temp=NULL, *prevtemp=NULL, *loop=NULL;;

int countNode(){
    temp=head;
    int count=0;
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }    
    return count;
}

void delete_Employee(int ID){
    temp = head;
    prevtemp = head;
    loop=head;
    if(ID == 1){
        head = head->next;
        break;
    } else {
        while(loop!=NULL){
            prev = temp;
            temp = temp->next;
            if(employeeID == ID){
                
            }
            

        }
    }
}

void add_Employee(){
    struct employee *newRecord;
    newRecord = malloc(sizeof(struct employee));
    
    newRecord->next = NULL;

    if(head==NULL){
        newRecord->employeeID=1;
        head=newRecord;
        tail=newRecord;        
    } else {
        newRecord->employeeID=tail->employeeID+1;
        // insert newNode in the begining
        // newRecord -> next = head;
        // head = newRecord;

        //inser newNode in the end
        tail -> next = newRecord;
        tail=newRecord;
    }   
}

int main(){

    for(int x=0; x<6; x++){
        add_Employee();
    }
    int count = countNode();
    printf("\n CountNode: %d",count);


    while(head!=NULL){
        printf("\n%d", head-> employeeID);
        head = head->next;
    }
    

}