#include<bits/stdc++.h>

using namespace std;


int ternarySearch(int l, int r, int x, int arr[]){

    int mid1 = l + (r-l)/3;
    int mid2 = mid1 + (r-l)/3;

    if (r>=l){

        if (arr[mid1]==x){
            return mid1;
        }
        else if (arr[mid2]==x){
            return mid2;
        }
        else if (arr[mid2]<x){
            return ternarySearch(mid2+1, r, x, arr);
        }
        else if (arr[mid1]>x){
            return ternarySearch(l, mid1-1, x, arr);
        }
        return ternarySearch(mid1+1,mid2-1,x,arr);
    }
    return -1;
}


int main(){

    int arr[] = {1,4,7,9,10,13,17,23,89};
    int r = sizeof(arr)/sizeof(arr[0])-1;
    int x = 89;
    cout << ternarySearch(0,r,x,arr);
}
