#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
* 백준 13549 - 숨바꼭질 3
* 
* 문제 발상:
* 1. 수빈이가 동생을 찾아가는 최단 시간을 구하는 문제
* 2. 수빈이는 X-1, X+1 위치로 1초에 이동하거나, 2*X 위치로 0초에 이동 가능
* 3. 일반 BFS로는 최단 시간을 보장할 수 없음 (가중치가 0인 간선이 존재하므로)
* 4. 0-1 BFS 또는 다익스트라 알고리즘으로 해결 필요
* 5. 0-1 BFS: 가중치가 0인 간선으로 이동한 정점은 큐의 앞에, 가중치가 1인 간선으로 이동한 정점은 큐의 뒤에 추가
* 6. 다익스트라: 우선순위 큐를 사용해 현재까지의 최단 시간이 가장 짧은 위치부터 탐색
*/

const int MAX = 100001; // 최대 위치

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    
    // 다익스트라 알고리즘 사용
    vector<int> dist(MAX, 1e9); // 각 위치까지의 최단 시간
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[N] = 0; // 시작 위치
    pq.push({0, N}); // {시간, 위치}
    
    while (!pq.empty()) {
        int time = pq.top().first;
        int pos = pq.top().second;
        pq.pop();
        
        // 현재 위치가 이미 더 짧은 시간으로 방문된 경우 스킵
        if (dist[pos] < time) continue;
        
        // 동생 위치에 도착한 경우
        if (pos == K) {
            cout << time << '\n';
            break;
        }
        
        // 1. 순간이동 (2*X로 0초에 이동)
        if (pos * 2 < MAX && dist[pos * 2] > time) {
            dist[pos * 2] = time;
            pq.push({time, pos * 2});
        }
        
        // 2. 걷기 (X-1로 1초에 이동)
        if (pos - 1 >= 0 && dist[pos - 1] > time + 1) {
            dist[pos - 1] = time + 1;
            pq.push({time + 1, pos - 1});
        }
        
        // 3. 걷기 (X+1로 1초에 이동)
        if (pos + 1 < MAX && dist[pos + 1] > time + 1) {
            dist[pos + 1] = time + 1;
            pq.push({time + 1, pos + 1});
        }
    }
    
    return 0;
}

/* 
* 0-1 BFS를 이용한 풀이도 가능합니다:
* 
* int main() {
*     ios_base::sync_with_stdio(false);
*     cin.tie(nullptr);
*     
*     int N, K;
*     cin >> N >> K;
*     
*     vector<int> dist(MAX, -1); // 각 위치까지의 최단 시간
*     deque<int> dq; // 덱 사용
*     
*     dist[N] = 0;
*     dq.push_back(N);
*     
*     while (!dq.empty()) {
*         int pos = dq.front();
*         dq.pop_front();
*         
*         if (pos == K) {
*             cout << dist[pos] << '\n';
*             break;
*         }
*         
*         // 1. 순간이동 (가중치 0)
*         if (pos * 2 < MAX && dist[pos * 2] == -1) {
*             dist[pos * 2] = dist[pos];
*             dq.push_front(pos * 2); // 가중치 0은 덱의 앞에 추가
*         }
*         
*         // 2. 걷기 (가중치 1)
*         if (pos - 1 >= 0 && dist[pos - 1] == -1) {
*             dist[pos - 1] = dist[pos] + 1;
*             dq.push_back(pos - 1); // 가중치 1은 덱의 뒤에 추가
*         }
*         
*         // 3. 걷기 (가중치 1)
*         if (pos + 1 < MAX && dist[pos + 1] == -1) {
*             dist[pos + 1] = dist[pos] + 1;
*             dq.push_back(pos + 1); // 가중치 1은 덱의 뒤에 추가
*         }
*     }
*     
*     return 0;
* }
*/
