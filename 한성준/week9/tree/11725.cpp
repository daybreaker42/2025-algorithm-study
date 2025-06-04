#include <iostream> // 입출력 스트림을 사용하기 위한 헤더 파일
#include <vector>   // 벡터 컨테이너를 사용하기 위한 헤더 파일
#include <queue>    // 큐 컨테이너를 사용하기 위한 헤더 파일

using namespace std; // std 네임스페이스 사용

int main() {
    int n;       // 노드의 개수
    cin >> n;    // 노드의 개수 입력

    vector<vector<int>> adj(n + 1); // 인접 리스트 (1-based indexing)
    vector<int> parents(n + 1, 0);  // 부모 노드 저장 (1-based indexing)
    vector<bool> visited(n + 1, false); // 방문 여부 (1-based indexing)

    // 간선 정보 입력 및 인접 리스트 구성
    for (int i = 0; i < n - 1; ++i) {
        int u, v;    // 간선 (u, v)
        cin >> u >> v; // 간선 정보 입력
        adj[u].push_back(v); // u에 v를 연결
        adj[v].push_back(u); // v에 u를 연결 (무방향 그래프)
    }

    queue<int> q; // BFS를 위한 큐
    q.push(1);    // 루트 노드 1부터 시작
    visited[1] = true; // 루트 노드 방문 처리

    // BFS를 사용하여 각 노드의 부모를 찾음
    while (!q.empty()) {
        int parent = q.front(); // 현재 노드 (부모 노드)
        q.pop();                // 큐에서 제거

        // 현재 노드와 연결된 모든 자식 노드에 대해
        for (int child : adj[parent]) {
            if (!visited[child]) {          // 방문하지 않은 자식 노드인 경우
                visited[child] = true;       // 방문 처리
                parents[child] = parent;     // 부모 노드 설정
                q.push(child);               // 큐에 추가
            }
        }
    }

    // 각 노드의 부모 노드 출력 (2번 노드부터)
    for (int i = 2; i <= n; ++i) {
        cout << parents[i] << endl; // 부모 노드 출력
    }

    return 0; // 프로그램 종료
}
