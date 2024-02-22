#include <iostream>
#include <map>

using namespace std;

int missingGuy(map<int, int>  arr, int size) {
    for(int i = 1; i <= size+1; i++) {
        if(arr.find(i)->second != 1) {
            return i;
        }
    }
    return 0;
}

int main() {
    int size, temp;
    cin >> size;
    map<int, int> arr;

    for (int i = 0; i < size; i++) {
        cin >> temp;
        arr[temp] = 1;
    }

    cout << missingGuy(arr, size);

    return 0;
}
