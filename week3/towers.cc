#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int size;
    cin >> size;
    int temp, replace_status;
    vector<vector<int>> towers;

    for(int i = 0; i < size; i++) {
        replace_status = 1;
        cin >> temp;
        if(towers.empty()) {
            towers.push_back({temp});
        } else {
            int low = 0;
            int high = towers.size() - 1;
            while (low < high) {
                int mid = ceil((high+low)/2.0);
                int midValue = towers[mid].back();

                if (temp < midValue) {
                    high = mid-1;
                } else {
                    low = mid+1;
                }
            }
            if (towers[high].back() <= temp && high+1 >= towers.size()) {
                towers.push_back({temp});
            } else if (towers[high].back() > temp) {
                towers[high].push_back(temp);
            } else {
                towers[high+1].push_back(temp);
            }
        }
    }
    cout << towers.size();
}
