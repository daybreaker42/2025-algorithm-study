#include <iostream>
#include <vector>
using namespace std;

/*
* 백준 22869: 징검다리 건너기(small)
* 
* 문제 해결 아이디어:
* - 동적 계획법(DP)을 사용하여 각 돌에 도달할 수 있는지 여부를 저장
* - dp[i] = i번째 돌에 도달할 수 있는지 여부 (1: 가능, 0: 불가능)
* - 각 돌에서 다음 돌로 이동할 때 필요한 에너지는 (j-i) * (1 + |A[i] - A[j]|)
* - K보다 작거나 같은 에너지로 이동할 수 있어야 함
* - 모든 돌에 대해, 이전의 모든 돌로부터 현재 돌로 이동할 수 있는지 확인
*/

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> A(N+1);
    vector<bool> dp(N+1, false);
    
    // 입력 받기
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    // 시작점 설정
    dp[1] = true;
    
    // DP 계산
    for(int i = 1; i < N; i++) {
        if(!dp[i]) continue; // i번째 돌에 도달할 수 없다면 스킵
        
        for(int j = i+1; j <= N; j++) {
            // 에너지 계산
            int energy = (j - i) * (1 + abs(A[i] - A[j]));
            
            // 에너지가 K 이하면 이동 가능
            if(energy <= K) {
                dp[j] = true;
            }
        }
    }
    
    // 마지막 돌에 도달할 수 있는지 여부 출력
    if(dp[N]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}