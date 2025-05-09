#include <iostream>
#include <vector>
using namespace std;

/*
* 백준 11660: 구간 합 구하기 5
* 
* 문제 해결 아이디어:
* - 2차원 누적 합(Prefix Sum)을 사용하여 구간 합을 O(1)에 계산
* - dp[i][j]는 (1,1)부터 (i,j)까지의 부분 배열 합
* - dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i][j]
* - (x1,y1)부터 (x2,y2)까지의 구간 합은 
*   dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1]
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    // 원본 배열과 누적 합 배열 (1-indexed)
    vector<vector<int>> arr(N+1, vector<int>(N+1, 0));
    vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
    
    // 입력 받기
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    
    // 2차원 누적 합 계산
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i][j];
        }
    }
    
    // 쿼리 처리
    for(int q = 0; q < M; q++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        // 구간 합 계산
        int result = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
        cout << result << '\n';
    }
    
    return 0;
}