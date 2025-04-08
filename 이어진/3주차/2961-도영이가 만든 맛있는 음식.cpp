#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> s(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> b[i];
    }

    long long min_diff = LLONG_MAX;

    for (int mask = 1; mask < (1 << n); ++mask) {
        long long total_sourness = 1;
        long long total_bitterness = 0;
        bool ingredient_chosen = false;

        for (int j = 0; j < n; ++j) {
            if ((mask >> j) & 1) {
                total_sourness *= s[j];
                total_bitterness += b[j];
                ingredient_chosen = true;
            }
        }

        if (ingredient_chosen) {
            long long diff = abs(total_sourness - total_bitterness);
            if (diff < min_diff) {
                min_diff = diff;
            }
        }
    }

    cout << min_diff << endl;

    return 0;
}