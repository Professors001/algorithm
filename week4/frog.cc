#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  string arr[t];
  for(int i = 0; i < t; i++) {
    cin >> arr[i];
  }

  for(int i = 0; i < t; i++) {
    string temp = arr[i];
    int start = -1, max = 1, len = temp.length();
    while (start < len) {
        int jump;
        for (jump = max; jump > 0; jump--) {
            int nextPosition = start + jump;
            if (nextPosition < len) {
                if (temp[nextPosition] == 'R') {
                    break;
                }
            } else {
                break;
            }
        }

        if (jump == 0) {
            max++;
            jump = max;
        }else {
            start += jump;
        }
    }
    cout << max << endl;
  }
}