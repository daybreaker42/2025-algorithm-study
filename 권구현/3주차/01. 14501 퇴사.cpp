#include <iostream>
#include <cmath>

using namespace std;
int n, t, p, dp[16][16] = {{0, }, };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i<=n; i++) {
        cin >> t >> p;
        if (i+t-1 > n) {
            for (int ii = 1; ii<=n; ii++) dp[i][ii] = dp[i-1][ii];
        } else {
            for (int ii = 1; ii<=n; ii++) {
                if (ii<i+t-1) dp[i][ii] = dp[i-1][ii];
                else if (ii == i+t-1) dp[i][ii] = max(dp[i-1][ii-t]+p,dp[i-1][ii]);
                else dp[i][ii] = max(dp[i-1][ii], dp[i][ii-1]);
            }
        }
    }
    cout << dp[n][n];
}
