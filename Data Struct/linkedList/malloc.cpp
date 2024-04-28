#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


int main(){

    int *ptr; 
    //int array[5];
    //int *memory = (int*)malloc(5*sizeof(int)) 

    //free(ptr);

    ptr = (int *)malloc(4 * sizeof(4));
    printf("%d", sizeof(ptr));

    // if (ptr == NULL){
    //     printf("Memory not allocated");
    // }

    
}