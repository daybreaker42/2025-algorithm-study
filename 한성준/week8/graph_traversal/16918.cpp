#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int r, c, n;
    cin >> r >> c >> n;

    vector<string> grid(r);
    for (int i = 0; i < r; ++i) {
        cin >> grid[i];
    }

    for (int time = 1; time <= n; ++time) {
        if (time % 2 == 0) {
            // 폭탄 설치
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    if (grid[i][j] == '.') {
                        grid[i][j] = 'O';
                    }
                }
            }
        } else if (time > 1 && time % 2 == 1) {
            // 폭탄 폭발
            vector<pair<int, int>> bombs;
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    if (grid[i][j] == 'O') {
                        bombs.push_back({i, j});
                    }
                }
            }

            int dx[] = {0, 0, 1, -1, 0};
            int dy[] = {1, -1, 0, 0, 0};

            for (auto bomb : bombs) {
                int x = bomb.first;
                int y = bomb.second;

                for (int i = 0; i < 5; ++i) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                        grid[nx][ny] = '.';
                    }
                }
            }
        }
    }

    for (int i = 0; i < r; ++i) {
        cout << grid[i] << endl;
    }

    return 0;
}
