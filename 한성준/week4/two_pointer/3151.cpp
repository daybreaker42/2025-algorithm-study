#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<int> skills(N);
    for (int i = 0; i < N; i++) {
        cin >> skills[i];
    }
    
    // 코딩 실력 정렬
    sort(skills.begin(), skills.end());
    
    long long count = 0;  // 경우의 수
    
    // 첫 번째 학생 선택
    for (int i = 0; i < N - 2; i++) {
        // 두 번째, 세 번째 학생을 투 포인터로 선택
        for (int j = i + 1; j < N - 1; j++) {
            int target = -(skills[i] + skills[j]);  // 합이 0이 되기 위한 목표값
            
            // target과 같은 값을 이진 탐색으로 찾기
            // 중복 원소가 있을 수 있으므로 upper_bound와 lower_bound 사용
            int low = lower_bound(skills.begin() + j + 1, skills.end(), target) - skills.begin();
            int high = upper_bound(skills.begin() + j + 1, skills.end(), target) - skills.begin();
            
            count += (high - low);  // 찾은 원소의 개수만큼 경우의 수 증가
        }
    }
    
    cout << count << '\n';
    
    return 0;
}
