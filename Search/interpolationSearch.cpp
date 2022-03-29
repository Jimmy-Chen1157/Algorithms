#include<bits/stdc++.h>

using namespace std;


int interpolationSearch(int arr[], int n, int x){
    int lo=0, hi=(n-1);

    while(lo<=hi && arr[lo]<=x && arr[hi]>=x){
        if (lo == hi){
            if(arr[lo]==x){
                return lo;
            }
            return -1;
        }

        int pos = lo + ((hi-lo)/(arr[hi]-arr[lo]))*(x-arr[lo]);

        if (arr[pos]==x){
            return pos;
        }

        else if (arr[pos]<x){
            lo = pos+1;
        }

        else if (arr[pos]>x){
            hi = pos-1;
        }
    }
    return -1;
}


int main(){
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21,
                 22, 23, 24, 33, 35, 42, 47};
    int n = sizeof(arr)/sizeof(arr[0]);

    int x = 13;
    cout << interpolationSearch(arr, n, x);
}
