#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    // 1차원 DP 배열로 공간 최적화
    vector<int> dp(K + 1, 0);
    
    for (int i = 1; i <= N; i++) {
        int weight, value;
        cin >> weight >> value;
        
        // 배낭 용량을 큰 값부터 작은 값 순으로 검사 (역순 탐색)
        // 이렇게 해야 각 물건을 한 번만 사용하게 됨
        for (int j = K; j >= weight; j--) {
            dp[j] = max(dp[j], dp[j - weight] + value);
        }
    }
    
    cout << dp[K] << '\n';
    
    return 0;
}
