#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n <= 2) {
        cout << n << endl;
        return 0;
    }

    int max_length = 2;

    for (int i1 = 0; i1 < n - 1; ++i1) {
        for (int i2 = i1 + 1; i2 < n; ++i2) {
            int sum_val = a[i1] + a[i2];
            int count = 0;
            for (int ik = i2 + 1; ik < n; ++ik) {
                if (a[ik] < sum_val) {
                    count++;
                }
            }
            max_length = max(max_length, 2 + count);
        }
    }

    cout << max_length << endl;

    return 0;
}