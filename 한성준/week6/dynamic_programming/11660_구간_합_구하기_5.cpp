#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    // 2차원 배열 입력 받기 (1-indexed)
    vector<vector<int>> matrix(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> matrix[i][j];
        }
    }
    
    // 2D 누적 합 계산
    vector<vector<int>> prefix_sum(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            // 현재 칸의 값 + 왼쪽까지의 누적합 + 위쪽까지의 누적합 - 중복된 왼쪽 위 대각선 영역
            prefix_sum[i][j] = matrix[i][j] + prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1];
        }
    }
    
    // 쿼리 처리
    for (int q = 0; q < M; q++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        // (x1,y1)부터 (x2,y2)까지의 합 계산
        int result = prefix_sum[x2][y2] - prefix_sum[x2][y1-1] - prefix_sum[x1-1][y2] + prefix_sum[x1-1][y1-1];
        cout << result << "\n";
    }
    
    return 0;
}
