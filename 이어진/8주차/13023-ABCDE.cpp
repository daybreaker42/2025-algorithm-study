#include <iostream>
#include <vector>
using namespace std;

/*
* 백준 13023 - ABCDE
* 
* 문제 발상:
* 1. A-B-C-D-E와 같이 5명이 연속적으로 친구인 관계가 존재하는지 확인하는 문제
* 2. 그래프에서 깊이가 4인 경로가 존재하는지 확인하는 문제와 동일
* 3. DFS를 이용하여 각 정점에서 시작해 깊이 4까지 탐색
* 4. 깊이 4에 도달할 수 있으면 조건을 만족하는 관계가 존재
* 5. N과 M이 작기 때문에 모든 정점에서 DFS를 시작해보는 완전 탐색 가능
*/

int N, M;
vector<vector<int>> graph;
vector<bool> visited;
bool found = false;

// DFS 함수: 현재 정점과 깊이를 매개변수로 받음
void dfs(int node, int depth) {
    // 깊이가 4에 도달하면 조건 만족
    if (depth == 4) {
        found = true;
        return;
    }
    
    visited[node] = true;
    
    // 인접한 모든 정점 탐색
    for (int next : graph[node]) {
        if (!visited[next]) {
            dfs(next, depth + 1);
            if (found) return; // 이미 조건을 만족하면 더 탐색할 필요 없음
        }
    }
    
    // 백트래킹: 다른 경로에서 해당 정점을 방문할 수 있도록 방문 표시 해제
    visited[node] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    
    graph.resize(N);
    visited.resize(N, false);
    
    // 친구 관계 입력
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // 양방향 그래프
    }
    
    // 모든 정점에서 DFS 시작
    for (int i = 0; i < N; i++) {
        if (found) break;
        dfs(i, 0);
    }
    
    // 결과 출력
    cout << (found ? 1 : 0) << '\n';
    
    return 0;
}
