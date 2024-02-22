#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string orderStr(string order, string str) {
    string result = "";
    string left = "";
    for(char c : order) {
        if(find(str.begin(), str.end(), c) != str.end()) {
            result += c;
        }
    }
    for(char c : str) {
        if(find(order.begin(), order.end(), c) == order.end()) {
            left +=  c;
        }
    }

    sort(left.begin(), left.end());
    return result+left;
}

int main() {
    string order, str;
    cin >> order >> str;

    cout << orderStr(order, str);

    return 0;
}
