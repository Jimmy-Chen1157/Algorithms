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
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);

}

int kthSmallest(int arr[], int l, int r, int k)
    {
        int pi = partition(l, r, arr);
        while(1){
            if (pi == k-1){
                return arr[pi];
            }
            else if (pi > k-1){
                pi = partition(l, pi-1, arr);
            }
            else if ( pi > k-1 ){
                pi = partition(pi+1, r, arr);
            }
        }

    }

int main(){
    int arr[] = {31,2,5,2,3,61,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int kSmallest;
    kSmallest = kthSmallest(arr, 0, n-1, 5);
    cout << kSmallest;
}
