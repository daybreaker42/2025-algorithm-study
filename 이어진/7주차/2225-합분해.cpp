#include <iostream>
#include <vector>
using namespace std;

/*
* 백준 2225 - 합분해
* 
* 문제 발상:
* 1. 0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수를 구하는 문제
* 2. DP를 이용하여 해결: dp[k][n] = k개의 수를 더해서 합이 n이 되는 경우의 수
* 3. 점화식:
*    - dp[k][n] = dp[k-1][0] + dp[k-1][1] + ... + dp[k-1][n]
*    - 또는 다르게 표현하면: dp[k][n] = sum(dp[k-1][n-l]) (0 <= l <= n)
* 4. 초기값: dp[1][n] = 1 (1개의 수로 합이 n이 되는 경우의 수는 1가지)
* 5. 중간 결과가 매우 커질 수 있으므로 모든 연산은 1,000,000,000로 나눈 나머지를 취함
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    const int MOD = 1000000000;
    int N, K;
    cin >> N >> K;
    
    // DP 테이블 초기화
    vector<vector<int>> dp(K+1, vector<int>(N+1, 0));
    
    // 초기값 설정: 1개의 수로 합이 n이 되는 경우의 수는 1가지
    for (int n = 0; n <= N; n++) {
        dp[1][n] = 1;
    }
    
    // DP 계산
    for (int k = 2; k <= K; k++) {
        for (int n = 0; n <= N; n++) {
            for (int l = 0; l <= n; l++) {
                dp[k][n] = (dp[k][n] + dp[k-1][n-l]) % MOD;
            }
        }
    }
    
    // 결과 출력: K개의 수를 더해서 합이 N이 되는 경우의 수
    cout << dp[K][N] << '\n';
    
    return 0;
}
