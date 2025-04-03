#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

bool is_perfect_square(long long n) {
    if (n < 0) return false;
    if (n == 0) return true;
    long long root = round(sqrt(n));
    return root * root == n;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    long long max_square = -1;
    int dr[] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dc[] = {1, -1, 0, 0, 1, -1, 1, -1};

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            for (int i = 0; i < 8; ++i) {
                long long current_number = 0;
                int current_r = r;
                int current_c = c;
                while (current_r >= 0 && current_r < n && current_c >= 0 && current_c < m) {
                    current_number = current_number * 10 + (grid[current_r][current_c] - '0');
                    if (is_perfect_square(current_number)) {
                        if (current_number > max_square) {
                            max_square = current_number;
                        }
                    }
                    current_r += dr[i];
                    current_c += dc[i];
                }
            }
            int digit = grid[r][c] - '0';
            if (is_perfect_square(digit)) {
                if (digit > max_square) {
                    max_square = digit;
                }
            }
        }
    }

    cout << max_square << endl;

    return 0;
}