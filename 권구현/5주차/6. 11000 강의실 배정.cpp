#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> lectures(n);
    for (auto &[s, e] : lectures) cin >> s >> e;

    sort(lectures.begin(), lectures.end());

    priority_queue<int, vector<int>, greater<>> pq;
    for (auto [s, e] : lectures) {
        if (!pq.empty() && pq.top() <= s) pq.pop();
        pq.push(e);
    }

    cout << pq.size() << '\n';
}
