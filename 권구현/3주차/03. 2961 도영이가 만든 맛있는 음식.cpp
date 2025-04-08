#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<pair<int, int>> ingredients(N);
    for (int i = 0; i < N; i++) {
        cin >> ingredients[i].first >> ingredients[i].second;
    }
    
    int min_diff = INT_MAX;
    
    // 모든 부분집합 검사 (비트마스킹 사용)
    for (int i = 1; i < (1 << N); i++) {  // 1부터 시작하여 빈 집합을 제외
        long long sour = 1;  // 신맛(곱)
        int bitter = 0;      // 쓴맛(합)
        
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {  // j번째 재료를 사용한다면
                sour *= ingredients[j].first;
                bitter += ingredients[j].second;
            }
        }
        
        // 신맛과 쓴맛의 차이 계산
        int diff = abs(sour - bitter);
        min_diff = min(min_diff, diff);
    }
    
    cout << min_diff << endl;
    
    return 0;
}
