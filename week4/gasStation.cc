#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int fillArr[n], costArr[n];
    for(int i = 0; i < n; i++) {
        cin >> fillArr[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> costArr[i];
    }

    int totalFill = 0;
    int totalCost = 0;
    int tank = 0;
    int startIndex = 0;
    for (int i = 0; i < n; ++i) {
        totalFill += fillArr[i];
        totalCost += costArr[i];
        tank += fillArr[i] - costArr[i];

        if (tank < 0) {
            startIndex = i + 1;
            tank = 0;
        }
    }
    if (totalFill < totalCost)
        cout << -1;
    else
        cout << startIndex;
}