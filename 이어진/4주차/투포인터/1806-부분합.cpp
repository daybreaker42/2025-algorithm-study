#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long s;
    cin >> n >> s;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int left = 0;
    int right = 0;
    long long current_sum = 0;
    int min_length = n + 1;

    while (right < n) {
        current_sum += a[right];

        while (current_sum >= s) {
            min_length = min(min_length, right - left + 1);
            current_sum -= a[left];
            left++;
        }
        right++;
    }

    if (min_length > n) {
        cout << 0 << endl;
    } else {
        cout << min_length << endl;
    }

    return 0;
}