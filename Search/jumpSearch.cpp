#include<bits/stdc++.h>

using namespace std;

int jumpSearch(int arr[], int x, int n){
    int step = sqrt(n);

    int prev = 0;

    while (arr[min(step,n)-1] < x){
        prev = step;
        step += sqrt(n);
        if(prev >= n){
            return -1;
        }
    }

    while(arr[prev]<x){
        prev ++;

        if(prev==min(step,n)){
            return -1;
        }

    }

    if (arr[prev] == x){
            return prev;
        }

    return -1;
}


int main(){
    int arr[] = { 22, 23, 31, 37, 44, 52, 69, 88, 91, 96 };
    int x = 96;
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = jumpSearch(arr, x, n);

    cout << index << endl;
}
