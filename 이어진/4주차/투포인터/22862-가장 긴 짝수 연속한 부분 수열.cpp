#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int left = 0;
    int right = 0;
    int max_length = 0;
    int odd_count = 0;

    while (right < n) {
        if (a[right] % 2 != 0) {
            odd_count++;
        }

        while (odd_count > k) {
            if (a[left] % 2 != 0) {
                odd_count--;
            }
            left++;
        }

        max_length = max(max_length, right - left + 1);
        right++;
    }

    cout << max_length << endl;

    return 0;
}