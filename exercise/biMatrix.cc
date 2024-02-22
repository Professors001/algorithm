#include <iostream>

using namespace std;

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return 1;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return 0;
}

int main() {
    int size, temp;
    cin >> size;
    int arr[size][size];

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cin >> arr[i][j];
        }
    }

    int target, status = 0;
    cin >> target;
    for(int i = 0; i < size; i++) {
        if(binarySearch(arr[i], size, target) == 1) {
            status = 1;
            break;
        }
    }
    if(status) {
            cout << "The Target Number is in this Matrix.";
    } else {
        
            cout << "The Target Number is NOT in this Matrix.";
    }
}
