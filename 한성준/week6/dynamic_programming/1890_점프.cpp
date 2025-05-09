#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<vector<int>> board(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    
    // dp[i][j] = (i,j)에서 도착점까지 가는 경로의 수
    // long long 타입 사용 (경로의 수가 2^63-1보다 작거나 같다고 문제에서 명시)
    vector<vector<long long>> dp(N, vector<long long>(N, 0));
    dp[0][0] = 1; // 시작점에서의 경로 수는 1
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // 이미 도착했거나 경로가 없는 경우 스킵
            if (dp[i][j] == 0 || (i == N-1 && j == N-1)) continue;
            
            int jump = board[i][j];
            if (jump == 0) continue; // 0이면 더 이상 이동 불가
            
            // 아래로 점프
            if (i + jump < N) {
                dp[i + jump][j] += dp[i][j];
            }
            
            // 오른쪽으로 점프
            if (j + jump < N) {
                dp[i][j + jump] += dp[i][j];
            }
        }
    }
    
    cout << dp[N-1][N-1] << endl;
    
    return 0;
}
