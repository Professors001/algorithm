#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b > a) {
        std::swap(a, b);
    }

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int sumOfDigit(int n) {
    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n = n / 10;
    }
    return sum;
}

int main() {
    int a, b;
    cin >> a >> b;
    for(int i = a; i <= b; i++) {
        if(gcd(i, sumOfDigit(i)) != 1) {
            cout << i << " ";
        }
    }
}
