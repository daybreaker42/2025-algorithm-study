#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    // 2D 배열 입력 받기 (1-indexed)
    vector<vector<int>> area(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> area[i][j];
        }
    }
    
    // 2D 누적 합(prefix sum) 계산
    vector<vector<int>> prefix_sum(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            // 현재 위치의 값 + 왼쪽까지의 합 + 위쪽까지의 합 - 중복 계산된 왼쪽 위 대각선 영역
            prefix_sum[i][j] = area[i][j] + prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1];
        }
    }
    
    // 쿼리 처리
    int K;
    cin >> K;
    
    for (int q = 0; q < K; q++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        // (x1,y1)부터 (x2,y2)까지의 직사각형 영역 합 계산
        int result = prefix_sum[x2][y2] - prefix_sum[x2][y1-1] - prefix_sum[x1-1][y2] + prefix_sum[x1-1][y1-1];
        cout << result << '\n';
    }
    
    return 0;
}
