#include <iostream>
#include <vector>

using namespace std;

bool is_valid(int r, int c) {
    return r >= 0 && r < 19 && c >= 0 && c < 19;
}

bool check_five(const vector<vector<int>>& board, int r, int c, int color, int dr, int dc) {
    for (int i = 0; i < 5; ++i) {
        int nr = r + i * dr;
        int nc = c + i * dc;
        if (!is_valid(nr, nc) || board[nr][nc] != color) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<vector<int>> board(19, vector<int>(19));
    for (int i = 0; i < 19; ++i) {
        for (int j = 0; j < 19; ++j) {
            cin >> board[i][j];
        }
    }

    int dr[] = {0, 1, 1, 1};
    int dc[] = {1, 0, 1, -1};

    for (int r = 0; r < 19; ++r) {
        for (int c = 0; c < 19; ++c) {
            int color = board[r][c];
            if (color == 1 || color == 2) {
                for (int i = 0; i < 4; ++i) {
                    if (check_five(board, r, c, color, dr[i], dc[i])) {
                        if (color == 2) {
                            return 2;
                        } else {
                            int prev_r = r - dr[i];
                            int prev_c = c - dc[i];
                            int next_r = r + 5 * dr[i];
                            int next_c = c + 5 * dc[i];
                            bool prev_is_black = is_valid(prev_r, prev_c) && (board[prev_r][prev_c] == 1);
                            bool next_is_black = is_valid(next_r, next_c) && (board[next_r][next_c] == 1);
                            if (!prev_is_black && !next_is_black) {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
