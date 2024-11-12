#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void insertingSort(int arr[], int sizearr){
    for(int i=1;i<sizearr;i++){
        int temp=arr[i];
        int j=i-1;

        while(j>=0 && arr[j] >temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void selectionSort(int arr[], int sizearr) {
    for(int i=0;i<sizearr; i++){
        int min=i;
        for(int j=i+1;j<sizearr;j++){
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        if(min!=i){
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
}

int main(){
    int arr[] = {8,7,9,2,3,1,5,4,6,10};

    int sizearr = sizeof(arr)/sizeof(arr[0]);

    insertingSort(arr, sizearr);

    for(int i=0;i<sizearr;i++){
        printf("%d", arr[i]);
    }
}