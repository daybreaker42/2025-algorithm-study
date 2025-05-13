#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> meetings(n);
    for (auto &[s, e] : meetings) cin >> s >> e;

    sort(meetings.begin(), meetings.end(), [](auto a, auto b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    int cnt = 0, end = 0;
    for (auto [s, e] : meetings) {
        if (s >= end) {
            end = e;
            cnt++;
        }
    }

    cout << cnt << '\n';
}
