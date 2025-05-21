#include <iostream>
#include <vector>
using namespace std;

/*
* 백준 15724 - 주지수
* 
* 문제 발상:
* 1. 2차원 누적 합(prefix sum)을 이용한 문제
* 2. (x1,y1)에서 (x2,y2)까지의 직사각형 영역 인구 합을 빠르게 구하기 위해 
*    2차원 누적 합 배열을 미리 계산
* 3. 누적 합을 이용하면 특정 직사각형 영역의 합을 O(1)에 구할 수 있음
* 4. 공식: sum(x1,y1,x2,y2) = prefix_sum[x2][y2] - prefix_sum[x1-1][y2] 
*                            - prefix_sum[x2][y1-1] + prefix_sum[x1-1][y1-1]
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M; // N: 행의 개수, M: 열의 개수
    cin >> N >> M;
    
    // 2차원 배열 입력 (인덱스를 1부터 시작하기 위해 크기를 +1)
    vector<vector<int>> area(N+1, vector<int>(M+1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> area[i][j];
        }
    }
    
    // 2차원 누적 합 계산
    vector<vector<int>> prefix_sum(N+1, vector<int>(M+1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            prefix_sum[i][j] = area[i][j] + prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1];
        }
    }
    
    // 질의 처리
    int K;
    cin >> K;
    
    for (int i = 0; i < K; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        // (x1,y1)부터 (x2,y2)까지의 직사각형 영역 인구 합 계산
        int result = prefix_sum[x2][y2] - prefix_sum[x1-1][y2] - prefix_sum[x2][y1-1] + prefix_sum[x1-1][y1-1];
        cout << result << '\n';
    }
    
    return 0;
}
