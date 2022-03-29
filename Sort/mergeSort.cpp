#include <bits/stdc++.h>

using namespace std;

void Merge(int arr[], int l, int mid, int r){
    int subArrayOne = mid - l + 1;
    int subArrayTwo = r - mid;

    int leftArray[subArrayOne],
        rightArray[subArrayTwo];

    for (int i=0; i<subArrayOne; i++){
        leftArray[i] = arr[l + i];
    }
    for (int i=0; i<subArrayTwo; i++){
        rightArray[i] = arr[mid + 1 + i];
    }

    int indexOfSubArrayOne = 0,
        indexOfSubArrayTwo = 0,
        indexOfMergedArray = l;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo){
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]){
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else{
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void MergeSort(int arr[], int l, int r){

    if (l >= r){
        return;
    }

    int mid;
    mid = l + (r-l)/2;
    MergeSort(arr, l, mid);
    MergeSort(arr, mid+1, r);
    Merge(arr, l, mid, r);

}

void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}


int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    auto arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arr_size);

    MergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}


