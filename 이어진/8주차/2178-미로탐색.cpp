#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
* 백준 2178 - 미로 탐색
* 
* 문제 발상:
* 1. (1,1)에서 (N,M)까지의 최단 경로를 구하는 문제
* 2. BFS가 최단 경로를 보장하므로 BFS로 해결
* 3. 상하좌우로만 이동 가능하며, 이동 가능한 칸은 1로 표시
* 4. 방문한 칸의 거리를 기록하며 BFS 진행
* 5. 최종적으로 (N,M) 위치의 거리가 시작점으로부터의 최단 거리
*/

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int N, M;
vector<vector<char>> maze;
vector<vector<int>> dist;

// BFS로 미로 최단 경로 탐색
int bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0}); // 시작점 (0,0)
    dist[0][0] = 1; // 시작 위치도 카운트
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        // 목적지에 도달한 경우
        if (x == N - 1 && y == M - 1) {
            return dist[x][y];
        }
        
        // 상하좌우 네 방향 탐색
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 맵 범위 내에 있고, 방문하지 않은 길(1)인 경우
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && dist[nx][ny] == 0 && maze[nx][ny] == '1') {
                q.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1; // 거리 갱신
            }
        }
    }
    
    return -1; // 도달할 수 없는 경우 (문제에서는 발생하지 않음)
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    
    maze.resize(N, vector<char>(M));
    dist.resize(N, vector<int>(M, 0)); // 거리 배열 초기화
    
    // 미로 정보 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> maze[i][j];
        }
    }
    
    // BFS로 최단 경로 탐색
    cout << bfs() << '\n';
    
    return 0;
}
