#include <iostream>
#include <algorithm>
using namespace std;

bool canSumArrToTarget(int* arr, int size, int target) {
    // create a table
    bool newArr[size + 1][target + 1];
    for (int i = 0; i <= size; i++) {
        newArr[i][0] = true;
    }
    for (int j = 1; j <= target; j++) {
        newArr[0][j] = false;
    }

    for(int i = 1; i <= size; i++) {
        for(int j = 1; j <= target; j++) {
            if(arr[i-1] > j) {
                newArr[i][j] = newArr[i - 1][j];
            } else if(arr[i-1] == j || arr[i-1] * (j / arr[i-1]) == j) {
                newArr[i][j] = true;
            } else if(newArr[i-1][j]) {
                newArr[i][j] = true;
            } else {
                newArr[i][j] = newArr[i - 1][j - arr[i - 1]];
            }
        }
    }

    // cout << "  ";
    // for(int j = 1; j <= target; j++) {
    //     cout << " " << j; 
    // }
    // cout << endl;

    // for(int i = 1; i <= size; i++) {
    //     cout << arr[i-1] << ":";
    //     for(int j = 1; j <= target; j++) {
    //         if(j >= 10) {
    //             cout << " ";
    //         }
    //         cout << " " << newArr[i][j]; 
    //     }
    //     cout << endl;
    // }
    
    return newArr[size][target];
}

int main() {
    int size, target;
    cin >> size >> target;

    int arr[size];
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << (canSumArrToTarget(arr, size, target) == 1 ? "Yes" : "No");
}