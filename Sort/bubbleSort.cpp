#include<bits/stdc++.h>

using namespace std;


bool isSwap = true;
int swapTime = 0;

void swap(int* x, int* y){
    swapTime++;
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[], int n){
    int curr;
    while(isSwap==true){
        for (curr=0; curr<n-1; curr++){
            if (arr[curr]>arr[curr+1]){
                swap(&arr[curr], &arr[curr+1]);
            }
        }
        if (swapTime == 0){
            isSwap = false;
        }
        swapTime = 0;
    }
}

void bubbleSort1(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}


void printArr(int arr[],int n){
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int n = 10;
    int arr[] = {10, 50, 13, 3, 3, 7, 4, 5, 2, 1};
    bubbleSort(arr, n);
    printArr(arr,n);
}


