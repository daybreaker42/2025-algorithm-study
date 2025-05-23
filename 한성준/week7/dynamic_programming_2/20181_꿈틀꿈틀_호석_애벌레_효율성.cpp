#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    vector<int> food(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> food[i];
    }
    
    // dp[i]: i번째 음식까지 고려했을 때 얻을 수 있는 최대 탈피 에너지
    vector<ll> dp(N + 1, 0);
    
    int left = 1;
    int right = 1;
    ll sum = food[1]; // 현재 구간의 음식 에너지 합
    ll max_energy = 0; // 현재 위치 이전까지의 최대 탈피 에너지
    
    while (right <= N) {
        if (sum >= K) { // 에너지 조건이 충족되면
            // 현재 구간 [left, right]에서 얻은 탈피 에너지를 추가
            ll extra_energy = sum - K; // 초과 에너지가 탈피 에너지가 됨
            
            // left-1 위치까지의 최적 해에 현재 탈피 에너지를 더한 것과 기존 최적해 비교
            dp[right] = max(dp[right], max_energy + extra_energy);
            
            // 구간의 왼쪽을 줄여가며 다른 가능한 경우 탐색
            sum -= food[left];
            left++;
        } else {
            // 다음 위치의 최적해 갱신 (현재 위치의 최적해를 물려줌)
            if (right < N) {
                dp[right + 1] = dp[right];
            }
            
            // 현재 위치까지의 최대 탈피 에너지 갱신
            max_energy = max(max_energy, dp[right]);
            
            // 구간의 오른쪽을 늘려 더 많은 에너지 섭취
            right++;
            if (right <= N) {
                sum += food[right];
            }
        }
    }
    
    // N번째 위치까지의 최대 탈피 에너지 출력
    cout << dp[N] << '\n';
    
    return 0;
}
