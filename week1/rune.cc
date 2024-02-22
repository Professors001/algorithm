#include <iostream>
#include <algorithm>

using namespace std;

int sumByOrder(int* arr, int size, int k, bool reverse_order) {
    int sum = 0;
    for(int i = 0; i < k; i++) {
        if(reverse_order) {
            sum += arr[i];
        } else {
            sum += arr[size-i-1];
        }           
    }
    return sum;
}

// void sorter(int* arr, int size, bool reverse_order) {
//     for(int i = 0; i < size; i++) {
//         int value = arr[i];
//         for(int j = i; j < size; j++) {
//             if((value < arr[j] && !reverse_order) || (value > arr[j] && reverse_order)) {
//                 arr[i] = arr[j];
//                 arr[j] = value;
//                 value = arr[i];
//             }
//         }
//     }
// }

int main() {
    int n,k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int max_sum = sumByOrder(arr, n, k, false);
    int min_sum = sumByOrder(arr, n, k, true);
    cout << max_sum-min_sum;
}