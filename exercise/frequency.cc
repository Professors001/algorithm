#include <iostream>
#include <map>

using namespace std;

int frequency(int* arr, int size) {
    map<int, int> count;

    for(int i = 0; i < size; i++) {
        if(count.find(arr[i]) != count.end()) {
            count.find(arr[i])->second++;
            if(count.find(arr[i])->second > size / 2) {
                return count.find(arr[i])->first;
            }
        } else {
            count[arr[i]] = 1;
        }
    }
    return -1;
}

int main() {
    int size;
    cin >> size;
    int arr[size];
    for(int i = 0; i < size; i++) { 
        cin >> arr[i];
    }

    int ans = frequency(arr, size);
    if(ans != -1) {
        cout << ans;
    } else {
        cout << "";
    }
    
}
