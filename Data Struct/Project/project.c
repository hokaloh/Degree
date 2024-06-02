#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct animals{
    struct animals *prev;
    char name[10000];
    struct animals *next;
}*head=NULL, *temp=NULL, *p1=NULL, *p2=NULL;

int countNode(){
    temp=head;
    int count=0;
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }    
    return count;
}

struct animals* swap(struct animals *p1, struct animals *p2) {
    struct animals* temp = p2->next;
    p2->next = p1;
    p1->next = temp;
    return p2;
}

// struct animals ascendingAnimals(int count){
//     struct animals ascendingAnimals; 

//     // https://www.ascii-code.com

//     for(int x=0;x<count;x++){

//         ascendingAnimals = *head;

//         for(int y=0;y<count-x-1;y++){
        
//             p1 = head;
//             p2 = p1->next;

//             if(p1->name[y] > p2 -> name[y]){
//                 ascendingAnimals = swap(p1,p2);
//             }

//             ascendingAnimals = ascendingAnimals->next;
//         }
//     }



//     return ascendingAnimals;
// }

struct animals* ascendingAnimals() {
    int count = countNode();

    // if (head == NULL || count < 2) {
    //     return head;
    // }
    for (int x = 0; x < count; x++) {
        struct animals* current = head;
        struct animals* prev = NULL;

        
        while (current != NULL && current->next != NULL) {
            struct animals* p1 = current;
            struct animals* p2 = current->next;

            if (strcmp(p1->name, p2->name) > 0) {
                if (prev == NULL) {
                    head = swap(p1, p2);
                    prev = head;
                } else {
                    prev->next = swap(p1, p2);
                    prev = prev->next;
                }

            } else {
                prev = current;
                current = current->next;
            }
            //kira++;
        }
    }


    return head;
}


struct animals descendingAnimals(int count){
    struct animals descendingAnimals;

    descendingAnimals = *head;

    return descendingAnimals;
}

void displayAnimals(){
    printf("Ascending:\n");
    
    struct animals *ascending = ascendingAnimals();

    while (ascending != NULL) {
        printf("%s\n", ascending->name);
        ascending = ascending->next;
    }
    exit(0);

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
    //char *data[] = {"rabbit", "cow", "bird", "snake", "giraffe", "kangaroo", "goat", "tiger", "crocodile", "bat", "horse", "penguin", "deer", "butterfly", "fish"};

    char *data[] = {"Faiz", "Ammar", "Yus", "Kamal", "Abu Bakar"};

    // sizeof(data) is total size of data array in bytes
    // chac is 4 bytes
    int countData = sizeof(data)/sizeof(data[0]);

    for(int x=0;x<countData; x++){
        insertingAnimal(data[x]);
    }

    displayAnimals();

    // temp=head;

    // if(temp->name[0] > head->next->name[0] ){
    //     printf("%c", head->next->name[0]);
    // }

    //fish 13010820 102
    //butterfly 12542060  98
    //deer 12269900
        
        
    exit(0);
    

    // for(int x;x<countNode();x++){
    //     for()
    // }
    

}