#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, S;
    cin >> N >> S;
    
    vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    
    int left = 0, right = 0;
    int sum = 0;
    int minLength = INT_MAX;  // 최소 길이
    
    while (right < N) {
        // 오른쪽 포인터 이동하여 합 증가
        sum += numbers[right++];
        
        // 합이 S 이상이면 왼쪽 포인터 이동
        while (sum >= S) {
            minLength = min(minLength, right - left);  // 현재 길이 갱신
            sum -= numbers[left++];  // 왼쪽 값 제거
        }
    }
    
    if (minLength == INT_MAX) {
        cout << 0 << '\n';  // 합이 S 이상인 부분합이 없는 경우
    } else {
        cout << minLength << '\n';
    }
    
    return 0;
}
