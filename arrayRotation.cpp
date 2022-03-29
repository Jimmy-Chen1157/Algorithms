#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if (b==0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }
}


void rotateArray(int arr[], int n, int k){

    int temp, i, d, j;
    int numOfSets = gcd(n, k);

    for (i=0; i<numOfSets; i++){
        j = i;
        temp = arr[i];

        while(true){
            d = (j+k)%n;
            if(d==i){
                break;
            }
            arr[j] = arr[d];
            j = d;
        }
        arr[j] = temp;
    }

}

void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}

int main(){

    int k, n;
    int arr[] = {1,2,3,4,5,6,7,8,9};
    n = sizeof(arr)/sizeof(arr[0]);
    k = 3;
    rotateArray(arr, n, k);
    printArray(arr, n);



}
