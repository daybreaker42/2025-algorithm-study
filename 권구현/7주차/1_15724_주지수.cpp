// 15724 주지수
#include <iostream>
using namespace std;
int n, m, dp[1025][1025];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x; cin >> x;
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + x;
        }
    }
    int k; cin >> k;
    while (k--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1] << '\n';
    }
}
