#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
// define size of stack 

//create pointer 'top' to keep track item in stack
int top =-1;

// create variable size stack 
int stack[SIZE];

void push(){
    int input;
    // make condition to identify stack in overflow'full' or not 
    // size - 1 to verify in index 
    if (top == SIZE - 1){
       printf("\nOverflow"); 
    } else {
        printf("Insert Number: ");
        scanf("%d",&input);
        top = top + 1;
        stack[top] = input; 
    }
}

void pop(){
    // identify underflow
    if(top == -1){
        printf("Underflow!");
    } else {
        printf("Delete the element %d", stack[top]);
        //delete index 'track'
        top = top - 1;
    }
}

void show(){
    // identify underflow 
    if(top == -1){
        printf("Underflow!");
    } else {
        for(int x = top; x >= 0; --x){
            printf("%d\n", stack[x]);
        }
    }
}


// push, pop, show

int main(){
    
    while(1){
        
        int choice;

        printf("\nPerform operations on the stack:");
        printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.End");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                show();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice ");
        }


    }

}

