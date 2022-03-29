#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int infinity = numeric_limits<int>::max();

int main(){


    int search;
    cin >> search;

    vector<int> coins = {1,3,5,100};
    int value[search+1];
    int first[search+1];

    value[0] = 0;
    for (int x = 1; x <= search; x++) {
        value[x] = infinity;
        for (auto c:coins){
            if (x-c >= 0 && value[x-c]+1 < value[x]){
                value[x] = value[x-c]+1;
                first[x] = c;
            }
        }
    }

    cout << value[search] << endl;

    while(search > 0){
        cout << first[search] << " ";
        search -= first[search];
    }
}


// solve(x) = {

//    x == 0 --> 0
//    x < 0 --> INF
//    x > 0 --> min(for c in coins) value[x-c]+1

//}
