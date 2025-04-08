#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int bfs(int state) {
    queue<pair<int, int>> q;
    unordered_set<int> visited;
    
    q.push({state, 0});
    visited.insert(state);
    
    // 가능한 모든 뒤집기 연산의 비트마스크
    vector<int> flips = {
        0b111000000, // 첫 번째 행
        0b000111000, // 두 번째 행
        0b000000111, // 세 번째 행
        0b100100100, // 첫 번째 열
        0b010010010, // 두 번째 열
        0b001001001, // 세 번째 열
        0b100010001, // 왼쪽 위에서 오른쪽 아래 대각선
        0b001010100  // 오른쪽 위에서 왼쪽 아래 대각선
    };
    
    while (!q.empty()) {
        auto [current, moves] = q.front();
        q.pop();
        
        // 모든 동전이 앞면이거나 모든 동전이 뒷면인 경우
        if (current == 0 || current == 0b111111111) {
            return moves;
        }
        
        // 가능한 모든 뒤집기 연산 시도
        for (int flip : flips) {
            int next = current ^ flip; // XOR 연산으로 뒤집기
            
            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                q.push({next, moves + 1});
            }
        }
    }
    
    return -1; // 불가능한 경우
}

int main() {
    fastio;
    
    int T;
    cin >> T;
    
    while (T--) {
        int state = 0;
        char c;
        
        // 3x3 동전 상태 입력
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> c;
                // H(앞면)은 1, T(뒷면)은 0으로 설정
                if (c == 'H') {
                    state |= (1 << (i * 3 + j));
                }
            }
        }
        
        // BFS로 최소 연산 횟수 구하기
        int result = bfs(state);
        cout << result << endl;
    }
    
    return 0;
}

/* 
문제 요약: 3x3 동전 배열에서 모든 동전을 같은 면이 보이도록 뒤집는 최소 횟수 구하기
- 행, 열, 대각선 단위로 동전을 뒤집을 수 있음
- 모든 동전이 앞면이나 뒷면이 되도록 하는 최소 횟수 또는 불가능(-1) 출력

접근 방법:
1. 동전 상태를 비트마스크로 표현 (H=1, T=0)
2. BFS를 이용해 가능한 모든 상태 탐색
3. 모든 동전이 같은 면인 경우(0 또는 111111111) 종료
4. 최소 연산 횟수 반환
*/
