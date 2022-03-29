#include<bits/stdc++.h>

using namespace std;

int binarySearch(int l,int r,int arr[],int x){
    int  m = l+(r-l)/2;
    if(r>=l){
        if (x==arr[m]){
            return m;
        }
        else if (x>arr[m]){
            return binarySearch(m+1,r,arr,x);
        }
        else if (x<arr[m]){
            return binarySearch(l,m-1,arr,x);
        }

    }
    return -1;
}


int exponentialSearch(int n, int x, int arr[]){
    
    if (arr[0]==x){
        return 0;
    }

    int i = 1;
    while(i<n && arr[i]<=x){
        i *= 2;
    }

    return binarySearch(i/2,min(i,n-1),arr,x);

}

int main(){

    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int x = 10;
    cout << exponentialSearch(n, x, arr);
}
