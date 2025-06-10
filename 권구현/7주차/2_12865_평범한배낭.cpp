// 12865 평범한 배낭
#include <iostream>
#include <algorithm>
using namespace std;
int n, k, dp[100001];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int w, v; cin >> w >> v;
        for (int j = k; j >= w; j--)
            dp[j] = max(dp[j], dp[j-w] + v);
    }
    cout << dp[k];
}
