#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> wine(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> wine[i];
    }
    
    // dp[i] = i번째 포도주까지 고려했을 때 최대로 마실 수 있는 포도주의 양
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = wine[1];
    
    if (n > 1) {
        dp[2] = wine[1] + wine[2];
    }
    
    // 각 위치에서 3가지 선택지 고려:
    // 1. 현재 포도주를 마시고 이전 포도주도 마신 경우 (dp[i-3] + wine[i-1] + wine[i])
    // 2. 현재 포도주를 마시고 이전 포도주는 마시지 않은 경우 (dp[i-2] + wine[i])
    // 3. 현재 포도주를 마시지 않은 경우 (dp[i-1])
    for (int i = 3; i <= n; i++) {
        dp[i] = max({dp[i-3] + wine[i-1] + wine[i], dp[i-2] + wine[i], dp[i-1]});
    }
    
    cout << dp[n] << endl;
    
    return 0;
}
