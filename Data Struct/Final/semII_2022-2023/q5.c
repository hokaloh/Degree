#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void sortAlgo(int size, int data[]){
    int curr=1,temp,x;

    while (curr < size){
        // a bubble sort
        for (x=0; x < size-curr; x++) { 
            // b
            if (data[x]> data [x+1]){
                // 1- Set temp to data[x]
                temp = data[x];
                // 2-Set data [x+1] to data[x] 
                data[x] = data[x+1];
                // 3-Set data [x+1] to temp;
                data[x+1] = temp;
            }
        }

        // c
        printf("\nData 8d \n", curr);
        for (x=0; x < size; x++){
            printf("%d ", data[x]);
        }
        curr++;
    }
}

int main(){
    int data[]={4,3,1,2};

    int size = sizeof(data) / sizeof(data[0]);

    sortAlgo(size,data);
}