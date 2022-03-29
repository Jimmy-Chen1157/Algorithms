#include <vector>
#include <iostream>

using namespace std;

void search(int k, int n, vector<int> arr, vector<int> v){
    int p;
    if (k == n-1){
        for (auto p : v){
            cout << p;
        }
        cout << endl;
    }
    else{
        search(k+1, n, arr, v);
        v.push_back(arr[k]);
        search(k+1, n, arr, v);
        v.pop_back();
    }
}

int main(){
    vector<int> v;
    vector<int> arr = {1,4,2};
    int size = arr.size();
    search(0, size, arr, v);

    return 0;
}
