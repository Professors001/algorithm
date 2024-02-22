#include <iostream>
#include <algorithm>

using namespace std;

int satisfaction(int* arr, int size) {
    int score = 0;
    for(int i = 1; i <= size; i++) {
        score += arr[i-1] * i;
    }
    return score;
}

int main() {
    int size;
    cin >> size;
    int arr[size];

    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + size);

    cout << satisfaction(arr, size);

    return 0;
}
