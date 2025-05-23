#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

/*
* 백준 17836 - 공주님을 구해라!
* 
* 문제 발상:
* 1. 기사가 (0,0)에서 (N-1,M-1)까지 공주를 구하러 가는 최단 시간을 구하는 문제
* 2. 일반적인 최단 경로 문제와 다른 점은 그람이라는 아이템이 있음
* 3. 그람을 획득하면 벽을 무시하고 이동 가능
* 4. 두 가지 경로를 고려해야 함:
*    - 그람 없이 그냥 이동하는 경우
*    - 그람을 획득한 뒤 벽을 무시하고 목적지로 직행하는 경우
* 5. BFS로 두 경로의 최단 시간을 구한 뒤 더 짧은 시간을 택함
*/

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const int INF = 1e9;

int N, M, T;
vector<vector<int>> castle;
vector<vector<int>> dist; // 기사의 위치에서의 최단 거리

// BFS로 최단 경로 탐색
void bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0}); // 시작점 (0,0)
    dist[0][0] = 0;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        // 상하좌우 네 방향 탐색
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 맵 범위 내에 있고, 방문하지 않은 경우
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && dist[nx][ny] == -1) {
                // 빈 공간이거나 그람이 있는 경우
                if (castle[nx][ny] != 1) {
                    q.push({nx, ny});
                    dist[nx][ny] = dist[x][y] + 1;
                }
                // 벽인 경우는 지나갈 수 없음
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> T;
    
    castle.resize(N, vector<int>(M));
    dist.resize(N, vector<int>(M, -1)); // 거리 배열 초기화
    
    pair<int, int> gram_pos = {-1, -1}; // 그람의 위치
    
    // 성 정보 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> castle[i][j];
            if (castle[i][j] == 2) {
                gram_pos = {i, j}; // 그람 위치 저장
            }
        }
    }
    
    // BFS로 최단 경로 탐색
    bfs();
    
    int min_time = INF;
    
    // 1. 그람 없이 공주에게 도달하는 경우
    if (dist[N-1][M-1] != -1) {
        min_time = dist[N-1][M-1];
    }
    
    // 2. 그람을 먼저 찾아 공주에게 도달하는 경우
    if (gram_pos.first != -1 && dist[gram_pos.first][gram_pos.second] != -1) {
        int time_to_gram = dist[gram_pos.first][gram_pos.second];
        // 그람 획득 후 공주까지 맨해튼 거리로 계산 (벽을 무시하고 직선 이동)
        int gram_to_princess = (N-1 - gram_pos.first) + (M-1 - gram_pos.second);
        
        int total_time = time_to_gram + gram_to_princess;
        min_time = min(min_time, total_time);
    }
    
    // 결과 출력
    if (min_time <= T) {
        cout << min_time << '\n';
    } else {
        cout << "Fail" << '\n';
    }
    
    return 0;
}
