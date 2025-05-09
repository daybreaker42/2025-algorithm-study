#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
* 백준 1106: 호텔
* 
* 문제 해결 아이디어:
* - 동적 계획법(DP)을 사용하여 최소 비용을 계산
* - dp[i]: 적어도 i명의 고객을 늘리기 위해 필요한 최소 비용
* - 각 도시마다 비용과 고객 수가 다름
* - dp[i + customers] = min(dp[i + customers], dp[i] + cost)
* - 문제의 핵심은 "적어도" C명을 늘려야 한다는 것
* - 모든 도시에 대해, 홍보했을 때 얻을 수 있는 고객 수와 비용을 고려하여 DP 테이블 갱신
*/

int main() {
    int C, N;
    cin >> C >> N;
    
    vector<pair<int, int>> cities; // <비용, 고객 수>
    
    // 입력 받기
    for(int i = 0; i < N; i++) {
        int cost, customers;
        cin >> cost >> customers;
        cities.push_back({cost, customers});
    }
    
    // dp[i]: 적어도 i명의 고객을 늘리기 위한 최소 비용
    // 최대 C + 100명까지 고려 (한 번의 홍보로 얻을 수 있는 최대 고객 수가 100이라고 가정)
    vector<int> dp(C + 101, INT_MAX);
    dp[0] = 0; // 0명을 늘리는 비용은 0
    
    // DP 계산
    for(int i = 0; i <= C; i++) {
        if(dp[i] == INT_MAX) continue; // 도달할 수 없는 경우
        
        for(auto& city : cities) {
            int cost = city.first;
            int customers = city.second;
            
            // i명에서 시작해서 customers명을 더 늘리는 경우의 최소 비용 갱신
            dp[i + customers] = min(dp[i + customers], dp[i] + cost);
        }
    }
    
    // C명 이상 중에서 최소 비용 찾기
    int result = INT_MAX;
    for(int i = C; i <= C + 100; i++) {
        result = min(result, dp[i]);
    }
    
    cout << result << endl;
    
    return 0;
}