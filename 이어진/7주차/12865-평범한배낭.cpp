#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 백준 12865 - 평범한 배낭
* 
* 문제 발상:
* 1. 전형적인 0-1 배낭 문제(Knapsack Problem)
* 2. 각 물건은 무게(W)와 가치(V)를 가지고 있음
* 3. 배낭의 최대 무게(K)가 정해져 있을 때, 최대 가치를 구해야 함
* 4. DP를 이용하여 해결: dp[i][w] = i번째 물건까지 고려했을 때, 무게 w인 배낭의 최대 가치
* 5. 점화식: 
*    - i번째 물건을 선택하지 않는 경우: dp[i][w] = dp[i-1][w]
*    - i번째 물건을 선택하는 경우: dp[i][w] = dp[i-1][w-weight[i]] + value[i]
*    - 두 값 중 최댓값이 dp[i][w]의 값이 됨
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K; // N: 물품의 수, K: 버틸 수 있는 무게
    cin >> N >> K;
    
    vector<int> weights(N+1);
    vector<int> values(N+1);
    
    // 물건의 무게와 가치 입력
    for (int i = 1; i <= N; i++) {
        cin >> weights[i] >> values[i];
    }
    
    // DP 테이블 초기화
    vector<vector<int>> dp(N+1, vector<int>(K+1, 0));
    
    // 배낭 문제 해결
    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= K; w++) {
            // i번째 물건을 넣지 않는 경우
            dp[i][w] = dp[i-1][w];
            
            // i번째 물건을 넣을 수 있고, 넣는 것이 더 가치가 높은 경우
            if (w >= weights[i]) {
                dp[i][w] = max(dp[i][w], dp[i-1][w-weights[i]] + values[i]);
            }
        }
    }
    
    // 최대 가치 출력
    cout << dp[N][K] << '\n';
    
    return 0;
}
