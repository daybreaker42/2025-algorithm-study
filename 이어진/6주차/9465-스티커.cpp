#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 백준 9465: 스티커
* 
* 문제 해결 아이디어:
* - 동적 계획법(DP)을 사용하여 최대 점수를 계산
* - dp[0][j]: j번째 열에서 위쪽(0행) 스티커를 선택했을 때의 최대 점수
* - dp[1][j]: j번째 열에서 아래쪽(1행) 스티커를 선택했을 때의 최대 점수
* - 스티커를 떼면 상하좌우로 인접한 스티커는 사용할 수 없음
* - 대각선으로는 사용 가능
* - dp[0][j] = max(dp[1][j-1], dp[1][j-2]) + sticker[0][j]
* - dp[1][j] = max(dp[0][j-1], dp[0][j-2]) + sticker[1][j]
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while(T--) {
        int n;
        cin >> n;
        
        vector<vector<int>> sticker(2, vector<int>(n+1, 0));
        vector<vector<int>> dp(2, vector<int>(n+1, 0));
        
        // 입력 받기
        for(int i = 0; i < 2; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> sticker[i][j];
            }
        }
        
        // 초기 조건
        dp[0][1] = sticker[0][1];
        dp[1][1] = sticker[1][1];
        
        // DP 계산
        for(int j = 2; j <= n; j++) {
            dp[0][j] = max(dp[1][j-1], dp[1][j-2]) + sticker[0][j];
            dp[1][j] = max(dp[0][j-1], dp[0][j-2]) + sticker[1][j];
        }
        
        // 결과 출력
        cout << max(dp[0][n], dp[1][n]) << '\n';
    }
    
    return 0;
}