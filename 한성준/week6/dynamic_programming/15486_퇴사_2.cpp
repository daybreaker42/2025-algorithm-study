#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<int> T(N + 2, 0); // 상담에 걸리는 시간
    vector<int> P(N + 2, 0); // 상담 수익
    
    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }
    
    // dp[i] = i일부터 마지막 날까지 얻을 수 있는 최대 수익
    vector<int> dp(N + 2, 0);
    
    // 뒤에서부터 DP 계산
    for (int i = N; i >= 1; i--) {
        // i일에 상담을 할 수 있는 경우 (상담이 퇴사일 이전에 끝나는 경우)
        if (i + T[i] - 1 <= N) {
            // i일에 상담을 하는 경우와 하지 않는 경우 중 최대값 선택
            dp[i] = max(dp[i + T[i]] + P[i], dp[i + 1]);
        } else {
            // i일에 상담을 할 수 없는 경우 (상담이 퇴사일을 넘어가는 경우)
            dp[i] = dp[i + 1];
        }
    }
    
    cout << dp[1] << endl; // 1일부터 시작했을 때 최대 수익 출력
    
    return 0;
}
