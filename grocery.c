#include <stdio.h>
#include <stdbool.h>

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
    
    return newArr[size][target];
}

int main() {
    int size, target;
    scanf("%d %d", &size, &target);

    int arr[size];
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%s", canSumArrToTarget(arr, size, target) == 1 ? "Yes" : "No");
    return 0;
}
