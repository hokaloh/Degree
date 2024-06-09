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

struct animals* ascendingAnimals() {
    int count = countNode();

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
    printf("\n\nChoose Selection of Animals: [1]InsertNew [2]Delete [3]search [4]update [5]Display in Sorting");
    scanf("%d",&selection);

    switch(selection){
        case 1:{
            char animal[100];
            printf("\nEnter the name newAnimals: ");
            scanf("%s", animal);
            insertingAnimal(lang, animal);
            break;
        };
        case 2:{
            int locationAnimal;
            printf("\nEnter the number location deleteAnimals: ");
            scanf("%d", &locationAnimal);
            deleteAnimal(lang, locationAnimal);
            break;
        };
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
        for(int num=0;num<countData;num++) printf("%s, ", data[0][num]); 

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

    displayAnimals();

}