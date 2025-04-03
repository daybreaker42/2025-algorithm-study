#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> t(n);
    vector<int> p(n);

    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> p[i];
    }

    vector<int> dp(n + 1, 0);

    for (int i = n - 1; i >= 0; --i) {
        dp[i] = dp[i + 1]; 
        if (i + t[i] <= n) {
            dp[i] = max(dp[i], p[i] + dp[i + t[i]]);
        }
    }

    cout << dp[0] << endl;

    return 0;
}