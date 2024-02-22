#include <iostream>
#include <algorithm>

using namespace std;


int countMax(string text) {
    if (text.empty()) {
        return 0;
    }

    string cur_text;
    int countMax = 1;
    int counting = 1;

    for (int i = 1; i < text.length(); ++i) {
        if (text[i] == text[i - 1]) {
            counting++;
            if (counting > countMax) {
                countMax = counting;
            }
        } else {
            counting = 1;
        }
    }

    return countMax;
}

int main() {
    string text;
    cin >> text;
    cout << countMax(text);
}
