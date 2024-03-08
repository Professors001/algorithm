#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printText(vector<long int> vec) {
    if(vec.empty()) {
        cout << '-' << endl; 
        return;
    }

    for(long int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void subset(vector<long int> vec, vector<long int> text, long int index) {
    printText(text);
    for(long int i = index; i < vec.size(); i++) {
        text.push_back(vec[i]);
        subset(vec, text, i + 1);
        text.pop_back();
    }
}

int main() {
    long int size, temp;
    vector<long int> vec;
    cin >> size;
    for(long int i = 0; i < size; i++) {
        cin >> temp;
        vec.push_back(temp);
    }

    vector<long int> text;
    subset(vec, text, 0);
    return 0;
}