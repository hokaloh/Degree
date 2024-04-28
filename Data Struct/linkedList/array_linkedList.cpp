#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct myNo{ 	
	int no;  
	struct myNo *next;	
};

int main() {
	int i, total=0;
	int number[11]={12,15,17,3,2,7,10,10,15,15,50};
	
    //convert arry to link list	
	struct myNo *myNoLL, *myNew, *head, *cur, *tail;
	
    head = NULL;
    for(i=0;i < 11; i++){
        myNew =(myNo *) malloc(sizeof(myNo));
        myNew->next = NULL;
        if(head==NULL){
            myNew->no = number[i];
            head=myNew;
            tail=myNew;
        }else{
            myNew->no=  number[i];
            tail->next=myNew;
            tail=myNew;   
        }    
        //total+=number[i];
	    //printf(" %d", number[i]);
	} 
	
	//print link list
    cur=head;
    while(cur != NULL) {
        printf(" %d", cur->no);
        cur=cur->next;
    }
    
    return(0);
}