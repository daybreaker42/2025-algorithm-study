#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> circles(n);
    for (int i = 0; i < n; ++i) {
        cin >> circles[i].first >> circles[i].second;
    }

    int start, end;
    cin >> start >> end;

    // 그래프 인접 리스트 생성 (원들의 교차 여부)
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int distSq = (circles[i].first - circles[j].first) * (circles[i].first - circles[j].first) +
                         (circles[i].second - circles[j].second) * (circles[i].second - circles[j].second);
            if (distSq <= 4) { // 반지름이 1이므로, 거리가 2 이하면 인접
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    // BFS를 사용하여 start에서 end까지의 최단 경로 탐색
    queue<int> q;
    vector<int> dist(n, -1);
    q.push(start - 1);
    dist[start - 1] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    cout << (dist[end - 1] != -1 ? dist[end - 1] : -1) << endl;

    return 0;
}
