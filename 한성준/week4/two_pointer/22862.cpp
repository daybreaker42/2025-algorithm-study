#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    
    vector<int> sequence(N);
    for (int i = 0; i < N; i++) {
        cin >> sequence[i];
    }
    
    int left = 0, right = 0;
    int oddCount = 0;  // 현재 범위 내 홀수 개수
    int maxLength = 0;  // 최대 짝수 연속 부분 수열 길이
    
    while (right < N) {
        // 현재 숫자가 홀수인 경우
        if (sequence[right] % 2 == 1) {
            oddCount++;
        }
        
        // 홀수 개수가 K를 초과하는 경우, 왼쪽 포인터 이동
        while (oddCount > K) {
            if (sequence[left] % 2 == 1) {
                oddCount--;
            }
            left++;
        }
        
        // 현재 구간에서 짝수의 개수 계산 (전체 길이 - 홀수 개수)
        int evenCount = (right - left + 1) - oddCount;
        maxLength = max(maxLength, evenCount);
        
        right++;
    }
    
    cout << maxLength << '\n';
    
    return 0;
}
