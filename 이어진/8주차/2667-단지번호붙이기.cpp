#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
* 백준 2667 - 단지번호붙이기
* 
* 문제 발상:
* 1. 연결된 집들의 단지를 찾는 전형적인 BFS/DFS 문제
* 2. 각 집(1)에서 시작하여 연결된 모든 집을 방문하며 단지를 형성
* 3. 상하좌우로만 연결된 경우 같은 단지로 인정
* 4. 각 단지의 집 수를 오름차순으로 정렬하여 출력
* 5. DFS 또는 BFS로 단지를 탐색하고 집의 수를 세는 방식으로 해결
*/

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int N;
vector<vector<char>> map;
vector<vector<bool>> visited;

// BFS로 하나의 단지 내 집의 수를 세는 함수
int bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    int count = 1; // 시작 위치도 포함
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        // 상하좌우 네 방향 탐색
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 맵 범위 내에 있고, 방문하지 않은 집인 경우
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && map[nx][ny] == '1') {
                q.push({nx, ny});
                visited[nx][ny] = true;
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    
    map.resize(N, vector<char>(N));
    visited.resize(N, vector<bool>(N, false));
    
    // 지도 정보 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    
    vector<int> house_counts; // 각 단지별 집의 수
    
    // 전체 지도를 탐색하며 단지 찾기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == '1' && !visited[i][j]) {
                // 새로운 단지 발견 및 BFS 실행
                int house_count = bfs(i, j);
                house_counts.push_back(house_count);
            }
        }
    }
    
    // 단지별 집의 수 오름차순 정렬
    sort(house_counts.begin(), house_counts.end());
    
    // 결과 출력
    cout << house_counts.size() << '\n'; // 단지의 총 개수
    for (int count : house_counts) {
        cout << count << '\n';
    }
    
    return 0;
}
