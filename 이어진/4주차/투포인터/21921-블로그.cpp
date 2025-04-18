#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> visitors(n);
    for (int i = 0; i < n; ++i) {
        cin >> visitors[i];
    }

    if (x > n) {
        cout << "SAD" << endl;
        return 0;
    }

    long long current_visitors = 0;
    for (int i = 0; i < x; ++i) {
        current_visitors += visitors[i];
    }

    long long max_visitors = current_visitors;
    int count = 1;

    for (int i = x; i < n; ++i) {
        current_visitors -= visitors[i - x];
        current_visitors += visitors[i];

        if (current_visitors > max_visitors) {
            max_visitors = current_visitors;
            count = 1;
        } else if (current_visitors == max_visitors) {
            count++;
        }
    }

    if (max_visitors == 0) {
        cout << "SAD" << endl;
    } else {
        cout << max_visitors << endl;
        cout << count << endl;
    }

    return 0;
}