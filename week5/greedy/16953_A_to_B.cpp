#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B;
    cin >> A >> B;
    
    // 그리디 접근: B에서 A로 거꾸로 연산 (B가 2로 나누어 떨어지거나 끝자리가 1인 경우)
    int count = 1; // 연산 횟수 (처음 A도 카운트)
    
    while (B > A) {
        if (B % 2 == 0) {
            // B가 2로 나누어 떨어지는 경우: 2로 나눔
            B /= 2;
        } else if (B % 10 == 1) {
            // B의 끝자리가 1인 경우: 끝자리 1 제거
            B /= 10;
        } else {
            // 두 연산으로 A에서 B를 만들 수 없는 경우
            count = -1;
            break;
        }
        count++;
    }
    
    // B가 A보다 작아진 경우 (더 이상 연산으로 A를 만들 수 없음)
    if (B < A) {
        count = -1;
    }
    
    cout << count << endl;
    
    return 0;
}
