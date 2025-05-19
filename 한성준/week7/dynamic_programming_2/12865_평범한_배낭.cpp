#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    vector<int> weights(N + 1);
    vector<int> values(N + 1);
    
    for (int i = 1; i <= N; i++) {
        cin >> weights[i] >> values[i];
    }
    
    // dp[i][j] = i번째 물건까지 고려했을 때, 무게 j에서의 최대 가치
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            // 현재 물건을 넣을 수 없는 경우
            if (weights[i] > j) {
                dp[i][j] = dp[i-1][j];
            }
            // 현재 물건을 넣을 수 있는 경우 (넣는 경우와 넣지 않는 경우 중 최대값)
            else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i]] + values[i]);
            }
        }
    }
    
    cout << dp[N][K] << '\n';
    
    return 0;
}
