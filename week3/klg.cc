#include <iostream>

using namespace std;

int calculateTotalSize(int days) {
    return (days + 1)*(days + 1);
}

long long area(long long l, long long r) {
    long long b = r - l + 1;
    if (b <= 0) return 0;
    if (b % 2 != 0) return (b + 1) * (b + 1) / 4;
    return b * (b + 2) / 4;
}

int main() {
    int size, target;
    cin >> size >> target;
    int arr[size];
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    int count, day = 1;
    count = calculateTotalSize(day) * size;
    while(count < target) {
        day++;
        count = calculateTotalSize(day) * size;
    }
    cout << day;

}
