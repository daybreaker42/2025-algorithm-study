#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

/*
* 백준 1325 - 효율적인 해킹
* 
* 문제 발상:
* 1. 신뢰 관계가 있는 컴퓨터들을 그래프로 표현 (A가 B를 신뢰하면 B→A 방향 간선)
* 2. 한 컴퓨터를 해킹했을 때 해킹할 수 있는 컴퓨터의 총 개수를 찾는 문제
* 3. 각 컴퓨터에서 시작하여 BFS/DFS로 도달 가능한 컴퓨터 수를 세면 됨
* 4. 양방향 그래프가 아닌 단방향 그래프이므로 방향에 주의
* 5. N이 최대 10,000이므로 O(N^2) 알고리즘으로 해결 가능
*/

vector<int> graph[10001]; // 컴퓨터 간 신뢰 관계 그래프 (B가 A를 해킹할 수 있으면 B→A)
bool visited[10001];      // BFS/DFS 방문 체크 배열
int hackCount[10001];     // 각 컴퓨터가 해킹할 수 있는 컴퓨터 수

// BFS로 특정 컴퓨터에서 시작해 해킹 가능한 컴퓨터 수를 세는 함수
int bfs(int start) {
    queue<int> q;
    memset(visited, false, sizeof(visited));
    
    q.push(start);
    visited[start] = true;
    int count = 1; // 자기 자신부터 카운트
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        for (int next : graph[current]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    // 신뢰 관계 입력 (A가 B를 신뢰하면 B→A 방향 간선)
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        graph[B].push_back(A); // B를 해킹하면 A도 해킹 가능
    }
    
    // 각 컴퓨터에서 시작하여 해킹 가능한 컴퓨터 수 계산
    int maxHackCount = 0;
    for (int i = 1; i <= N; i++) {
        hackCount[i] = bfs(i);
        maxHackCount = max(maxHackCount, hackCount[i]);
    }
    
    // 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터 번호 출력
    for (int i = 1; i <= N; i++) {
        if (hackCount[i] == maxHackCount) {
            cout << i << " ";
        }
    }
    cout << '\n';
    
    return 0;
}
