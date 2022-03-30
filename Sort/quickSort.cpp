#include <bits/stdc++.h>

using namespace std;


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int low, int high, int arr[]){
    int i = low-1, pivot = arr[high];
    for (int j=low; j<high; j++){
        if (arr[j] <= pivot){
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i+1], arr[high]);
    return (i+1);
}

void quickSort(int low, int high, int arr[]){
    int pi;
    if (low<high){
        pi = partition(low, high, arr);
        quickSort(low, pi-1, arr);
        quickSort(pi+1, high, arr);
    }
}

void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}


int main(){
    int arr[] = { 2, 1, 6, 10, 4, 1, 3, 9, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(0, n-1, arr);
    printArray(arr, n);

}
