#include <iostream>
#include <stack>
using namespace std;

int main() {
    int cnt = 0;
    int n;
    cin >> n;

    while (n-- > 0) {
        string s;
        stack<char> stk;
        cin >> s;

        for (char chr : s) {
            if (chr == 'A') {
                if (!stk.empty() && stk.top() == 'A') {
                    stk.pop();
                }
                else {
                    stk.push('A');
                }
            }
            else if (chr == 'B') {
                if (!stk.empty() && stk.top() == 'B') {
                    stk.pop();
                }
                else {
                    stk.push('B');
                }
            }
        }
        if (stk.empty()) cnt++;
    }
    cout << cnt << endl;
}
