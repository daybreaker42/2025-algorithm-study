#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool canTransform(string S, string T) {
    // T에서 시작하여 S로 줄여나가는 과정
    while (T.length() > S.length()) {
        char lastChar = T.back();
        T.pop_back();
        
        if (lastChar == 'A') {
            // 마지막 문자가 A이면 단순히 제거
            continue;
        } else if (lastChar == 'B') {
            // 마지막 문자가 B이면 제거하고 뒤집기
            reverse(T.begin(), T.end());
        }
    }
    
    // 최종적으로 S와 T가 같은지 확인
    return S == T;
}

int main() {
    string S, T;
    cin >> S >> T;
    
    if (canTransform(S, T)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    
    return 0;
}
