#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

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
    map<int, int> frequency;

    while (right < n) {
        frequency[a[right]]++;

        while (frequency[a[right]] > k) {
            frequency[a[left]]--;
            left++;
        }

        max_length = max(max_length, right - left + 1);
        right++;
    }

    cout << max_length << endl;

    return 0;
}