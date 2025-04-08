#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int N, M;
char grid[9][9];
int maxSquare = -1;

// 숫자가 제곱수인지 확인하는 함수
bool isSquare(long long num) {
    long long root = sqrt(num);
    return root * root == num;
}

int main() {
    fastio;
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }
    
    // 모든 시작 위치에서 탐색
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // 모든 등차 값 탐색 (-N부터 N까지, -M부터 M까지)
            for (int di = -N; di <= N; di++) {
                for (int dj = -M; dj <= M; dj++) {
                    // 등차가 둘 다 0인 경우는 제외 (제자리)
                    if (di == 0 && dj == 0) continue;
                    
                    int x = i, y = j;
                    long long num = 0;
                    
                    // 등차수열 형태로 숫자 생성
                    while (0 <= x && x < N && 0 <= y && y < M) {
                        // 현재 자리 숫자 추가
                        num = num * 10 + (grid[x][y] - '0');
                        
                        // 제곱수 확인
                        if (isSquare(num)) {
                            maxSquare = max(maxSquare, (int)num);
                        }
                        
                        // 다음 위치로 이동
                        x += di;
                        y += dj;
                    }
                }
            }
        }
    }
    
    cout << maxSquare << endl;
    
    return 0;
}

/* 
문제 요약: N×M 격자에서 등차수열 형태로 숫자를 선택하여 만들 수 있는 가장 큰 제곱수 찾기
- 행과 열의 등차수열로 숫자 선택 가능
- 한 자리 숫자도 가능
- 제곱수가 없으면 -1 출력

접근 방법:
1. 모든 시작 위치(i, j)에서 탐색
2. 모든 가능한 등차(di, dj) 값으로 숫자 생성
3. 생성된 숫자가 제곱수인지 확인하고 최대값 갱신
*/
