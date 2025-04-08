#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n;
vector<vector<int>> cost;
int min_total_cost = -1;

set<pair<int, int>> get_flower_cells(int r, int c) {
    set<pair<int, int>> cells;
    cells.insert({r, c});
    cells.insert({r - 1, c});
    cells.insert({r + 1, c});
    cells.insert({r, c - 1});
    cells.insert({r, c + 1});
    return cells;
}

int get_flower_cost(int r, int c) {
    if (r < 1 || r >= n - 1 || c < 1 || c >= n - 1) {
        return 0;
    }
    return cost[r][c] + cost[r - 1][c] + cost[r + 1][c] + cost[r][c - 1] + cost[r][c + 1];
}

void solve(int flowers_planted, int current_cost, set<pair<int, int>>& occupied, int last_r, int last_c) {
    if (flowers_planted == 3) {
        if (min_total_cost == -1 || current_cost < min_total_cost) {
            min_total_cost = current_cost;
        }
        return;
    }

    for (int r = 1; r < n - 1; ++r) {
        for (int c = 1; c < n - 1; ++c) {
            if (r < last_r || (r == last_r && c <= last_c)) {
                continue;
            }

            set<pair<int, int>> flower_cells = get_flower_cells(r, c);
            bool can_plant = true;
            for (const auto& cell : flower_cells) {
                if (occupied.count(cell)) {
                    can_plant = false;
                    break;
                }
            }

            if (can_plant) {
                int flower_price = get_flower_cost(r, c);
                set<pair<int, int>> next_occupied = occupied;
                for (const auto& cell : flower_cells) {
                    next_occupied.insert(cell);
                }
                solve(flowers_planted + 1, current_cost + flower_price, next_occupied, r, c);
            }
        }
    }
}

int main() {
    cin >> n;
    cost.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
        }
    }

    set<pair<int, int>> occupied;
    solve(0, 0, occupied, 0, 0);

    cout << min_total_cost << endl;

    return 0;
}