#include <iostream>
#include <vector>
using namespace std;

/*
* 백준 16918 - 봄버맨
* 
* 문제 발상:
* 1. 봄버맨의 행동 패턴을 시뮬레이션하는 구현 문제
* 2. 처음 1초 동안은 아무것도 하지 않고, 다음 1초 동안은 모든 빈 칸에 폭탄 설치
* 3. 그 다음 1초부터는 3초 전에 설치된 폭탄이 터지며, 동시에 비어있는 칸에 새 폭탄 설치
* 4. 짝수 시간에는 모든 칸에 폭탄이 있는 상태
* 5. 홀수 시간에는 패턴이 반복됨 (N이 1이면 초기 상태, N이 3 이상의 홀수면 N % 4 == 3 또는 N % 4 == 1에 따라 상태가 결정)
*/

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int R, C, N;
vector<vector<char>> board;
vector<vector<int>> bomb_timer;

// 현재 상태를 출력하는 함수
void print_board() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

// 폭탄을 터뜨리는 함수
void explode_bombs() {
    vector<pair<int, int>> to_explode;
    
    // 폭발할 폭탄 위치 찾기
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (bomb_timer[i][j] == 3) {
                to_explode.push_back({i, j});
            }
        }
    }
    
    // 폭탄 폭발 처리
    for (auto [x, y] : to_explode) {
        board[x][y] = '.';
        bomb_timer[x][y] = 0;
        
        // 인접한 4방향 확인
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
                // 이미 폭발한 폭탄에 의해 영향받은 칸은 넘어감
                if (board[nx][ny] == '.') continue;
                board[nx][ny] = '.';
                bomb_timer[nx][ny] = 0;
            }
        }
    }
}

// 모든 빈 칸에 폭탄을 설치하는 함수
void install_bombs() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == '.') {
                board[i][j] = 'O';
                bomb_timer[i][j] = 1;
            }
        }
    }
}

// 타이머 증가 함수
void increase_timers() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 'O') {
                bomb_timer[i][j]++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> R >> C >> N;
    
    board.resize(R, vector<char>(C));
    bomb_timer.resize(R, vector<int>(C, 0));
    
    // 초기 보드 상태 입력
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'O') {
                bomb_timer[i][j] = 1; // 초기 폭탄 타이머 설정
            }
        }
    }
    
    // N=1인 경우는 초기 상태 그대로
    if (N == 1) {
        print_board();
        return 0;
    }
    
    // N이 짝수인 경우 모든 칸이 폭탄으로 가득 찬 상태
    if (N % 2 == 0) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cout << 'O';
            }
            cout << '\n';
        }
        return 0;
    }
    
    // N이 홀수인 경우 (3 이상)
    // N % 4 == 3 또는 N % 4 == 1에 따라 다른 패턴
    int cycles = (N % 4 == 3) ? 2 : 4;
    
    // 시뮬레이션 실행 (최대 4사이클)
    for (int t = 2; t <= cycles; t++) {
        // 짝수 시간: 모든 빈 칸에 폭탄 설치
        if (t % 2 == 0) {
            increase_timers();
            install_bombs();
        }
        // 홀수 시간: 3초 전 폭탄 폭발
        else {
            increase_timers();
            explode_bombs();
        }
    }
    
    // 최종 결과 출력
    print_board();
    
    return 0;
}
