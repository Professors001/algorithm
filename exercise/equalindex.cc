#include <iostream>

using namespace std;

int main() {
    int size;
    cin >> size;
    int arr[size];

    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int index;
    cin >> index;
    if(index < size) {
        if(arr[index] == index) {
            cout << "IT EQUAL!";
            return 0;
        }
    }
    cout << "It Not Equal!";
}
