#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 19x19 바둑판 상태 입력
    vector<vector<int>> board(19, vector<int>(19));
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> board[i][j];
        }
    }
    
    // 8방향 탐색을 위한 델타 값 (우, 우하, 하, 좌하, 좌, 좌상, 상, 우상)
    int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    
    // 승리 여부 및 승리한 돌의 위치
    int winner = 0;
    int win_row = 0, win_col = 0;
    
    // 바둑판 전체 탐색
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            // 바둑알이 있는 경우
            if (board[i][j] != 0) {
                int stone = board[i][j]; // 현재 돌의 색깔
                
                // 8방향으로 탐색
                for (int dir = 0; dir < 8; dir++) {
                    int count = 1; // 연속된 돌의 개수
                    int ni = i + dx[dir];
                    int nj = j + dy[dir];
                    
                    // 같은 색 돌이 연속으로 있는지 확인
                    while (ni >= 0 && ni < 19 && nj >= 0 && nj < 19 && board[ni][nj] == stone) {
                        count++;
                        ni += dx[dir];
                        nj += dy[dir];
                    }
                    
                    // 정확히 5개의 돌이 연속으로 있는지 확인
                    if (count == 5) {
                        // 6개 이상이 연속되는지 확인 (반대 방향)
                        int oi = i - dx[dir];
                        int oj = j - dy[dir];
                        if (oi < 0 || oi >= 19 || oj < 0 || oj >= 19 || board[oi][oj] != stone) {
                            // 승리 조건 만족
                            winner = stone;
                            // 가장 왼쪽 또는 가장 위에 있는 돌의 위치 찾기
                            if (dir == 0 || dir == 1 || dir == 2 || dir == 7) { // 우, 우하, 하, 우상
                                win_row = i + 1; // 1-indexed로 변환
                                win_col = j + 1;
                            } else if (dir == 3) { // 좌하
                                win_row = i + 4 + 1;
                                win_col = j - 4 + 1;
                            } else if (dir == 4) { // 좌
                                win_row = i + 1;
                                win_col = j - 4 + 1;
                            } else if (dir == 5) { // 좌상
                                win_row = i - 4 + 1;
                                win_col = j - 4 + 1;
                            } else if (dir == 6) { // 상
                                win_row = i - 4 + 1;
                                win_col = j + 1;
                            }
                        }
                    }
                }
            }
        }
    }
    
    // 결과 출력
    cout << winner << endl;
    if (winner != 0) {
        cout << win_row << " " << win_col << endl;
    }
    
    return 0;
}
