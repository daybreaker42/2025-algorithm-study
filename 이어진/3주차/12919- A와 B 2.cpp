#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool can_reach(string current_T, const string& S, unordered_set<string>& visited) {
    if (current_T == S) {
        return true;
    }
    if (current_T.length() < S.length()) {
        return false;
    }
    if (visited.count(current_T)) {
        return false;
    }
    visited.insert(current_T);

    bool possible = false;

    if (current_T.length() > S.length() && current_T.back() == 'A') {
        string next_T1 = current_T.substr(0, current_T.length() - 1);
        if (can_reach(next_T1, S, visited)) {
            return true;
        }
    }

    if (current_T.length() > S.length() && current_T.front() == 'B') {
        string temp_T = current_T.substr(1);
        string next_T2 = temp_T;
        reverse(next_T2.begin(), next_T2.end());
        if (can_reach(next_T2, S, visited)) {
            return true;
        }
    }

    return false;
}

int main() {
    string s, t;
    cin >> s >> t;

    unordered_set<string> visited;
    if (can_reach(t, s, visited)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
