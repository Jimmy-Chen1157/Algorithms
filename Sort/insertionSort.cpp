#include<bits/stdc++.h>

using namespace std;

void insertionSort(int arr[], int n){

    int i, j, key;

    for (int i=1; i<n; i++){
        key = arr[i];
        j = i-1;
        while (j>=0 && key < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

}

void printArr(int arr[],int n){
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){
    int arr[] = {1,4,2,3,5,2,3,73,4,5,6,2,4,567,23,4512,34,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
    printArr(arr, n);
}

