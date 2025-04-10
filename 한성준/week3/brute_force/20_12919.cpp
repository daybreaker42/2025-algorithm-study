#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

string S, T;
bool possible = false;

// T에서 S로 변환 가능한지 확인하는 역방향 탐색 함수
void solve(string current) {
    // 기저 조건: S와 동일해지면 변환 가능
    if (current.length() == S.length()) {
        if (current == S) possible = true;
        return;
    }
    
    // 마지막 문자가 'A'인 경우 제거 연산
    if (current.back() == 'A') {
        string next = current;
        next.pop_back();
        solve(next);
    }
    
    // 첫 문자가 'B'인 경우 제거 후 뒤집기 연산
    if (current.front() == 'B') {
        string next = current;
        next.erase(next.begin());
        reverse(next.begin(), next.end());
        solve(next);
    }
}

int main() {
    fastio;
    
    cin >> S >> T;
    
    // T에서 S로 변환 가능한지 역으로 탐색
    solve(T);
    
    cout << (possible ? 1 : 0) << endl;
    
    return 0;
}

/* 
문제 요약: 문자열 S를 T로 변환할 수 있는지 확인하기
- 두 가지 연산만 가능:
  1. 문자열 뒤에 'A' 추가
  2. 문자열 뒤에 'B' 추가 후 문자열 뒤집기
- S에서 시작해서 T를 만들 수 있는지 확인

접근 방법:
1. S→T 방향으로 탐색하면 경우의 수가 많아지므로 T→S 방향으로 역탐색
2. T의 마지막 문자가 'A'면 제거
3. T의 첫 문자가 'B'면 제거 후 뒤집기
4. S와 동일해지면 변환 가능
*/
