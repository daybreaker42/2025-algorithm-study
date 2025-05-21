#include <iostream>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    int cnt = 1;
    while (b > a) {
        if (b % 10 == 1) b /= 10;
        else if (b % 2 == 0) b /= 2;
        else break;
        cnt++;
    }
    cout << (a == b ? cnt : -1) << '\n';
}
