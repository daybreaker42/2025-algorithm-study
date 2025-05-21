#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
* 백준 2294: 동전 2
* 
* 문제 해결 아이디어:
* - 동적 계획법(DP)을 사용하여 각 금액을 만드는 데 필요한 최소 동전 개수를 계산
* - dp[i]: i원을 만드는 데 필요한 최소 동전 개수
* - dp[i] = min(dp[i], dp[i - coin[j]] + 1) (j는 동전의 종류)
* - 초기값으로 dp[0] = 0, 나머지는 매우 큰 값으로 설정
* - 각 동전에 대해, 해당 동전을 사용했을 때의 최소 개수를 갱신
*/

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> coins(n);
    vector<int> dp(k+1, INT_MAX-1); // 오버플로우 방지를 위해 INT_MAX-1로 초기화
    
    // 입력 받기
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    // 초기 조건
    dp[0] = 0;
    
    // DP 계산
    for(int i = 0; i < n; i++) { // 각 동전에 대해
        for(int j = coins[i]; j <= k; j++) { // coins[i]원부터 k원까지
            // j원을 만드는 데 필요한 최소 동전 개수 갱신
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }
    
    // 결과 출력
    if(dp[k] == INT_MAX-1) {
        cout << -1 << endl; // 불가능한 경우
    } else {
        cout << dp[k] << endl;
    }
    
    return 0;
}