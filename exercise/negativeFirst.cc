#include <iostream>

using namespace std;

int* negativeFirst(int* arr, int size) {
    // int* sortArr = (int*)malloc(sizeof(int)*size);
    int* sortArr = new int[size];
    int* plus = new int[size];
    int sortArrIndex = 0, plusIndex = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] < 0) {
            sortArr[sortArrIndex] = arr[i];
            sortArrIndex++;
        } else{
            plus[plusIndex] = arr[i];
            plusIndex++;
        }
    }
    for(int i = 0; i <= plusIndex; i++) {
        sortArr[sortArrIndex+i] = plus[i];
    }

    free(plus);
    return sortArr;
}

int main() {
    int size;
    cin >> size;
    int arr[size];
    for(int i = 0; i < size; i++) { 
        cin >> arr[i];
    }

    int* arrSort = negativeFirst(arr, size);

    for(int i = 0; i < size; i++) { 
        cout << arrSort[i] << " ";
    }
}
