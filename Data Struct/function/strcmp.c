#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    char name1[] = "Faiz";
    char name2[] = "Ammar";
    int result;

    // printf("%", name1);
    // exit(0);
    
    int lenght = strlen(name2);

    for(int x=0; x<lenght; x++){
        printf("%d\n", name2[x]);
    }

    // result = strcmp(name1, name2);
    // printf("%d", result);


}