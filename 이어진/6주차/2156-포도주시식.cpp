#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 백준 2156: 포도주 시식
* 
* 문제 해결 아이디어:
* - 동적 계획법(DP)을 사용하여 최대로 마실 수 있는 포도주의 양을 계산
* - dp[i]는 i번째 포도주까지 고려했을 때 최대로 마실 수 있는 포도주의 양
* - 세 가지 경우를 고려해야 함:
*   1) i번째 포도주를 마시지 않는 경우: dp[i-1]
*   2) i번째 포도주와 i-1번째 포도주를 마시고, i-2번째는 마시지 않는 경우: dp[i-3] + wine[i-1] + wine[i]
*   3) i번째 포도주와 i-2번째 포도주를 마시는 경우: dp[i-2] + wine[i]
* - 위 세 가지 경우 중 최댓값을 dp[i]에 저장
*/

int main() {
    int n;
    cin >> n;
    
    vector<int> wine(n+1, 0);
    vector<int> dp(n+1, 0);
    
    // 입력 받기
    for(int i = 1; i <= n; i++) {
        cin >> wine[i];
    }
    
    // 초기 조건 설정
    dp[0] = 0;
    dp[1] = wine[1];
    
    if(n > 1) {
        dp[2] = wine[1] + wine[2];
    }
    
    // DP 계산
    for(int i = 3; i <= n; i++) {
        dp[i] = max({
            dp[i-1],                      // i번째 포도주를 마시지 않는 경우
            dp[i-2] + wine[i],            // i번째 포도주와 i-2번째 포도주를 마시는 경우
            dp[i-3] + wine[i-1] + wine[i] // i번째와 i-1번째 포도주를 마시는 경우
        });
    }
    
    cout << dp[n] << endl;
    
    return 0;
}