#include <iostream>
using namespace std;

// int mostSumNum(int* arr, int size) {
//     int maxSum = -10^9;
//     for(int i = 0; i < size; i++) {
//         for(int j = size-1; j > i; j--) {
//             int sum = arr[i];
//             for(int k = i+1; k <= j; k++) {
//                 sum += arr[k];
//             }
//             if(sum > maxSum) {
//                 maxSum = sum;
//             }
//         }    
//     }
//     return maxSum;
// }

long mostSumNum(long* arr, long size) {
    long maxSum = arr[0]; 
    long currentSum = arr[0]; 

    for(long i = 1; i < size; i++) {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }
    
    return maxSum;
}

int main() {
    long size;
    cin >> size;

    long arr[size];
    for(long i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << mostSumNum(arr, size) << endl;
    
}