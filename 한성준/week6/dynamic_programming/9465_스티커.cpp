#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        
        vector<vector<int>> stickers(2, vector<int>(n + 1, 0));
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> stickers[i][j];
            }
        }
        
        // dp[i][j] = j번째 열까지 고려했을 때 최대 점수
        // i=0: j열에서 아무 스티커도 선택하지 않음
        // i=1: j열에서 위쪽(0행) 스티커 선택
        // i=2: j열에서 아래쪽(1행) 스티커 선택
        vector<vector<int>> dp(3, vector<int>(n + 1, 0));
        
        for (int j = 1; j <= n; j++) {
            // 아무것도 선택하지 않는 경우 (이전 열의 최대값)
            dp[0][j] = max({dp[0][j-1], dp[1][j-1], dp[2][j-1]});
            
            // 위쪽 스티커 선택 (이전 열에서 아래쪽 선택 or 아무것도 선택X)
            dp[1][j] = max(dp[0][j-1], dp[2][j-1]) + stickers[0][j];
            
            // 아래쪽 스티커 선택 (이전 열에서 위쪽 선택 or 아무것도 선택X)
            dp[2][j] = max(dp[0][j-1], dp[1][j-1]) + stickers[1][j];
        }
        
        // 마지막 열까지 고려했을 때의 최대값
        int result = max({dp[0][n], dp[1][n], dp[2][n]});
        cout << result << "\n";
    }
    
    return 0;
}
