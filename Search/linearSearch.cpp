#include<iostream>


using namespace std;

int linearSearch(int arr[], int n, int x){
        int i;
        for (i=0;i<n;i++){
            if (arr[i] == x){
                return i;
            }
        }
        return -1;
    }

int main(){

    int arr[] = {3,1,2,6,8};
    int x = 4;
    int n = sizeof(arr)/sizeof(arr[0]);

    int result = linearSearch(arr,n,x);
    cout << result;

}
