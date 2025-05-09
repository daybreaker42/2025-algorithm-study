#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    // dp[i] = i원을 만들기 위해 필요한 최소 동전 개수
    vector<int> dp(k + 1, INT_MAX - 1); // 오버플로우 방지를 위해 INT_MAX-1로 초기화
    dp[0] = 0; // 0원은 동전이 필요 없음
    
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= k; j++) {
            // j원을 만들기 위해 coins[i]를 사용하는 경우와 사용하지 않는 경우 비교
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }
    
    // 불가능한 경우 -1 출력
    cout << (dp[k] == INT_MAX - 1 ? -1 : dp[k]) << endl;
    
    return 0;
}
