#include <iostream>

using namespace std;

int main() {
    int size, temp;
    cin >> size;
    int arr[size];

    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cin >> temp;
    if(temp > size) {
        cout << "Not Equal";
    } else if (arr[temp] == temp) {
        cout << "Equal!";
    } else{
        cout << "Not Equal";
    }
}
