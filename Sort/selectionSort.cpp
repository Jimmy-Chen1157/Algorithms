#include<bits/stdc++.h>

using namespace std;

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int arr[], int n){

    int i,j,min_idx;

    for (i=0; i<n-1; i++){
        min_idx = i;
        for (j=i+1; j<n; j++){
            if (arr[j]<arr[min_idx]){
                swap(&arr[j],&arr[min_idx]);
            }
        }
    }
}


void printArr(int arr[],int n){
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int n = 10;
    int arr[] = {10, 12, 8, 3, 6, 7, 4, 5, 2, 1};
    selectionSort(arr, n);
    printArr(arr,n);
}
