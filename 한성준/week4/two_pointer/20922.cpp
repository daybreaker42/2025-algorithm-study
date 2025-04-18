#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    
    vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    
    // 투 포인터 알고리즘 적용
    int left = 0, right = 0;
    int maxLength = 0;
    unordered_map<int, int> count;  // 숫자별 등장 횟수
    
    while (right < N) {
        // 오른쪽 포인터 이동 (숫자 추가)
        count[numbers[right]]++;
        
        // K개를 초과하는 숫자가 있으면 왼쪽 포인터 이동
        while (count[numbers[right]] > K) {
            count[numbers[left]]--;
            left++;
        }
        
        // 현재 길이 계산 및 최대 길이 갱신
        maxLength = max(maxLength, right - left + 1);
        right++;
    }
    
    cout << maxLength << '\n';
    
    return 0;
}
