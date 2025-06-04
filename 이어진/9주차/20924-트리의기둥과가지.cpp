#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 백준 20924 - 트리의 기둥과 가지
* 
* 문제 발상:
* 1. 트리에서 기둥(trunk)과 가지(branch)의 개념을 정의하고 각각의 길이를 구하는 문제
* 2. 기둥: 루트에서 시작하여 차수가 2 이하인 경로 (일직선 경로)
* 3. 가지: 기둥이 끝나는 지점에서 리프까지의 경로 중 가장 긴 경로
* 4. 기가 노드(Giga Node): 기둥이 끝나는 지점
*    - 루트가 리프인 경우: 루트가 기가 노드
*    - 루트의 차수가 3 이상인 경우: 루트가 기가 노드
*    - 그 외: 루트에서 시작하여 차수가 3 이상인 첫 번째 노드가 기가 노드
* 5. 알고리즘:
*    - 기가 노드를 찾기 위해 루트에서 DFS 탐색
*    - 기가 노드에서 모든 가지의 길이를 계산하여 최댓값 구함
*/

vector<vector<pair<int, int>>> tree;  // 인접 리스트 (노드, 가중치)
vector<bool> visited;
int giga_node = -1;
int trunk_length = 0;

// 기가 노드를 찾는 DFS
void find_giga_node(int node, int current_length) {
    visited[node] = true;
    
    // 현재 노드의 차수 계산 (방문하지 않은 인접 노드 개수)
    int unvisited_neighbors = 0;
    for (auto& edge : tree[node]) {
        if (!visited[edge.first]) {
            unvisited_neighbors++;
        }
    }
    
    // 기가 노드 조건 확인
    if (unvisited_neighbors == 0 || unvisited_neighbors >= 2) {
        giga_node = node;
        trunk_length = current_length;
        return;
    }
    
    // 차수가 1인 경우 계속 진행
    for (auto& edge : tree[node]) {
        if (!visited[edge.first]) {
            find_giga_node(edge.first, current_length + edge.second);
            break;  // 차수가 1이므로 방문하지 않은 노드는 하나뿐
        }
    }
}

// 기가 노드에서 가장 긴 가지 길이를 구하는 DFS
int find_longest_branch(int node, int parent) {
    int max_length = 0;
    
    for (auto& edge : tree[node]) {
        int next = edge.first;
        int weight = edge.second;
        
        if (next != parent) {
            int branch_length = weight + find_longest_branch(next, node);
            max_length = max(max_length, branch_length);
        }
    }
    
    return max_length;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, R;
    cin >> N >> R;
    
    tree.resize(N + 1);
    visited.resize(N + 1, false);
    
    // 트리 간선 정보 입력
    for (int i = 0; i < N - 1; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        tree[u].push_back({v, d});
        tree[v].push_back({u, d});
    }
    
    // 특별한 경우: 노드가 1개인 경우
    if (N == 1) {
        cout << "0 0" << '\n';
        return 0;
    }
    
    // 기가 노드 찾기
    find_giga_node(R, 0);
    
    // 가장 긴 가지 길이 계산
    int branch_length = 0;
    if (giga_node != -1) {
        branch_length = find_longest_branch(giga_node, -1);
    }
    
    // 결과 출력
    cout << trunk_length << " " << branch_length << '\n';
    
    return 0;
}
