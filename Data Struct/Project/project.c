#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct animals{
    struct animals *prev;
    char name[10000];
    struct animals *next;
}*head=NULL, *temp=NULL;

int countNode(){
    temp=head;
    int count=0;
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }    
    return count;
}

struct animals ascendingAnimals(int count){
    struct animals ascendingAnimals;

    ascendingAnimals = *head;


    return ascendingAnimals;
}


struct animals descendingAnimals(int count){
    struct animals descendingAnimals;

    descendingAnimals = *head;

    return descendingAnimals;
}

void displayAnimals(){
    printf("Ascending:\n");
    struct animals ascending=ascendingAnimals(countNode());
    

    printf("\nDescending:\n");
    struct animals descending=descendingAnimals(countNode());

} 


void insertingAnimal(char *data){
    
    struct animals *newAnimal;
    newAnimal = malloc(sizeof(struct animals));
    newAnimal->next = NULL;

    if(head == NULL){
        //newAnimal->name = data;
        strcpy(newAnimal->name, data);
        head = newAnimal;
    } else {
        //newAnimal->name = data;
        strcpy(newAnimal->name, data);
        newAnimal->next = head;
        head = newAnimal;
    }

}


int main(){
    //use pointer to avoid waste memory
    // https://www.geeksforgeeks.org/array-of-strings-in-c/
    char *data[] = {"rabbit", "cow", "bird", "snake", "giraffe", "kangaroo", "goat", "tiger", "crocodile", "bat", "horse", "penguin", "deer", "butterfly", "fish"};

    // sizeof(data) is total size of data array in bytes
    // chac is 4 bytes
    int countData = sizeof(data)/sizeof(data[0]);

    for(int x=0;x<countData; x++){
        insertingAnimal(data[x]);
    }
    
    while (head!=NULL)
    {
        printf("%s\n", head->name);
        head = head->next;
    }
    

}