#include <iostream>
#include <string>
using namespace std;

string maxVal(string s) {
    string res = "";
    int mCnt = 0;
    for (char c : s) {
        if (c == 'M') mCnt++;
        else {
            res += '5';
            res.append(mCnt, '0');
            mCnt = 0;
        }
    }
    if (mCnt) res.append(mCnt, '1');
    return res;
}

string minVal(string s) {
    string res = "";
    int mCnt = 0;
    for (char c : s) {
        if (c == 'M') mCnt++;
        else {
            if (mCnt) {
                res += '1';
                res.append(mCnt - 1, '0');
                mCnt = 0;
            }
            res += '5';
        }
    }
    if (mCnt) {
        res += '1';
        res.append(mCnt - 1, '0');
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    cout << maxVal(s) << '\n' << minVal(s) << '\n';
}
