#include <iostream>
#include <algorithm>
using namespace std;

int t[1500001], p[1500001];
long long dp[1500002];

int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i] >> p[i];

    for (int i=n; i>=1; i--) {
        if (i + t[i] > n + 1) dp[i] = dp[i+1];
        else dp[i] = max(dp[i+1], dp[i + t[i]] + p[i]);
    }

    cout << dp[1] << '\n';
}
