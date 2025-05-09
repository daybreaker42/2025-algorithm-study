#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    // dp[i] = i번째 돌까지 도달 가능 여부 (1: 가능, 0: 불가능)
    vector<bool> dp(N + 1, false);
    dp[1] = true; // 시작점
    
    for (int i = 1; i < N; i++) {
        // 현재 i번째 돌에 도달할 수 없으면 스킵
        if (!dp[i]) continue;
        
        // i번째 돌에서 j번째 돌로 이동 가능한지 확인
        for (int j = i + 1; j <= N; j++) {
            int power = (j - i) * (1 + abs(A[i] - A[j]));
            // K 이하의 힘으로 도달 가능하면 dp[j]를 true로 설정
            if (power <= K) {
                dp[j] = true;
            }
        }
    }
    
    // N번째 돌에 도달할 수 있는지 여부 출력
    cout << (dp[N] ? "YES" : "NO") << endl;
    
    return 0;
}
