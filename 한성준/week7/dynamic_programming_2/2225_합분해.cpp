#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    const int MOD = 1000000000;
    
    // dp[k][n] = 정수 k개를 더해서 합이 n이 되는 경우의 수
    vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
    
    // 초기화: 1개의 숫자로 n을 만드는 방법은 1가지 (그 숫자 자체)
    for (int n = 0; n <= N; n++) {
        dp[1][n] = 1;
    }
    
    for (int k = 2; k <= K; k++) {
        for (int n = 0; n <= N; n++) {
            // n을 만드는 k개의 정수 조합: 마지막 수가 0~n인 경우의 합
            for (int lastNum = 0; lastNum <= n; lastNum++) {
                dp[k][n] = (dp[k][n] + dp[k-1][n-lastNum]) % MOD;
            }
        }
    }
    
    cout << dp[K][N] << '\n';
    
    return 0;
}
