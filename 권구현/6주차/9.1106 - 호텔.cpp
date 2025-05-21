#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int dp[1001]; // dp[i]: i명 얻기 위한 최소 비용

int main() {
    int c, n;
    cin >> c >> n;

    fill(dp, dp + 1001, INF);
    dp[0] = 0;

    for (int i=0; i<n; i++) {
        int cost, cust;
        cin >> cost >> cust;
        for (int j=cust; j<=1000; j++) {
            dp[j] = min(dp[j], dp[j - cust] + cost);
        }
    }

    int ans = INF;
    for (int i=c; i<=1000; i++) ans = min(ans, dp[i]);

    cout << ans << '\n';
}
