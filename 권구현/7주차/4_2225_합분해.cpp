#include <iostream>
using namespace std;
const int MOD = 1e9;
int dp[201][201];
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= n; i++) dp[1][i] = 1;
    for (int i = 2; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            for (int l = 0; l <= j; l++) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-l]) % MOD;
            }
        }
    }
    cout << dp[k][n];
}
