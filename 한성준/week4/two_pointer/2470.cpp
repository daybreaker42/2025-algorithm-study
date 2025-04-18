#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<int> solutions(N);
    for (int i = 0; i < N; i++) {
        cin >> solutions[i];
    }
    
    // 용액 특성값 정렬
    sort(solutions.begin(), solutions.end());
    
    int left = 0;
    int right = N - 1;
    int minSum = 2e9;  // 충분히 큰 값으로 초기화
    int solution1 = 0, solution2 = 0;  // 결과로 출력할 두 용액
    
    // 투 포인터로 탐색
    while (left < right) {
        int sum = solutions[left] + solutions[right];
        
        // 특성값 합의 절댓값이 더 작으면 갱신
        if (abs(sum) < minSum) {
            minSum = abs(sum);
            solution1 = solutions[left];
            solution2 = solutions[right];
        }
        
        // 합이 0보다 작으면 왼쪽 포인터 증가
        if (sum < 0) {
            left++;
        } 
        // 합이 0보다 크면 오른쪽 포인터 감소
        else {
            right--;
        }
    }
    
    cout << solution1 << " " << solution2 << '\n';
    
    return 0;
}
