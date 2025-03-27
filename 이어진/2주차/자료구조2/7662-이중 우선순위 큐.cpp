#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        multiset<int> s;
        for (int i = 0; i < k; ++i) {
            char command;
            int value;
            cin >> command >> value;
            if (command == 'I') {
                s.insert(value);
            } else if (command == 'D') {
                if (!s.empty()) {
                    if (value == 1) {
                        s.erase(--s.end());
                    } else if (value == -1) {
                        s.erase(s.begin());
                    }
                }
            }
        }
        if (s.empty()) {
            cout << "EMPTY" << endl;
        } else {
            cout << *(--s.end()) << " " << *s.begin() << endl;
        }
    }
    return 0;
}