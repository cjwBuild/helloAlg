#include <iostream>
using namespace std;

void swap(int* a,int* b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

//this function rearrange the array
int partition(int arr[], int l , int h){
    int pivot = arr[h];
    int i = (l-1);
    
    for(int j= l;j<=h-1;j++){
        if(arr[j]<=pivot){
            i++;
            swap(&arr[j],&arr[i]);
        }
       
    }
    swap(&arr[i+1],&arr[h]);
    return (i+1);
    
}

void quicksort(int arr[],int l, int h){

    if(l<h){
       
        int pi = partition(arr,l,h);

        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,h);
    }
}

void printArray(int arr[],int size){
    for(int i = 0;i<size;i++){
        printf("%d " , arr[i]);
    }
}

int main(){
    int arr[] = {10,3,6,2,6,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);
    printf("Sorted array: ");
    printArray(arr,n);
    return 0;
}

