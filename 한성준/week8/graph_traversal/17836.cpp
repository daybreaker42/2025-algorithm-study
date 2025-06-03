#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m, t;
    cin >> n >> m >> t;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    bool has_gram = false;
    int gram_x, gram_y;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (grid[x][y] == 2) {
            has_gram = true;
            gram_x = x;
            gram_y = y;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == -1) {
                if (grid[nx][ny] == 0 || grid[nx][ny] == 2) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                } else if (has_gram) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    int ans = dist[n - 1][m - 1];

    if (ans == -1) {
        cout << "Fail" << endl;
    } else {
        if(ans) cout << ans << endl;
        else cout << "Fail" << endl;
    }

    return 0;
}
