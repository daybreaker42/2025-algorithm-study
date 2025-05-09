#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 백준 15486: 퇴사 2
* 
* 문제 해결 아이디어:
* - 동적 계획법(DP)을 사용하여 최대 수익을 계산
* - dp[i]: i일째까지 상담했을 때 얻을 수 있는 최대 수익
* - 각 날짜에 대해 두 가지 선택이 가능:
*   1) i일에 상담을 하지 않는 경우: dp[i] = dp[i-1]
*   2) i일에 상담을 하는 경우: dp[i+T[i]-1] = max(dp[i+T[i]-1], dp[i-1] + P[i])
* - 뒤에서부터 계산하면 더 직관적이지만, 앞에서부터 계산해도 가능
* - 범위를 벗어나는 경우를 처리해야 함
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<int> T(N+1); // 상담에 걸리는 시간
    vector<int> P(N+1); // 상담 시 받는 금액
    vector<int> dp(N+2, 0); // i일까지 일했을 때 최대 수익
    
    // 입력 받기
    for(int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }
    
    // DP 계산
    for(int i = 1; i <= N; i++) {
        // i일에 상담을 하지 않는 경우
        dp[i] = max(dp[i], dp[i-1]);
        
        // i일에 상담을 하는 경우 (상담이 끝나는 날이 퇴사일을 넘지 않는 경우만)
        if(i + T[i] <= N+1) {
            dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
        }
    }
    
    // 결과 출력 (마지막 날까지의 최대 수익)
    cout << max(dp[N], dp[N+1]) << endl;
    
    return 0;
}