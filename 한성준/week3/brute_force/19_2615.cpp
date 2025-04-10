#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int board[19][19];
// 방향: 우, 우하, 하, 좌하
int dx[] = {0, 1, 1, 1};
int dy[] = {1, 1, 0, -1};

// 승리 확인 함수
bool checkWin(int x, int y, int stone) {
    for (int dir = 0; dir < 4; dir++) {
        int count = 1;
        
        // 해당 방향으로 연속된 돌 확인
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        while (0 <= nx && nx < 19 && 0 <= ny && ny < 19 && board[nx][ny] == stone) {
            count++;
            nx += dx[dir];
            ny += dy[dir];
        }
        
        // 반대 방향도 확인
        nx = x - dx[dir];
        ny = y - dy[dir];
        while (0 <= nx && nx < 19 && 0 <= ny && ny < 19 && board[nx][ny] == stone) {
            count++;
            nx -= dx[dir];
            ny -= dy[dir];
        }
        
        // 정확히 5개 연속인지 확인
        if (count == 5) {
            // 육목 확인을 위해 반대 방향의 이전 좌표 계산
            int px = x - dx[dir];
            int py = y - dy[dir];
            
            // 시작점 결정 (가장 왼쪽 또는 가장 위의 돌)
            int startX, startY;
            if (dir == 3) { // 좌하 방향인 경우
                // 가장 오른쪽 위의 돌을 시작점으로
                startX = x - 4 * dx[dir];
                startY = y - 4 * dy[dir];
            } else {
                // 가장 왼쪽 또는 가장 위의 돌을 시작점으로
                if (0 <= px && px < 19 && 0 <= py && py < 19 && board[px][py] == stone) {
                    continue; // 육목이므로 패스
                }
                startX = x;
                startY = y;
            }
            
            return true;
        }
    }
    return false;
}

int main() {
    fastio;
    
    // 바둑판 상태 입력
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> board[i][j];
        }
    }
    
    // 모든 위치 확인
    for (int j = 0; j < 19; j++) {
        for (int i = 0; i < 19; i++) {
            if (board[i][j] != 0) {
                if (checkWin(i, j, board[i][j])) {
                    cout << board[i][j] << endl;
                    cout << (i + 1) << " " << (j + 1) << endl;
                    return 0;
                }
            }
        }
    }
    
    // 승부가 결정되지 않은 경우
    cout << 0 << endl;
    
    return 0;
}

/* 
문제 요약: 19x19 바둑판에서 오목 승부 결정하기
- 검은 돌(1)과 흰 돌(2)이 있음
- 가로, 세로, 대각선으로 연속 5개의 돌이 있으면 승리
- 6개 이상의 연속된 돌은 승리로 인정되지 않음
- 승부가 결정된 경우 승자와 승리에 기여한 가장 왼쪽 또는 위쪽 돌의 위치 출력

접근 방법:
1. 바둑판의 모든 위치를 왼쪽->오른쪽, 위->아래 순으로 검사
2. 각 위치에서 네 방향(가로, 세로, 두 대각선)으로 연속된 돌 확인
3. 정확히 5개의 연속된 돌을 찾으면 승리 판정
4. 육목 여부 확인을 위해 반대 방향도 검사
*/
