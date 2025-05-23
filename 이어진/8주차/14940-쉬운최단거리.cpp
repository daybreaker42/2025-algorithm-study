#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
* 백준 14940 - 쉬운 최단거리
* 
* 문제 발상:
* 1. 목표지점(2)에서 모든 칸까지의 최단거리를 구하는 문제 (BFS)
* 2. 원래 갈 수 있는 땅(1)인 부분 중에서 도달할 수 없는 위치는 -1로 표시
* 3. 원래부터 갈 수 없는 땅(0)은 0으로 표시
* 4. 시작점(2)에서 BFS를 돌려 각 지점까지의 최단거리 계산
* 5. 방문하지 못한 땅(1)은 -1로 표시
*/

const int MAX = 1000;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m;
vector<vector<int>> map;
vector<vector<int>> dist;
vector<vector<bool>> visited;

// BFS로 시작지점에서 다른 모든 지점까지의 최단거리 계산
void bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    
    q.push({startX, startY});
    visited[startX][startY] = true;
    dist[startX][startY] = 0; // 시작점의 거리는 0
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 맵 범위 내에 있고, 방문하지 않은 땅이면서 갈 수 있는 땅인 경우
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && map[nx][ny] == 1) {
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    
    map.resize(n, vector<int>(m));
    dist.resize(n, vector<int>(m, -1)); // 모든 칸을 -1로 초기화
    visited.resize(n, vector<bool>(m, false));
    
    int startX = -1, startY = -1;
    
    // 지도 정보 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            
            if (map[i][j] == 2) {
                startX = i;
                startY = j;
            }
            
            if (map[i][j] == 0) {
                dist[i][j] = 0; // 원래부터 갈 수 없는 땅은 0으로 표시
            }
        }
    }
    
    // 시작점에서 BFS 실행
    bfs(startX, startY);
    
    // 결과 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}
