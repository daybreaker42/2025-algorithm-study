#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

long long getDEC(string s, int n) {
    long long res = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            res = res * n + (s[i] - '0');
        }
        else if (s[i] >= 'a' && s[i] <= 'z') {
            res = res * n + (s[i] - 'a' + 10);
        }
    }
    return res;
}

int getMax(string s) {
    char max = '0';
    for (int i = 0; i < s.length(); i++) {
        if (s[i] > max) max = s[i];
    }
    if (max >= '0' && max <= '9') return(max - '0') + 1;
    else if (max >= 'a' && max <= 'z') return(max - 'a' + 10) + 1;
    return 0;
}

int main() {
    string a, b;
    cin >> a >> b;

    set<long long> values;
    int cnt = 0, A = -1, B = -1;
    long long X = -1;

    for (int i = getMax(a); i <= 36; i++) {
        long long dec_a = getDEC(a, i);
        for (int j = getMax(b); j <= 36; j++) {
            if (i == j) continue;
            long long dec_b = getDEC(b, j);

            if (dec_a == dec_b) {
                if (values.find(dec_a) != values.end()) {
                    cout << "Multiple" << endl;
                    return 0;
                }
                values.insert(dec_a);
                A = i;
                B = j;
                X = dec_a;
                cnt++;
            }
        }
    }

    if (cnt == 0) {
        cout << "Impossible" << endl;
    }
    else if (cnt == 1) {
        cout << X << " " << A << " " << B << endl;
    }
    else {
        cout << "Multiple" << endl;
    }

    return 0;
}