#include <iostream>
#include <vector>



using namespace std;

int main(){
    vector<int> array = {-1,2,4-3,5,2,-5,2};


    int best = 0;
    int sum = 0;
    int n = array.size();

    for (int i = 0; i < n; i++){
        sum = max(sum+array[i],array[i]);
        best = max(best, sum);
    }

    cout << best;

    return 0;
}


// max_last_array + current_index
