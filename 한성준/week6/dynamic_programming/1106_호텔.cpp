#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int C, N;
    cin >> C >> N;
    
    vector<pair<int, int>> cities(N); // (비용, 고객 수)
    for (int i = 0; i < N; i++) {
        cin >> cities[i].first >> cities[i].second;
    }
    
    // 최대로 유치해야 할 고객 수에 여유를 두기 위해 C+100으로 설정
    const int MAX_CUSTOMERS = C + 100;
    
    // dp[i] = i명의 고객을 유치하기 위한 최소 비용
    vector<int> dp(MAX_CUSTOMERS + 1, INT_MAX);
    dp[0] = 0; // 0명은 비용이 0
    
    // 각 도시에서의 홍보 방법 고려
    for (int i = 0; i < N; i++) {
        int cost = cities[i].first;
        int customers = cities[i].second;
        
        for (int j = customers; j <= MAX_CUSTOMERS; j++) {
            // j-customers명까지 이미 유치했다면, j명까지 유치하는데 드는 최소 비용 갱신
            if (dp[j - customers] != INT_MAX) {
                dp[j] = min(dp[j], dp[j - customers] + cost);
            }
        }
    }
    
    // C명 이상의 고객을 유치하는데 필요한 최소 비용 찾기
    int result = INT_MAX;
    for (int i = C; i <= MAX_CUSTOMERS; i++) {
        result = min(result, dp[i]);
    }
    
    cout << result << endl;
    
    return 0;
}
