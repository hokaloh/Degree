#include <stdio.h>
#include <conio.h>

#define size 5

struct Stack{
	int top;
	int data[size];
};

typedef struct Stack stack;

void createStack(stack *S);
void menu();
int empty(stack *S);
int full(stack *S);
void push(stack *S);
void pop(stack *S);
void display(stack *St);

int main(){
	
	stack s,s1;
	int choice=0;
	
createStack(&s);

while(choice !=4){
	menu();
	scanf("%d",&choice);
	
	switch(choice){
			case 1: 	printf("\nPush the stack >> ");
					 	push(&s);
					  	break;
			
			case 2 : 	printf("\nPop the stack");
						pop(&s);
						break;
						
			case 3 :	
						s1=s;
						display(&s1);
						break;
			
			case 4 :	printf("\nExit stack menu ");
						break;
						
			default	 :	printf("\n<< Invalid entry, Please select 1,2,3 or 4 >>\n")	;	
	
	}
}
	
}

void createStack(stack *S)
{
	S->top= -1;
}

void menu(){
		printf("\n\n[----- Stack Menu -----]");
		printf("\n1 : Push Stack");
		printf("\n2 : Pop Stack");
		printf("\n3 : Display Stack");
		printf("\n4 : Exit Menu");
		printf("\n\n[----------------------]");
		printf("\nPlease enter choice >> ");
		
}

int empty(stack *S)
{
	if(S->top == -1)
	return (1);
	else
	return (0);
}

int full(stack *S){
	if(S->top ==size-1)
	return (1);
	else
	return (0);
}

void push(stack *S){
	int value;
	
	if(full(S)==1){
	   printf("\n!! Stack OVERFLOW - can't push stack !!!!'");
    }
	else{
		printf("\nEnter integer value into stack >> ");
    	scanf("%d",&value);
		S->top++;
		S->data[S->top]=value;
		
	}
}

void pop(stack *S){
	if(empty(S)==1)
	{
			printf("\n!!! Stack UNDERFLOW - can't pop stack !!!'");
	}
	else
	{	
		S->data[S->top]=0;
		S->top--;
	}
}

void display(stack *St){
	if(empty(St)==1){
		printf("\n!!! Stack UNDERFLOW - no data !!!'");

	}else{	
        int temp= St->top;
        
        for (temp=St->top; temp>-1; temp--){
            printf("\n%d -->  %d",temp, St->data[temp]);
        }
        St->top=0;
    }
}