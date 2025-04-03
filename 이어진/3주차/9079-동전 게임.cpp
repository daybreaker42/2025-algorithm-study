#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <array>

using namespace std;

int get_initial_state(const vector<string>& board) {
    int state = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == 'T') {
                state |= (1 << (3 * i + j));
            }
        }
    }
    return state;
}

int solve() {
    vector<string> board(3);
    for (int i = 0; i < 3; ++i) {
        cin >> board[i];
    }

    int start_state = get_initial_state(board);
    if (start_state == 0 || start_state == 511) {
        return 0;
    }

    queue<int> q;
    q.push(start_state);
    vector<int> distance(512, -1);
    distance[start_state] = 0;

    array<int, 8> masks = {7, 56, 448, 73, 146, 292, 273, 84};

    while (!q.empty()) {
        int current_state = q.front();
        q.pop();

        if (current_state == 0 || current_state == 511) {
            return distance[current_state];
        }

        for (int mask : masks) {
            int next_state = current_state ^ mask;
            if (distance[next_state] == -1) {
                distance[next_state] = distance[current_state] + 1;
                q.push(next_state);
            }
        }
    }

    return -1;
}

int main() {
    cout << solve() << endl;
    return 0;
}