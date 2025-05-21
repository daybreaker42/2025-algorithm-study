#include <iostream>
#include <algorithm>
using namespace std;

int dp[10001];
int coin[101];

int main() {
    int n, k;
    cin >> n >> k;

    fill(dp, dp + k + 1, 1e9);
    dp[0] = 0;

    for (int i=0; i<n; i++) cin >> coin[i];

    for (int i=0; i<n; i++) {
        for (int j=coin[i]; j<=k; j++) {
            dp[j] = min(dp[j], dp[j - coin[i]] + 1);
        }
    }

    cout << (dp[k] == 1e9 ? -1 : dp[k]) << '\n';
}
