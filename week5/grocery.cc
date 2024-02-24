#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canSumArrToTarget(vector<int> arr, long size, long target) {
    // create a table
    vector<bool> newVect(target + 1, false);

    newVect[0] = true;

    for(int i = 1; i <= target; i++) {
        for(int j = 0; j < size; j++) {
            long current = arr[j];
            if(i - current >= 0 && newVect[i-current]) {
                newVect[i] = true;
                break;
            }
        }
    }
    
    return newVect[target];
}

int main() {
    long size, target;
    cin >> size >> target;

    vector<int> vect(size, 0);
    for(long i = 0; i < size; i++) {
        cin >> vect[i];
    }

    cout << (canSumArrToTarget(vect, size, target) ? "Yes" : "No");
}