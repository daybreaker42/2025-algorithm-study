#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long a, b;
    cin >> a >> b;
    
    // 발상: B에서 A로 역으로 연산을 수행하는 것이 더 효율적
    // 1. B가 짝수면 2로 나눔
    // 2. B의 일의 자리가 1이면 10으로 나누고 1을 제거
    
    int count = 1; // 초기 연산 횟수
    
    while (a < b) {
        // 짝수인 경우 2로 나눔
        if (b % 2 == 0) {
            b /= 2;
        }
        // 1로 끝나는 경우 1 제거 (10으로 나눔)
        else if (b % 10 == 1) {
            b /= 10;
        }
        // 두 연산으로 도달할 수 없는 경우
        else {
            cout << -1 << '\n';
            return 0;
        }
        count++;
    }
    
    // A와 B가 같아졌는지 확인
    if (a == b) {
        cout << count << '\n';
    } else {
        cout << -1 << '\n';
    }
    
    return 0;
}