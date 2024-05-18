#include <stdio.h>
#include <stdlib.h>


void outputBubbleSort(int arr[], int lenght){
    for(int x=0; x<lenght;x++){
        printf("\n%d", arr[x]);
    }
}

void bubbleSort(int arr[], int lenght){
    for(int j=0;j<lenght-1;j++){
        if(arr[j] > arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
    outputBubbleSort(arr, lenght);
}

int main(){
    int arr[] = {5,2,3,4,1};
    // 20 / 4
    int lenght =  sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr,lenght);
}