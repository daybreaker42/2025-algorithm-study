#include <iostream>
#include <vector>
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
    
    // dp[i] = i원을 만드는 방법의 수
    vector<int> dp(k + 1, 0);
    dp[0] = 1; // 0원을 만드는 방법은 아무 동전도 사용하지 않는 1가지
    
    // 각 동전에 대해 dp 테이블 갱신
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= k; j++) {
            // j원을 만들 때 coins[i]를 사용하는 경우의 수 추가
            dp[j] += dp[j - coins[i]]; // 현재 동전을 한 번 사용하는 경우
        }
    }
    
    cout << dp[k] << endl;
    
    return 0;
}
