#include <iostream>
#include <vector>
using namespace std;

/*
* 백준 1890: 점프
* 
* 문제 해결 아이디어:
* - 동적 계획법(DP)을 사용하여 각 위치에 도달할 수 있는 경로의 수를 계산
* - dp[i][j] = (i,j) 위치에 도달할 수 있는 경로의 수
* - 점프는 오른쪽과 아래로만 이동 가능
* - 각 칸에서는 해당 칸에 적힌 숫자만큼만 점프 가능
* - 오버플로우 방지를 위해 long long 타입 사용
*/

int main() {
    int N;
    cin >> N;
    
    vector<vector<int>> board(N, vector<int>(N));
    vector<vector<long long>> dp(N, vector<long long>(N, 0));
    
    // 입력 받기
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    
    // 시작점 설정
    dp[0][0] = 1;
    
    // DP 계산
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(dp[i][j] == 0 || (i == N-1 && j == N-1)) continue;
            
            int jump = board[i][j];
            
            // 오른쪽으로 점프
            if(j + jump < N) {
                dp[i][j + jump] += dp[i][j];
            }
            
            // 아래로 점프
            if(i + jump < N) {
                dp[i + jump][j] += dp[i][j];
            }
        }
    }
    
    cout << dp[N-1][N-1] << endl;
    
    return 0;
}