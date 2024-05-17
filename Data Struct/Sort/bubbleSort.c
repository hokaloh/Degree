#include <stdio.h>
#include <stdlib.h>


void outputBubbleSort(int arr[],int length){

    printf("\nBubble Sort:");
    for(int i=0; i < length;i++){
        printf("\narry [%d] = %d", i,arr[i]);
    }
}

void bubbleSort(int arr[], int length){

    for(int i=0;i <length;i++){
        //
        for(int j=0;j<length-1-i;j++){
            //
            if(arr[j] > arr[j+1]){
                //
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
            }
        }
    }

    //Output
    outputBubbleSort(arr,length);
}

int main(){
    int arr[] = {70,60,30,20,23,38};
    int length = sizeof(arr) / sizeof(arr[0]);


    bubbleSort(arr,length);
}