#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

struct animals{
    struct animals *prev;
    char name[10000];
    struct animals *next;
};

struct animals* swap(struct animals *p1, struct animals *p2) {
    //struct animals* temp = p2->next;
    p1->next = p2->next;
    p2->next = p1;
    return p2;
}

void ascendingAnimals(struct animals **lang) {
    bool swapped;
    do {
        swapped = false;
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
                swapped = true;
            } else {
                prev = current;
                current = current->next;
            }
        }
    } while (swapped);
}

void descendingAnimals(struct animals **lang) {
    bool swapped;
    do {
        swapped = false;
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
                swapped = true;
            } else {
                prev = current;
                current = current->next;
            }
        }
    } while (swapped);
}
struct animals* copyList(struct animals *lang) {
    if (lang == NULL) return NULL;

    struct animals* newHead = malloc(sizeof(struct animals));
    strcpy(newHead->name, lang->name);
    newHead->next = copyList(lang->next);
    return newHead;
}

void displayAnimals(struct animals **lang){

    struct animals *copy = copyList(*lang);  // Create a copy of the list lang

    printf("\nAscending:\n");
    ascendingAnimals(lang);
    struct animals *ascending = *lang;
    while (ascending != NULL) {
        printf("%s ", ascending->name);
        ascending = ascending->next;
    }

    printf("\n");

    printf("Descending:\n");
    descendingAnimals(&copy); 
    struct animals *descending = copy;  
    while (descending != NULL) {
        printf("%s ", descending->name);
        descending = descending->next;
    }
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
        printf("\n\nChoose Selection of Animals: [1]InsertNew [2]Delete [3]search [4]update [5]Display in Sorting [6]Exit\n: ");
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
                printf("\nhere current animal:\n");
                struct animals *print=*lang;
                while (print!=NULL){
                    printf("%s ", print->name);
                    print = print->next;
                };
                int locationAnimal;
                printf("\n\nEnter the number location deleteAnimals: ");
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
            case 6: 
                exit(0);
            default:
                break;
        }
    }

}

int main(){

    char *data[2][15] = {
        {"rabbit", "cow", "bird", "snake", "giraffe", "kangaroo", "goat", "tiger", "crocodile", "bat", "horse", "penguin", "deer", "butterfly", "fish"},
        {"arnab", "lembu", "burung", "ular", "zirafah", "kanggaru", "kambing", "harimau", "buaya", "kelawar", "kuda", "penguin", "rusa", "rama", "ikan"}
    };

    int language;
    printf("Select Language: [1]English [2]Bahasa Malaysia\n: ");
    scanf("%d", &language);
    
    if(language == 1){
        int countData = sizeof(data[0])/sizeof(data[0][0]);
        printf("\n|============================================================================|");
        printf("\n|------------------------------Here Data Exist-------------------------------|\n\n ");
        for(int num=0;num<countData;num++) printf("%s ", data[0][num]); 
        printf("\n|----------------------------------------------------------------------------");

        struct animals *english = NULL;
        // insert data array into linked list  
        for(int num=0;num<countData;num++) insertingAnimal(&english, data[0][num]);

        selectionAnimal(&english);

    } else if (language == 2){
        int countData = sizeof(data[0])/sizeof(data[0][0]);
        printf("\n|============================================================================|");
        printf("\n|------------------------------Here Data Exist-------------------------------|\n\n ");
        for(int num=0;num<countData;num++) printf("%s ", data[1][num]); 
        printf("\n|----------------------------------------------------------------------------");

        struct animals *bahasaMelayu = NULL;
        // insert data array into linked list  
        for(int num=0;num<countData;num++) insertingAnimal(&bahasaMelayu, data[1][num]);

        selectionAnimal(&bahasaMelayu);
 
    }else {
        exit(0);
    }
}