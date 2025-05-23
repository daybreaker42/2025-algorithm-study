#include <iostream>
#include <vector>
#include <queue>

using namespace namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> dist(100001, -1);
    deque<int> q;
    q.push_back(n);
    dist[n] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop_front();

        if (u * 2 <= 100000 && dist[u * 2] == -1) {
            dist[u * 2] = dist[u];
            q.push_front(u * 2);
        }

        if (u - 1 >= 0 && dist[u - 1] == -1) {
            dist[u - 1] = dist[u] + 1;
            q.push_back(u - 1);
        }

        if (u + 1 <= 100000 && dist[u + 1] == -1) {
            dist[u + 1] = dist[u] + 1;
            q.push_back(u + 1);
        }
    }

    cout << dist[k] << endl;

    return 0;
}
