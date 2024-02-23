#include <iostream>
#include <algorithm>
using namespace std;

bool canSumArrToTarget(long* arr, long size, long target) {
    // create a table
    bool newArr[target + 1];

    fill(newArr, newArr+target, false);

    newArr[0] = true;

    for (int i = 0; i < size; i++) {
        int current = arr[i];
        for (int j = target; j >= current; j--) {
            if (j == current || j % current == 0) {
                newArr[j] = true;
            } else {
                newArr[j] = newArr[j] || newArr[j - current];
            }
        }
    }

    return newArr[target];
}

int main() {
    long size, target;
    cin >> size >> target;

    long arr[size];
    for(long i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << (canSumArrToTarget(arr, size, target) == 1 ? "Yes" : "No");
}