#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
* 백준 11725 - 트리의 부모 찾기
* 
* 문제 발상:
* 1. 루트가 1인 트리에서 각 노드의 부모를 찾는 문제
* 2. 트리는 무방향 그래프로 주어지므로 DFS나 BFS를 통해 부모-자식 관계를 설정
* 3. 루트(1번 노드)에서 시작하여 BFS/DFS로 탐색하면서 각 노드의 부모를 기록
* 4. 방문하지 않은 인접 노드는 현재 노드의 자식이 되고, 현재 노드는 그 노드의 부모가 됨
* 5. BFS를 사용하면 레벨 순서로 탐색하여 직관적으로 이해하기 쉬움
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<vector<int>> tree(N + 1);  // 트리의 인접 리스트
    vector<int> parent(N + 1, 0);     // 각 노드의 부모 저장
    vector<bool> visited(N + 1, false);  // 방문 체크
    
    // 트리의 간선 정보 입력
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);  // 무방향 그래프
    }
    
    // BFS로 루트(1)에서 시작하여 각 노드의 부모 찾기
    queue<int> q;
    q.push(1);  // 루트 노드부터 시작
    visited[1] = true;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        // 현재 노드의 모든 인접 노드 확인
        for (int next : tree[current]) {
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = current;  // current가 next의 부모
                q.push(next);
            }
        }
    }
    
    // 2번 노드부터 N번 노드까지의 부모 출력
    for (int i = 2; i <= N; i++) {
        cout << parent[i] << '\n';
    }
    
    return 0;
}
