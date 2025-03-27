#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<pair<int, int>> max_heap;
    set<pair<int, int>> min_heap;
    map<int, int> problem_difficulty;
    for (int i = 0; i < n; ++i) {
        int p, l;
        cin >> p >> l;
        max_heap.insert({-l, p});
        min_heap.insert({l, p});
        problem_difficulty[p] = l;
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string operation;
        cin >> operation;
        if (operation == "add") {
            int p, l;
            cin >> p >> l;
            max_heap.insert({-l, p});
            min_heap.insert({l, p});
            problem_difficulty[p] = l;
        } else if (operation == "recommend") {
            int x;
            cin >> x;
            if (x == 1) {
                cout << max_heap.begin()->second << endl;
            } else if (x == -1) {
                cout << min_heap.begin()->second << endl;
            }
        } else if (operation == "solved") {
            int p;
            cin >> p;
            int l = problem_difficulty[p];
            max_heap.erase({-l, p});
            min_heap.erase({l, p});
            problem_difficulty.erase(p);
        }
    }

    return 0;
}