#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int size;
    cin >> size;
    int arr[size][size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> arr[i][j];
        }
    }

    int minDiff = abs(arr[0][0] - arr[0][1]);
    int curDiff = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j - 1 >= 0) {
                curDiff = abs(arr[i][j - 1] - arr[i][j]);
                if (curDiff < minDiff) {
                    minDiff = curDiff;
                }
            }

            if (j + 1 < size) {
                curDiff = abs(arr[i][j + 1] - arr[i][j]);
                if (curDiff < minDiff) {
                    minDiff = curDiff;
                }
            }
        }
    }

    cout << minDiff << endl;

    return 0;
}
