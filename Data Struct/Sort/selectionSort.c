#include <stdio.h>
#include <stdlib.h>


void selectionSort(int arr[], int sizearr){
    // loop semua 
    for(int i=0; i<sizearr; i++){
        // kita simpan first iteration index 
        int min = i;
        // loop untuk next iteration 
        for(int j=i+1; j<sizearr; j++){
            // sekiranya value before this 
            if(arr[j] < arr[min]){
                min=j;
            }
            if(min!=i){
                int temp; 
                temp=arr[i];
                arr[i]=arr[min];
                arr[min]=temp;
            }
        }
    }

}



void insertionSort(int arr[], int sizearr){

    // [5,3,4,1]
    // [3,5,4,1]
    // store nextData
    // store prevIndex
    // data prevIndex >  nextData && prevIndex >= 0
    // // prevIndex + 1 =  data prevIndex
    // // prevIndex = prevIndex - 1 // untuk stop 
    // data prevIndex+1 = store data nextData
    int i, key, nextData, prevIndex;
    for(int i=1;i<sizearr;i++){
        nextData = arr[i];
        prevIndex = i-1;

        while(arr[prevIndex] > nextData && prevIndex >= 0){
            arr[prevIndex + 1] = arr[prevIndex];
            prevIndex = prevIndex - 1;
        }
        arr[prevIndex+1] = nextData;
    }
}
void bubbleSort(int arr[], int sizearr){
    // loop by phase
    for(int i=0;i <length;i++){
        // loop by index behind
        for(int j=0;j<length-1-i;j++){
            // condition greater 
            if(arr[j] > arr[j+1]){
                // make variable copy value for first index 
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
            }
        }
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int sizeArr = sizeof(arr)/sizeof(arr[0]);

    //printf("%d", sizeArr);
    //selectionSort(arr, sizeArr);
    insertionSort(arr, sizeArr);
    printArray(arr, sizeArr);
}