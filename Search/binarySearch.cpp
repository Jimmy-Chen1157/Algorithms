#include<iostream>

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

int binarySearch1(int l,int r,int arr[],int x){
    while(r>=l){
        int m = l+(r-l)/2;
        if (x==arr[m]){
            return m;
        }
        else if (x>arr[m]){
            l = m+1;
        }
        else if (x<arr[m]){
            r = m-1;
        }
    }
    return -1;
}


int main(){
    int arr[] = {1,3,7,9,10,12};
    int x = 10;
    int l = 0;
    int r = (sizeof(arr)/sizeof(arr[0]))-1;

    cout << binarySearch(l,r,arr,x);
}
