#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, max_weight;
    cin >> n >> max_weight;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int count = 0;
    sort(arr, arr + n);
    int left = 0, right = n - 1;

    while (left <= right) {
        if (arr[left] + arr[right] <= max_weight) {
            left++;
            right--;
        } else {
            right--;
        }
        count++;
    }
    cout << count;
}
