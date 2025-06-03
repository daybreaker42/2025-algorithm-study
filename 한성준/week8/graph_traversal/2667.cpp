#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<int> counts;

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '1' && !visited[i][j]) {
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                int count = 1;

                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; ++k) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == '1' && !visited[nx][ny]) {
                            q.push({nx, ny});
                            visited[nx][ny] = true;
                            count++;
                        }
                    }
                }
                counts.push_back(count);
            }
        }
    }

    sort(counts.begin(), counts.end());

    cout << counts.size() << endl;
    for (int count : counts) {
        cout << count << endl;
    }

    return 0;
}
