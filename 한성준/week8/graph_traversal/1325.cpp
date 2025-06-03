#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a); // b가 a를 신뢰한다.
    }

    int max_count = 0;
    vector<int> result;

    for (int i = 1; i <= n; ++i) {
        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(i);
        visited[i] = true;

        int count = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            count++;

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        if (count > max_count) {
            max_count = count;
            result.clear();
            result.push_back(i);
        } else if (count == max_count) {
            result.push_back(i);
        }
    }

    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
