#include <iostream> // 입출력 스트림을 사용하기 위한 헤더 파일
#include <vector>   // 벡터 컨테이너를 사용하기 위한 헤더 파일

using namespace std; // std 네임스페이스 사용

int n, r;                         // n은 노드의 개수, r은 루트 노드
vector<vector<pair<int, int>>> adj; // 인접 리스트: (노드, 가중치) 쌍 저장
int pillar = 0;                     // 기둥의 길이
int branch = 0;                     // 가지의 길이

// 기둥을 찾는 DFS 함수
void dfs_pillar(int node, int parent, int weightSum) {
    int count = 0; // 자식 노드의 개수
    // 현재 노드의 자식 노드 개수 확인
    for (auto& edge : adj[node]) {
        int nextNode = edge.first; // 다음 노드
        int weight = edge.second;  // 가중치
        if (nextNode != parent) {   // 부모 노드가 아닌 경우
            count++; // 자식 노드 개수 증가
        }
    }

    // 기둥의 끝에 도달한 경우
    if (count > 1 || (node == r && count > 0)) {
        pillar = weightSum;     // 기둥의 길이 저장
        dfs_branch(node, 0, 0); // 가지 탐색 시작
        return;                 // 함수 종료
    }

    // 다음 노드 탐색
    for (auto& edge : adj[node]) {
        int nextNode = edge.first; // 다음 노드
        int weight = edge.second;  // 가중치
        if (nextNode != parent) {   // 부모 노드가 아닌 경우
            dfs_pillar(nextNode, node, weightSum + weight); // 다음 노드 탐색
        }
    }
}

// 가지를 찾는 DFS 함수
void dfs_branch(int node, int parent, int weightSum) {
    bool isLeaf = true; // 리프 노드 여부
    // 현재 노드의 자식 노드 탐색
    for (auto& edge : adj[node]) {
        int nextNode = edge.first; // 다음 노드
        int weight = edge.second;  // 가중치
        if (nextNode != parent) {   // 부모 노드가 아닌 경우
            isLeaf = false;         // 리프 노드가 아님
            dfs_branch(nextNode, node, weightSum + weight); // 다음 노드 탐색
        }
    }

    // 리프 노드인 경우
    if (isLeaf) {
        branch = max(branch, weightSum); // 가지의 길이 갱신
    }
}

int main() {
    cin >> n >> r; // 노드의 개수와 루트 노드 입력

    adj.resize(n + 1); // 인접 리스트 크기 설정
    // 간선 정보 입력
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;    // 노드 u, v, 가중치 w
        cin >> u >> v >> w; // 노드 정보 입력
        adj[u].push_back({v, w}); // 인접 리스트에 추가
        adj[v].push_back({u, w}); // 인접 리스트에 추가
    }

    dfs_pillar(r, 0, 0); // 기둥 탐색 시작

    cout << pillar << " " << branch << endl; // 기둥과 가지의 길이 출력

    return 0; // 프로그램 종료
}
