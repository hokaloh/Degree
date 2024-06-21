#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

struct animals{
    struct animals *prev;
    char name[10000];
    struct animals *next;
}*p1=NULL, *p2=NULL;

struct animals* swap(struct animals *p1, struct animals *p2) {
    //struct animals* temp = p2->next;
    p1->next = p2->next;
    p2->next = p1;
    return p2;
}

void ascendingAnimals(struct animals **lang){
    struct animals *loop=*lang;

    while (loop != NULL) {
        struct animals *current = *lang;
        struct animals *prev = NULL;

        while (current != NULL && current->next != NULL) {
            struct animals *p1 = current;
            struct animals *p2 = current->next;

            if (strcmp(p1->name, p2->name) > 0) {
                if (prev == NULL) {
                    *lang = swap(p1, p2);
                    prev = *lang;
                } else {
                    prev->next = swap(p1, p2);
                    prev = prev->next;
                }
            } else {
                prev = current;
                current = current->next;
            }
        }
        loop = loop->next;
    }
}
void descendingAnimals(struct animals **lang){
    struct animals *loop=*lang;

     while (loop != NULL) {
        struct animals *current = *lang;
        struct animals *prev = NULL;

        while (current != NULL && current->next != NULL) {
            struct animals *p1 = current;
            struct animals *p2 = current->next;

            if (strcmp(p1->name, p2->name) < 0) {
                if (prev == NULL) {
                    *lang = swap(p1, p2);
                    prev = *lang;
                } else {
                    prev->next = swap(p1, p2);
                    prev = prev->next;
                }
            } else {
                prev = current;
                current = current->next;
            }
        }
        loop = loop->next;
    }

}

void displayAnimals(struct animals **lang){

    printf("Ascending:\n");
    ascendingAnimals(lang);
    struct animals *ascending = *lang;
    while (ascending != NULL) {
        printf("%s ", ascending->name);
        ascending = ascending->next;
    }

    // *lang = head;
    
    // printf("\nDescending:\n");
    // descendingAnimals(lang);
    // struct animals *descending = *lang;
    // while (descending != NULL) {
    //     printf("%s ", descending->name);
    //     descending = descending->next;
    // }
} 

char *upperLower(char *animal){
    for(int i = 0; animal[i]; i++){
        animal[i] = tolower(animal[i]);
    }
    return animal;
}

void updateAnimal(struct animals **lang, char *nameAnimal, char *newAnimal){
    struct animals *loop=*lang; 

    int found = 0;
    while (loop != NULL) {
        if (strcmp(loop->name,nameAnimal) == 0) {
            strcpy(loop->name,newAnimal);
            found=1;
        }
        loop = loop->next;
    } 
    if(found==0){
        printf("Record with name '%s' not found.\n", nameAnimal);
    }
}

void searchAnimal(struct animals **lang, char *nameAnimal){
    struct animals *loop=*lang; 

    int index=0;
    int found=0;
    while(loop!=NULL){
        if(strcmp(loop->name,nameAnimal) == 0){
            printf("Record with Name '%s' in index node [%d].\n", nameAnimal, index);
            found=1;
        }
        index++;
        loop = loop->next;
    }
    if(found==0){
        printf("Record with name '%s' not found.\n", nameAnimal);
    }
}

void deleteAnimal(struct animals **lang, int locationNode){
    // delete node animal
    struct animals *temp=*lang; 
    struct animals *prevtemp=*lang;

    if(locationNode == 1 ){
        *lang = prevtemp -> next;
    } else {
        while(locationNode != 1){
            prevtemp=temp;
            temp = temp->next;
            locationNode = locationNode - 1;
        }
        prevtemp -> next = temp -> next;
    }
}

void insertingAnimal(struct animals **lang, char *data){  
    
    struct animals *newAnimal;
    newAnimal = malloc(sizeof(struct animals));
    newAnimal->next = NULL;

    if(lang == NULL){
        //newAnimal->name = data;
        strcpy(newAnimal->name, data);
        *lang = newAnimal;
    } else {
        //newAnimal->name = data;
        strcpy(newAnimal->name, data);
        newAnimal->next = *lang;
        *lang = newAnimal;
    }

}

void selectionAnimal(struct animals **lang){
    int selection;
    while(1) {
        printf("\n\nChoose Selection of Animals: [1]InsertNew [2]Delete [3]search [4]update [5]Display in Sorting\n: ");
        scanf("%d",&selection);

        char nameAnimal[100];
        char newAnimal[100];
        switch(selection){
            case 1:{
                printf("\nEnter the name newAnimals: ");
                scanf("%s", nameAnimal);
                insertingAnimal(lang, nameAnimal);
                break;
            };
            case 2:{
                int locationAnimal;
                printf("\nEnter the number location deleteAnimals: ");
                scanf("%d", &locationAnimal);
                deleteAnimal(lang, locationAnimal);
                break;
            };
            case 3:{
                printf("\nEnter The name of animals: ");
                scanf("%s", &nameAnimal);
                searchAnimal(lang, upperLower(nameAnimal));
                break;
            };
            case 4:{
                printf("\nEnter The name of animals to update: ");
                scanf("%s", &nameAnimal);
                printf("Enter The name of new animals: ");
                scanf("%s", &newAnimal);            
                updateAnimal(lang, upperLower(nameAnimal), upperLower(newAnimal));
                break;
            }
            case 5:
                 
                displayAnimals(lang);
                break;
            default:
                break;
        }
    }

}

int main(){
    //use pointer to avoid waste memory
    // https://www.geeksforgeeks.org/array-of-strings-in-c/

    char *data[2][15] = {
        {"rabbit", "cow", "bird", "snake", "giraffe", "kangaroo", "goat", "tiger", "crocodile", "bat", "horse", "penguin", "deer", "butterfly", "fish"},
        {"arnab", "lembu", "burung", "ular", "zirafah", "kanggaru", "kambing", "harimau", "buaya", "kelawar", "kuda", "penguin", "rusa", "rama", "ikan"}
    };

    // sizeof(data) is total size of data array in bytes
    // chac is 4 bytes

    int language;
    printf("Select Language: [1]English [2]Bahasa Malaysia\n: ");
    scanf("%d", &language);
    
    if(language == 1){
        int countData = sizeof(data[0])/sizeof(data[0][0]);
        for(int num=0;num<countData;num++) printf("%s ", data[0][num]); 

        struct animals *english = NULL;

        for(int num=0;num<countData;num++) insertingAnimal(&english, data[0][num]);

        selectionAnimal(&english);
        
        //print linked list
        struct animals *current = english;

        while(current != NULL){
            printf("%s", current->name);
            current = current->next;
        };
        exit(0);

    } else if (language == 2){
        int countData = sizeof(data[0])/sizeof(data[1][0]);
        for(int num=0;num<countData;num++) printf("%s ", data[1][num]);

        struct animals bahasaMalaysia;
 
    }else {
        exit(0);
    }
    exit(0);

    


    // int count;
    // for(int x=0; x<countData;x++){
    //     count++;
    // }
    // printf("%d", count);

            
    //exit(0);

    //displayAnimals();

}