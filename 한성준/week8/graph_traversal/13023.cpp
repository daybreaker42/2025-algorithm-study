#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> visited;

bool dfs(int u, int depth) {
    visited[u] = true;

    if (depth == 5) {
        return true;
    }

    for (int v : adj[u]) {
        if (!visited[v]) {
            if (dfs(v, depth + 1)) {
                return true;
            }
        }
    }

    visited[u] = false; // 백트래킹
    return false;
}

int main() {
    cin >> n >> m;

    adj.resize(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; ++i) {
        visited.assign(n, false);
        if (dfs(i, 1)) {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;

    return 0;
}
