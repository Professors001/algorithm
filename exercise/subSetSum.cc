#include <iostream>
using namespace std;

bool subSetSum(int* arr, int size, int target) {

    // create a table
    bool newArr[size + 1][target + 1];
    for (int i = 0; i <= size; i++) {
        newArr[i][0] = true;
    }
    for (int j = 0; j <= target; j++) {
        newArr[0][j] = false;
    }

    for(int i = 1; i <= size; i++) {
        for(int j = 1; j <= target; j++) {
            if(arr[i] > j) {
                newArr[i][j] = newArr[i - 1][j];
            } else if(arr[i] == j) {
                newArr[i][j] = true;
            } else {
                newArr[i][j] = newArr[i - 1][j - arr[i - 1]];
            }
        }
    }

    return newArr[size][target];
}


int main() {
    int arr[] = {2, 3, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    bool can_sum = subSetSum(arr, size, target);

    if (can_sum) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}