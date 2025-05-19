#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    const int MOD = 1000000000;
    
    // dp[k][n] = 정수 k개를 더해 합이 n이 되는 경우의 수
    vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
    
    // 초기화: 1개의 숫자로 만드는 방법은 1가지
    for (int n = 0; n <= N; n++) {
        dp[1][n] = 1;
    }
    
    // 최적화된 점화식: dp[k][n] = dp[k][n-1] + dp[k-1][n]
    // - dp[k][n-1]은 마지막 수에 1을 더한 경우
    // - dp[k-1][n]은 k-1개로 n을 만든 후 0을 추가한 경우
    for (int k = 2; k <= K; k++) {
        for (int n = 0; n <= N; n++) {
            // n-1에서 1을 더하는 경우
            if (n > 0) {
                dp[k][n] = dp[k][n-1];
            }
            // k-1개 수로 n을 만들고 0을 추가하는 경우
            dp[k][n] = (dp[k][n] + dp[k-1][n]) % MOD;
        }
    }
    
    cout << dp[K][N] << '\n';
    
    return 0;
}
